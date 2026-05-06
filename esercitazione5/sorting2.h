#include <vector>
#include <algorithm>

/* BUBBLE SORT */
template<typename T>
void bubble_sort(std::vector<T>& A)
{
    size_t n = A.size();
	if (n <= 1)
		return;

    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = n - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}

/* INSERTION SORT */
template<typename T>
void insertion_sort(std::vector<T>& A)
{
	size_t n = A.size();
	if (n <= 1)
		return;
	
    for (size_t j = 1; j < n; ++j) {
        T key = A[j];
        size_t i = j;

        while (i > 0 && A[i - 1] > key) {
            A[i] = A[i - 1];
            --i;
        }
        A[i] = key;
    }
}

/* SELECTION SORT */ 
template<typename T>
void selection_sort(std::vector<T>& A)
{
    size_t n = A.size();
	if (n <= 1)
		return;

    for (size_t i = 0; i < n - 1; ++i) {
        size_t min = i;
		
        for (size_t j = i + 1; j < n; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }
}