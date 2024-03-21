#include "sort.h"

void heapify(std::vector<int> &array, int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && array[l] > array[largest])
        largest = l;
 
    // If right child is larger than root
    if (r < N && array[r] > array[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        // Swap the largest with the root
        std::swap(array[i], array[largest]);
        // Recursively heapify the affected sub-tree
        heapify(array, N, largest);
    }
}

std::vector<int> heap_sort(std::vector<int> array) {
    // Build heap (rearrange array)
    for (int i = array.size() / 2 - 1; i >= 0; i--)
        heapify(array, array.size(), i);
 
    // One by one extract an element from heap
    for (int i = array.size() - 1; i > 0; i--) {
 
        // Move current root to end
        std::swap(array[0], array[i]);
 
        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
    return array;
}