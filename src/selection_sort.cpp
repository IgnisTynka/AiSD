#include "sort.h"
#include <memory>

std::vector<int> selection_sort(std::vector<int> array) {
    size_t  i, j, min_index;
  
    for (i = 0; i < array.size() - 1; i++) { 
        min_index = i; 

        // Find the minimum element in the unsorted array
        for (j = i + 1; j < array.size(); j++) { 

            /* If the current element is smaller than the minimum element
            found so far change the min_index */ 
            if (array[j] < array[min_index]) 
                min_index = j; 
        } 
  
        /* Swap the found minimum element with the i-th element */
        if (min_index != i) 
            std::swap(array[i], array[min_index]);
    } 
    return array;
}