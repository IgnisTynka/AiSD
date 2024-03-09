#include "sort.h"
#include <memory>

std::vector<int> insertion_sort(std::vector<int> array) {
    int temp;
    size_t i, j;
    for (i = 1; i < array.size(); i++) {
        // copy of the current element
        temp = array[i]; 
        // position of the previous element   
        j = i - 1;      

        /* if the previous element is greater than the current element
        move the previous element to the next position */ 
        while (j >= 0 && array[j] > temp) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        }

        // insert the current element in the correct position
        array[j + 1] = temp; 
    }
    return array;
}