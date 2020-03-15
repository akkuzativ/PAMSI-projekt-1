#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{

    srand(time(NULL));
    int N = 10;

    //int test_arr[10] = {9, 4, 3, 2, 1, 6, 7, 8, 0, 5};

    int* int_array = ArrayTools::CreateArray<int>(N);
    float* float_array = ArrayTools::CreateArray<float>(N);
    
    
    ArrayTools::FillRandom(int_array, N);
    ArrayTools::FillRandom(float_array, N);
    ArrayTools::PrintFromattedArray(int_array, N);
    ArrayTools::PrintFromattedArray(float_array, N);
    std::cout << ArrayTools::IsSorted(int_array, N) << std::endl;
    std::cout << ArrayTools::IsSorted(float_array, N) << std::endl;

    int* array3 = ArrayTools::CreateArray<int>(N);
    ArrayTools::FillRandomAndSortFromBeginning(array3, N, 1, '<');
    ArrayTools::PrintFromattedArray(array3, N);
    std::cout << ArrayTools::IsSorted(array3, N) << std::endl;


    return 0;
}
