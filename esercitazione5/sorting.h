#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

/* QUICKSORT */

// 1. Partition
template <typename T>
int partition(std::vector<T>& A, int p, int r) {
	T x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
	
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

// 2. Quicksort //
template <typename T>
void quicksort(std::vector<T>& A, int p, int r) {
    if (p < r) {
		int q = partition(A, p, r);
		
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}




/* MERGESORT */

// 1. Merge
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + 1 + j];
	}
	
	int i = 0;
	int j = 0;
	
	for (int k = p; k <= r; k++) {
		if (i < n1 && (j >= n2 || L[i] <= R[j])) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

// 2. Mergesort
template <typename T>
void mergesort(std::vector<T>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		
		mergesort(A, p, q);
		mergesort(A, q + 1, r);
		
		merge(A, p, q, r);
	}
}