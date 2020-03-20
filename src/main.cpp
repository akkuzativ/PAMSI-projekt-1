#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{

    srand(time(NULL));
    int N = 10;

    int* array1 = ArrayTools::Create<int>(N);
    //int* array2 = ArrayTools::Create<int>(N);

    ArrayTools::Fill(array1, N, 0, '>');
    ArrayTools::PrintFormatted(array1, N);

    //ArrayTools::Fill(array2, N, 1, '<');
    //ArrayTools::PrintFormatted(array2, N);

    std::cout << '\n';

    Quicksort(array1, 0, N, '>');

    ArrayTools::PrintFormatted(array1, N);
    if (ArrayTools::IsSorted(array1, N, '<'))
    {
        std::cout << "Posortowana" << std::endl;
    }
    else
    {
        std::cout << "Blad" << std::endl;
    }
    
    return 0;

}
