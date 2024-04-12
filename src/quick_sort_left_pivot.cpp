#include "sort.h"
#include <memory>

int partition(std::vector<int> &array,int low,int high)
{
	//choose the pivot
	int pivot = array[low];
    int i = high + 1;

	// Rearrange the array so that all elements with values less than the pivot come before the pivot
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

void quick_sort_left(std::vector<int> &array,int low,int high)
{
	if(low<high)
	{
		// pi is the partition return index of pivot
		int pi=partition(array,low,high);
		//Recursion Call smaller element than pivot goes left and higher element goes right
		quick_sort_left(array,low,pi-1);
		quick_sort_left(array,pi+1,high);
	}
}
  
std::vector<int> quick_sort_left_pivot(std::vector<int> array) {
    // Call the quick_sort_left function
    quick_sort_left(array, 0, array.size() - 1);
    return array;
}

// Wskaźnik na funkcję jako argument
// void quick_sort_left(std::vector<int> &array,int low,int high, int (*partition)(std::vector<int>&, int, int))