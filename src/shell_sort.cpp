#include "sort.h"

std::vector<int> shell_sort(std::vector<int> array) {
    int temp;
    size_t gap, i, j;

    for (gap = array.size()/2; gap > 0; gap /= 2) 
    { 
        
        for (i = gap; i < array.size(); i += 1) 
        { 
            int temp = array[i]; 
  
            /* shift earlier elements up until 
            the correct location for temp (array[i]) is found */ 
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) 
                array[j] = array[j - gap]; 
              
            //  put temp (array[i]) in its correct location 
            array[j] = temp; 
        } 
    } 
    return array;
}