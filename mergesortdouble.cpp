#include <iostream>
#include <vector>
#include "mergesort.h"

int main(){
    std::vector<double> numbers { 42.0, -7, 1.001e3, -16.5, 2.5, 0.0, -17.8 };

    mergeSort(numbers, 0, numbers.size()-1);

    for (unsigned int i=0; i < numbers.size(); i++){
        std::cout << numbers.at(i) << ' ';
    }
    std::cout << std::endl;

    return 0;
}