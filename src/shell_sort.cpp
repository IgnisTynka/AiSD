#include "sort.h"
#include <memory>
#include <cmath>

std::vector<int> shell_sort(std::vector<int> array) {
    int temp, p = 0;
    size_t gap, i, j;

    // Calculate the gap using the Sedgewick formula: 9 * 4^k - 9 * 2^k + 1
    gap = 9 * std::pow(4, p) - 9 * std::pow(2, p) + 1;
    p++;
    
    while (gap < array.size()) {
        
        for (i = gap; i < array.size(); i += 1) 
        { 
            temp = array[i]; 
  
            /* Shift earlier elements up until 
            the correct location for temp (array[i]) is found */ 
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) 
                array[j] = array[j - gap]; 
              
            //  put temp (array[i]) in its correct location 
            array[j] = temp; 
        } 
        // Calculate the next gap
        gap = 9 * std::pow(4, p) - 9 * std::pow(2, p) + 1;
        p++;     
    } 
    return array;
}