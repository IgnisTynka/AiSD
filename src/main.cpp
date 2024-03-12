#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "sort.h"

// Function to print the array
void print_array(std::vector<int> array){
    for (size_t i = 0; i < 10 && i < array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Function to select the algorithm to sort the array 
std::vector<int> sort_using_algorithm(std::vector<int> array, int n){
    std::vector<int> sorted_array;
    switch (n){
        case 1:
            sorted_array = insertion_sort(array);
            break;

        case 2:
            sorted_array = shell_sort(array);
            break;

        case 3:
            sorted_array =  selection_sort(array);
            break;
        
        case 4:
            sorted_array = heap_sort(array);
            break;

        case 5:
            sorted_array = quick_sort_left_pivot(array);
            break;

        case 6:
            sorted_array = quick_sort_random_pivot(array);
            break;
    }
    return sorted_array;
}

int main(int argc, char const *argv[]) {

    if (argc != 3 || std::string(argv[1]) != "--algorithm") {
        std::cout << "Usage: ./executable --algorithm <algorithm_number>" << std::endl;
        return 1;
    }

    // Get algorithm number from command line arguments
    int algorithm_number;
    std::istringstream(argv[2]) >> algorithm_number;

    // Read input data from standard input until the end of file (EOF)
    std::vector<int> data;
    int value;
    while (std::cin >> value) {
        data.push_back(value);
    }

    // Perform sorting using the specified algorithm
    std::vector<int> sorted_data = sort_using_algorithm(data, algorithm_number);

    // Print the sorted data (first 10 elements for simplicity)
    std::cout << "Sorted data: ";
    print_array(sorted_data);

    return 0;
}  