#include <vector>

template <typename T>
bool is_sorted(const std::vector<T>& A) {
	size_t n = A.size();
	
    if (n <= 1) {	// il vettore ha dimensione 0 o 1 ==> è ordinato per definizione
        return true;
    }

    for (size_t i = 1; i < n; ++i) {
        if (A[i] < A[i - 1]) {
            return false;
        }
    }
    return true;
}