#pragma once

#include <queue>
#include <stack>

/* contenitore con politica FIFO: */
template <typename T>
class fifo {
	std::queue<T> q;

public:
	// costruttore di default:
	fifo() = default;
	
	// metodo put() per inserire un elemento nel contenitore
	void put(const T& elemento) {
		q.push(elemento);
	}
	
	// metodo get() per rimuovere un elemento dal contenitore
	T get() {
		T elemento = q.front();
		q.pop();
		return elemento;
	}		
	
	// metodo empty() per controllare se il contenitore è vuoto
	bool empty() const {
		return q.empty();
	}
};


/* contenitore con politica LIFO: */
template <typename T>
class lifo {
	std::stack<T> s;

public:
	// costruttore di default:
	lifo() = default;
	
	// metodo put() per inserire un elemento nel contenitore
	void put(const T& elemento) {
		s.push(elemento);
	}
	
	// metodo get() per rimuovere un elemento dal contenitore
	T get() {
		T elemento = s.top();
		s.pop();
		return elemento;
	}	
	
	// metodo empty() per controllare se il contenitore è vuoto
	bool empty() const {
		return s.empty();
	}
};