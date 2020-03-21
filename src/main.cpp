#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"


bool AlgorithmTest(int retries)
{
    int length = 100;
    int* testArray = ArrayTools::Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        ArrayTools::Fill(testArray, length, 0, '<');
        Quicksort(testArray, 0, length, '<');
        if (!ArrayTools::IsSorted(testArray, length, '<'))
        {
            return false;
        }
    }
    return true;
}




int main()
{

    srand(time(NULL));
    int N = 10;

    int* array1 = ArrayTools::Create<int>(N);
    //int* array2 = ArrayTools::Create<int>(N);

    ArrayTools::Fill(array1, N, 50, '<');
    ArrayTools::PrintFormatted(array1, N);

    //ArrayTools::Fill(array2, N, 1, '<');
    //ArrayTools::PrintFormatted(array2, N);

    

   // ArrayTools::PrintFormatted(array1, N);
    if (AlgorithmTest(10))
    {
        std::cerr << "Posortowana" << std::endl;
    }
    else
    {
        std::cerr << "Blad" << std::endl;
    }
    

    std::cout << '\n';
    Quicksort(array1, 0, N, '>');
    ArrayTools::PrintFormatted(array1, N);

}
