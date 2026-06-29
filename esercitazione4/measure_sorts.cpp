#include <iostream>
#include <vector>
#include <algorithm>

#include "sorting.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {
	randfiller rf;
	timecounter tc;
	
	for (size_t size = 4; size <= 8192; size *= 2) {
		
		std::cout << "Testing size " << size << "\n";
		
		std::vector<int> v;
		v.resize(size);
		
		/* creo un vettore unico con valori casuali compresi tra -1000 e 1000 */
		rf.fill(v, -1000, 1000);
		
		double time_bubblesort;
		double time_insertionsort;
		double time_selectionsort;
		double time_stdsort;
		
		/* BUBBLE SORT */
		std::vector<int> vb = v;
		tc.tic();
		bubble_sort(vb);
		time_bubblesort = tc.toc();
		
		/*INSERTION SORT*/
		std::vector<int> vi = v;
		tc.tic();
		insertion_sort(vi);
		time_insertionsort = tc.toc();
		
		/*SELECTION SORT*/
		std::vector<int> vs = v;
		tc.tic();
		selection_sort(vs);
		time_selectionsort = tc.toc();
		
		/*std::sort*/
		std::vector<int> vstd = v;
		tc.tic();
		std::sort(vstd.begin(), vstd.end());
		time_stdsort = tc.toc();
	
		std::cout << "Size " << size << "\n"
				  << "Tempo Bubble Sort " << time_bubblesort << "\n"
				  << "Tempo Insertion Sort " << time_insertionsort << "\n"
				  << "Tempo Selection Sort " << time_selectionsort << "\n"
				  << "Tempo std::sort " << time_stdsort << "\n";
	}
			  
	return 0;
}