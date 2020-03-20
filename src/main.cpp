#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{

    srand(time(NULL));
    int N = 3;

    int* array1 = ArrayTools::Create<int>(N);
    int* array2 = ArrayTools::Create<int>(N);

    ArrayTools::Fill(array1, N, 1, '>');
    ArrayTools::PrintFormatted(array1, N);

    ArrayTools::Fill(array2, N, 1, '<');
    ArrayTools::PrintFormatted(array2, N);

    ArrayTools::SwapValues(array1[0], array2[2]);

    std::cout << '\n';

    ArrayTools::PrintFormatted(array1, N);

    ArrayTools::PrintFormatted(array2, N);


    return 0;

}
