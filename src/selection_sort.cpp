#include "sort.h"
#include <memory>

std::vector<int> selection_sort(std::vector<int> array) {
    size_t  i, j, min_idx;
  
    for (i = 0; i < array.size() - 1; i++) { 
        min_idx = i; 

        // Find the minimum element in the unsorted array
        for (j = i + 1; j < array.size(); j++) { 

            /* If the current element is smaller than the minimum element
            found so far change the min_idx */ 
            if (array[j] < array[min_idx]) 
                min_idx = j; 
        } 
  
        /* Swap the found minimum element with the i-th element */
        if (min_idx != i) 
            std::swap(array[i], array[min_idx]);
    } 
    return array;
}