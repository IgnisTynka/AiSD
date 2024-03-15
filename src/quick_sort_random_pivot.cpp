#include "sort.h"
#include <memory>
#include <cstdlib>

void quick_sort_random(std::vector<int> &array, size_t left, size_t right)
{
    if(left >= right){
        return;
    }
	
	int i = left -1 , j = right + 1, 
    // select the pivot element
	pivot = array[rand() % (right - left + 1) + left]; 
	

	while(1)
	{
        // find the element greater or equal to the pivot
		while(pivot>array[++i]);

		// find the element smaller or equal to the pivot
		while(pivot<array[--j]);
		
        // if the counters have not crossed, swap the elements
		if( i <= j){
			std::swap(array[i],array[j]);
        }else{
			break;}
	}

	if(j > left)
	    quick_sort_random(array, left, j);
	if(i < right)
	    quick_sort_random(array, i, right);
}

std::vector<int> quick_sort_random_pivot(std::vector<int> array) {
	// Call the quick_sort_random function
    quick_sort_random(array, 0, array.size() - 1);
    return array;
}