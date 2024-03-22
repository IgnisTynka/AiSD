#include "sort.h"
#include <memory>
#include <cmath>

std::vector<int> shell_sort(std::vector<int> array) {
    int temp;
    size_t gap;

    // Calculate the gaps vector using the Sedgewick formula: 9 * 4^k - 9 * 2^k + 1
    std::vector<size_t> gaps;
    size_t p = 0;
    gap = 9 * std::pow(4, p) - 9 * std::pow(2, p) + 1;
    while (gap < array.size()) {
        gaps.push_back(gap);
        p++;
        gap = 9 * std::pow(4, p) - 9 * std::pow(2, p) + 1;
    }
    
    for (int i = gaps.size() - 1; i >= 0; --i) {
        gap = gaps[i];

        // Start with the gap and sort the subarrays
        for (size_t j = gap; j < array.size(); ++j) { 
            temp = array[j];
            size_t k;
            // Sort the subarray
            for (k = j; k >= gap && array[k - gap] > temp; k -= gap) 
                array[k] = array[k - gap];
            array[k] = temp; 
        } 
    } 
    return array;
}