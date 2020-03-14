#include <iostream>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{

    int test_arr[10] = {9, 4, 3, 2, 1, 6, 7, 8, 0, 5};
    Quicksort(test_arr, '>');

    return 0;
}
