#pragma once

#include <vector>
#include <algorithm>

const int k = 30;

// definisco Insertion sort su intervallo [p, r]
template<typename T>
void insertion_sort(std::vector<T>& A, int p, int r)
{
    for (int j = p + 1; j <= r; ++j) {
        T key = A[j];
        int i = j;

        while (i > p && A[i - 1] > key) {
            A[i] = A[i - 1];
            --i;
        }
        A[i] = key;
    }
}

// partition
template<typename T>
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

// quicksort
template<typename T>
void quicksort(std::vector<T>& A, int p, int r)
{
    if (r - p + 1 <= k) {
        insertion_sort(A, p, r);
        return;
    }

    if (p < r) {
		int q = partition(A, p, r);
		
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}