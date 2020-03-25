#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <ios>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"
#include "../inc/ArraySet.hh"


int main()
{
    srand(time(NULL));
    ArraySet<int> Set1;
    Set1.TestQuicksort("test", 0, '<');
/*
    int* testArray1 = Create<int>(10000);
    Fill(testArray1, 10000-1, 0, '<');
    int* testArray2 = Create<int>(50000);
    Fill(testArray2, 50000-1, 0, '<');
    int* testArray3 = Create<int>(100000);
    Fill(testArray3, 100000-1, 0, '<');
    int* testArray4 = Create<int>(500000);
    Fill(testArray4, 500000-1, 0, '<');
    int* testArray5 = Create<int>(1000000);
    Fill(testArray5, 1000000-1, 0, '<');

    for (int i=0; i <= 99; i++)
    {
        Quicksort(testArray1, 0, 10000-1);
        Quicksort(testArray2, 0, 50000-1);
        Quicksort(testArray3, 0, 100000-1);
        Quicksort(testArray4, 0, 500000-1);
        Quicksort(testArray5, 0, 1000000-1);
    }

*/
}