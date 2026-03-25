#include <iostream>
#include <cmath>

using namespace std;			// evito di specificare std::

int main()
{
	static const int N = 4;
	double arr[N] = {1.0, 8.0, 15.0, 36.0};
	
	double min = 1.0;
	double max = 36.0;
	
	// calcolo la media dell'array
	double somma = 0.0;
	for (int i = 0; i < N; i++) {
		somma += arr[i];
	}
	double media = somma / N;
	
	// calcolo la deviazione standard --> radice della sommatoria da 1 a N di ((x[i]- media)^2)/n;
	double somma_diff_quad = 0.0;	//
	for (int i = 0; i < N; i++) {
		somma_diff_quad += (arr[i] - media) * (arr[i] - media);
	}
	double deviazione = sqrt(somma_diff_quad / N);

	// stampo i valori richiesti
	cout << "Min:" << min << "\n";
	cout << "Max:" << max << "\n";
	cout << "Media:" << media << "\n";
	cout << "Deviazione standard:" << deviazione << "\n";
	
	return 0;
}