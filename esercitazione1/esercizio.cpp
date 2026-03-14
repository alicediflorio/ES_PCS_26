#include <string>
#include <iostream>
#include <fstream>

using namespace std;			// in questo modo evito di specificare std::

int main(int argc, char* argv[]) {
	if (argc <= 1) {			// si devono necessariamente avere 2 parametri (nome del programma + nome del file)
		cerr << "ERRORE: specificare il nome del file come parametro\n";
		return 1;
	}

	ifstream file(argv[1]);
	if ( !file.is_open() ) {		// controllo che il file si apra correttamente
		cerr << "ERRORE: problema nell'apertura del file\n";
		return 1;
	}
	
	// ho già verificato eventuali errori nell'apertura del file, quindi posso procedere
	while ( !file.eof() ) {
		string citta;				// salvo le città nella variabile citta
		double t00, t06, t12, t18;	// temperature di tipo double
		file >> citta >> t00 >> t06 >> t12 >> t18;
		
		double media = (t00 + t06 + t12 + t18) / 4.0;
		cout << citta << " " << media << "\n";
	}
	return 0;
}