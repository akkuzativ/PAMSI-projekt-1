#include <iostream>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{
    int N = 5;

    //int test_arr[10] = {9, 4, 3, 2, 1, 6, 7, 8, 0, 5};


    int* array = CreateArray<int>(N);
    array[2] = 1;

    return 0;
}
