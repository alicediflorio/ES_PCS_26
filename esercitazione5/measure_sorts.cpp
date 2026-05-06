#include <iostream>
#include <vector>
#include <algorithm>				 

#include "randfiller.h"
#include "timecounter.h"
#include "sorting.h"
#include "sorting2.h"


int main(void) {
	
	randfiller rf;
	timecounter tc;

	const int num_campioni = 100;
	
	for (int n = 1; n <= 100; n++) {
				
		std::vector<std::vector<double>> campioni(num_campioni, std::vector<double>(n));
		
		for (size_t k = 0; k < campioni.size(); k++) {
             std::vector<double>& v = campioni[k]; 
             rf.fill(v, -1000.0, 1000.0);
        }
		
		auto vb = campioni;
		auto vi = campioni;
		auto vs = campioni;
		auto vm = campioni;
		auto vq = campioni;
		auto vso = campioni;
		
		// BUBBLE SORT
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     bubble_sort(vb[j]);
		}
		double t_bubble = tc.toc()/num_campioni;
		
		// INSERTION SORT
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     insertion_sort(vi[j]);
	    }
		double t_insertion = tc.toc()/num_campioni;
		
		// SELECTION SORT
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     selection_sort(vs[j]);
		}
		double t_selection = tc.toc()/num_campioni;
		
		// MERGE SORT
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     mergesort(vm[j], 0, n - 1);
		}
		double t_merge = tc.toc()/num_campioni;
		
		// QUICK SORT
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     quicksort(vq[j], 0, n - 1);
		}
		double t_quick = tc.toc()/num_campioni;
		
		// std::sort()
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		std::sort(vso[j].begin(), vso[j].end());
	    }
		double t_sort = tc.toc()/num_campioni;
		
		// stampo i risultati per ogni ciclo for:
		std::cout << "Lunghezza del vettore " << n << "\n";
		std::cout << "Tempo Bubble Sort " << t_bubble << "\n";		
		std::cout << "Tempo Insertion Sort " << t_insertion << "\n";
		std::cout << "Tempo Selection Sort " << t_selection << "\n";
		std::cout << "Tempo Merge Sort " << t_merge << "\n";
		std::cout << "Tempo Quick Sort " << t_quick << "\n";
		std::cout << "Tempo std::sort() " << t_sort << "\n";
		std::cout << " \n";
	}
	
	return 0;
}