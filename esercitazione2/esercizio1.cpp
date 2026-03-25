#include <iostream> 

int main() 
{ 
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1;
	float y = 1.1;
	
	(&y)[1] = 0;

	std::cout << x << "\n";
	// con il comando (&y)[1] = 0 si sta chiedendo di accedere alla posizione successiva in memoria (y + sizeof(float)) come se y fosse un array di float, 
	// ma essendo y una singola variabile float, il puntatore esce fuori dai limiti: in questo caso la memoria oltre y coincide con x, per cui x è sovrascritta con 0
	
	// nel mio caso specifo: &y = 0x7ffce5d5dbfc ==> (&y)[1] = 0x7ffce5d5dc00 (che coincide con x)
	
	// indirizzi delle variabili da consegnare
	std::cout << &x << "\n";
	std::cout << &y << "\n";
	
	// indirizzi degli array da stampare SOLO per la rappresentazione grafica (poi commento)
	
	/*	std::cout << &ad[0] << "\n";
		std::cout << &af[0] << "\n";
		std::cout << &ai[0] << "\n";	*/
	
	return 0;
}