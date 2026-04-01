#pragma once

#include <iostream>
#include <concepts>
#include <numeric>		// serve per utilizzare gcd, utile per calcolare il MCD

template<typename I> 
requires std::integral<I>
class rational {
	I num_;
	I den_;

public:
	/* costruttore di default */
	rational()
		: num_(I{0}), den_(I{1})
	{}
	
	/* costruttore user-defined */
	rational(const I& num, const I& den)
		: num_(num), den_(den)
	{
		if (den_ == 0)
			// num_ == 0 --> NaN;
			// num_ != 0 --> Inf
			return;
		
		// in tutti gli altri casi
		semplifica();
	}		
	
	/* semplifico eventuali frazioni divisibili */
	void semplifica() {
		if (den_ == 0)		// se l'utente inserisce den = 0 il programma non semplifica
			return;
	
		if (num_ == 0) {	// si forza il denominatore a 1, qualunque sia quello inserito dall'utente
			den_ = 1;
			return;
		}
		
		if (den_ < 0) {		// se l'utente inserisce un valore negativo per il denominatore, "lo si porta" al numeratore
			num_ = -num_;
			den_ = -den_;
		}
	
		I mcd = std::gcd(num_, den_);
		num_ /= mcd;
		den_ /= mcd;
	}

	/* restituisce i valori di num e den */
	I num() const { return num_; }
	I den() const { return den_; }
	
	/* operatore += ==> implementazione dell'incremento a/b + c/d = (ad+bc)/ bd */
	rational& operator+=(const rational& other) {
		// caso NaN
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
            num_ = 0;
			den_ = 0;
			return *this;
        }

		// caso Inf
		if (den_ == 0 || other.den_ == 0) {
			// Inf + (-Inf) = NaN
			if (den_ == 0 && other.den_ == 0) {
				num_ = 0;
				den_ = 0;
			}
			// se hanno lo stesso segno --> Inf
			else if (den_ == 0) {
				// resta Inf
			}
			else {
				num_ = other.num_;
				den_ = other.den_;
			}
			return *this;
		}
		
		/* somma classica */
		num_ = num_ * other.den_ + den_ * other.num_;
		den_ = den_ * other.den_;
		semplifica();
		return *this;
	}
	
	/* operatore + classico: ritorna un nuovo rational */
	rational operator+(const rational& other) const {
		rational result = *this;  
		result += other;		// usa l’operatore += già implementato
		return result;
	}
	
	/* operatore -= */
	rational& operator-=(const rational& other) {
		// caso NaN
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
	
		// caso Inf
		if (den_ == 0 || other.den_ == 0) {
			if (den_ == 0 && other.den_ == 0) {
			// Inf - Inf = NaN se di segno uguale
				if ((num_ > 0) == (other.num_ > 0)) {
					num_ = 0;
					den_ = 0;
				}
				// Inf - Inf con segni diversi --> Inf
			}
			else if (den_ == 0) {
				// segni diversi --> Inf
				} 
			else {
				num_ = -other.num_;
				den_ = 0;
			}
			return *this;
		}
		
		// sottrazione classica a/b - c/d = (ad - bc) / bd
		num_ = num_ * other.den_ - den_ * other.num_;
		den_ = den_ *other.den_;
		semplifica();
		return *this;
	}
	
	/* operatore - classico: restituisce un nuovo rational */
	rational operator-(const rational& other) const {
		rational result = *this;
		result -= other;		// usa operator-= già implementato
		return result;
	}

	/* operatore *= */
	rational& operator*=(const rational& other) {
		// caso NaN
        if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
            num_ = 0;
			den_ = 0;
            return *this;
        }
		
		// caso Inf
        if (den_ == 0 || other.den_ == 0) {
			// Inf * 0 = NaN
			if ((num_ == 0 && den_ != 0) || (other.num_ == 0 && other.den_ != 0)) {
            num_ = 0;
			den_ = 0;
			}
			// altrimenti Inf con il segno corretto
			else {
				num_ = (num_ * other.num_ > 0) ? 1 : -1;	// condizione ? valore_true : valore_false
				den_ = 0;
			}
            return *this;
        }
		
		// moltiplicazione classica: (a/b) * (c/d) = (a*c) / (b*d)
        num_ *= other.num_;
        den_ *= other.den_;
        semplifica();
        return *this;
	}
	
	/* operatore * classico: ritorna un nuovo rational */
	rational operator*(const rational& other) const {
		rational result = *this;
		result *= other;
		return result;
	}
	
	/* operatore /= (divisione in-place) */
	rational& operator/=(const rational& other) {
		// caso NaN
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}

		// divisione per Inf → risultato 0
		if (other.den_ == 0 && other.num_ != 0) {
			num_ = 0;
			den_ = 1;
			return *this;
		}

		// divisione per 0 (0/0 è NaN, a/0 è Inf)
		if (other.num_ == 0 && other.den_ != 0) {
			if (num_ == 0) {
				num_ = 0;
				den_ = 0;
			} else {
				num_ = (num_ > 0) ? 1 : -1;
				den_ = 0;
			}
			return *this;
		}

		// divisione classica: (a/b) / (c/d) = (a*d)/(b*c)
		num_ *= other.den_;
		den_ *= other.num_;
		semplifica();
		return *this;
	}
	
	/* operatore / classico: ritorna un nuovo rational */
	rational operator/(const rational& other) const {
		rational result = *this;
		result /= other;
		return result;
	}
};

/* operatore << */
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0)
            return os << "NaN";
        else
            return os << (r.num() > 0 ? "+Inf" : "-Inf");
    }
    return os << r.num() << "/" << r.den();
}