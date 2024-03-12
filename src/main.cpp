#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include "sort.h"

// Function to print the array
void print_array(std::vector<int> array){
    for (size_t i = 0; i < 10 && i < array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Function to read the file and return the array
std::vector<int> read_file(std::string file_name){
    std::ifstream file(file_name);
    
    if (file.bad()){
        std::cout << "Error: file not found" << std::endl;
        return std::vector<int>();
    }

    size_t size;
    file >> size;

    std::vector<int> array(size);
    for(size_t i = 0; i < size && !file.eof(); i++){
        file >> array[i];
    }

    file.close();
    return array;
}

// Function to select the algorithm to sort the array 
std::vector<int> select_algorithm(std::vector<int> array, int n){
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

    if (argc < 3){
        std::cout << "Error: missing arguments" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];
    int algorithm_number = std::stoi(argv[2]);
    auto array = read_file(file_name); 

    auto sorted_array = select_algorithm(array, algorithm_number);
    print_array(sorted_array);
    
    return 0;
}  