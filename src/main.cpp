#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include "sort.h"

/// Function to read the file (path algorithn_number main function)
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

/// Function to select the algorithm to sort the array 
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
        case 7:
            sorted_array = rev_quick_sort_random_pivot(array);
            break;
    }
    return sorted_array;
}

/// Function to print the array
void print_array(std::vector<int> array){
    for (size_t i = 0; i < 100 && i < array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// benchmark main function
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

    return 0;
}  


// path algorithm_number main function
// int main(int argc, char const *argv[]) {

//     if (argc < 3){
//         std::cout << "Error: missing arguments" << std::endl;
//         return 1;
//     }

//     std::string file_name = argv[1];
//     int algorithm_number = std::stoi(argv[2]);
//     auto array = read_file(file_name); 

//     auto sorted_array =  sort_using_algorithm(array, algorithm_number);

//     std::cout << "Sorted data: ";
//     print_array(sorted_array);
    
//     return 0;
// } 


// own array main function
// int main(){
//     std::vector<int> array = {};
//     auto sorted_array =  sort_using_algorithm(array, 1);
//     std::cout << "Sorted data: ";
//     print_array(sorted_array);
//     return 0;
// }

