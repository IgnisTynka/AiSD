#include "sort.h"
#include <memory>
#include <cstdlib> 
#include <ctime>   

int random_partition(std::vector<int> &array, int low, int high) {
    // Generate a random index within the range [low, high]
    srand(time(NULL)); // Seed the random number generator
    int randomIndex = low + rand() % (high - low + 1);

    // Swap the randomly selected element with the first element (low)
    std::swap(array[randomIndex], array[low]);
    int pivot = array[low];
    int i = high + 1; 

    for (int j = high; j > low; j--) {
        if (array[j] >= pivot) {
            i--;
            std::swap(array[i], array[j]);
        }
    }
    // Move pivot to its correct position
    std::swap(array[i - 1], array[low]); 
    return (i - 1);
}

void quick_sort_random(std::vector<int> &array, int low, int high) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = random_partition(array, low, high);
        // Recursion Call smaller element than pivot goes left and higher element goes right
        quick_sort_random(array, low, pi - 1);
        quick_sort_random(array, pi + 1, high);
    }
}

std::vector<int> quick_sort_random_pivot(std::vector<int> array) {
	// Call the quick_sort_random function
    quick_sort_random(array, 0, array.size() - 1);
    return array;
}