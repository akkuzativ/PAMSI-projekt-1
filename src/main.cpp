#include <iostream>
#include <chrono>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{


    int N = 10;

    //int test_arr[10] = {9, 4, 3, 2, 1, 6, 7, 8, 0, 5};

    int* int_array = CreateArray<int>(N);
    float* float_array = CreateArray<float>(N);
    
    
    FillRandom(int_array, N);
    FillRandom(float_array, N);
    PrintFromattedArray(int_array, N);
    PrintFromattedArray(float_array, N);
    std::cout << IsSorted(int_array, N) << std::endl;
    std::cout << IsSorted(float_array, N) << std::endl;


    return 0;
}
