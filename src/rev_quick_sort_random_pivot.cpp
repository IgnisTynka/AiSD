#include "sort.h"
#include <memory>
#include <cstdlib> 
#include <ctime>   

int rev_random_partition(std::vector<int> &array, int high, int low) {
    // Generate a random index within the range [high, low]
    srand(time(NULL)); // Seed the random number generator
    int randomIndex = high + rand() % (low - high + 1);

    // Swap the randomly selected element with the first element (high)
    std::swap(array[randomIndex], array[high]);
    int pivot = array[high];
    int i = low + 1; 

    for (int j = low; j > high; j--) {
        if (array[j] <= pivot) {
            i--;
            std::swap(array[i], array[j]);
        }
    }
    // Move pivot to its correct position
    std::swap(array[i - 1], array[high]); 
    return (i - 1);
}

void rev_quick_sort_random(std::vector<int> &array, int high, int low) {
    if (high < low) {
        // pi is the partition return index of pivot
        int pi = rev_random_partition(array, high, low);
        // Recursion Call smaller element than pivot goes left and higher element goes right
        rev_quick_sort_random(array, high, pi - 1);
        rev_quick_sort_random(array, pi + 1, low);
    }
}

std::vector<int> rev_quick_sort_random_pivot(std::vector<int> array) {
	// Call the quick_sort_random function
    rev_quick_sort_random(array, 0, array.size() - 1);
    return array;
}