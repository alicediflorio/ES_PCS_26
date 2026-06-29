#include <vector>
#include <string>
#include <cstdlib>		// serve per utilizzare EXIT_FAILURE & EXIT_SUCCESS

#include "is_sorted.h"
#include "sorting.h"
#include "randfiller.h"

using namespace std;

int main()
{	/*  */
	randfiller rf;

	/* test su 100 vettori casuali */ 
	for (int k = 0; k < 100; k++) {
		
		/* impongo che la dimensione del vettore sia sempre compresa tra 1 e 200 */
		int size = 1 + rand() % 200;	// rand() % 200 produce numeri tra 0 e 199, a cui poi si aggiunge 1
		
		vector<int> v(size);
		
		/* riempio il vettore di numeri casuali, compresi tra -1000 e 1000 */
		rf.fill(v, -1000, 1000);
		
		bubble_sort(v);
		
		if (!is_sorted(v)) {
			return EXIT_FAILURE;
		}
	}
	
	/* test su stringhe */
	vector<string> vs = {"torino", "milano", "padova", "genova", "firenze", "bologna", "roma", "napoli", "palermo"};
	
	bubble_sort(vs);
	
	if (!is_sorted(vs)) {
		return EXIT_FAILURE;
	}
		
	return EXIT_SUCCESS;
}