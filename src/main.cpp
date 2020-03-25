#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"




bool QuicksortTest(int retries)
{
    int length = 1000000;
    int* testArray = Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        Fill(testArray, length-1, 0, '<');
        Quicksort(testArray, 0, length-1, '<');
        if (!IsSorted(testArray, length-1, '<'))
        {
            return false;
        }
        std::cout << i << '\n';
    }
    return true;
}


bool MergesortTest(int retries)
{
    int length = 1000000;
    int* testArray = Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        Fill(testArray, length-1, 0, '<');
        Mergesort(testArray, 0, length-1, '<');
        if (!IsSorted(testArray, length-1, '<'))
        {
            return false;
        }
        std::cout << i << '\n';
    }
    return true;
}


bool HybridIntrosortTest(int retries)
{
    int length = 1000000;
    int* testArray = Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        Fill(testArray, length-1, 0, '<');
        HybridIntrosort(testArray, 0, length-1, '<');
        if (!IsSorted(testArray, length-1, '<'))
        {
            return false;
        }
        std::cout << i << '\n';
    }
    return true;
}

void TestNotification(int retries, const char algLetter)
{
    bool AlgorithmTestResult;
    switch(algLetter)
    {
      case 'q':
        AlgorithmTestResult = QuicksortTest(retries);
        break;
      case 'i':
        AlgorithmTestResult = HybridIntrosortTest(retries);
        break;
      case 'm':
        AlgorithmTestResult = MergesortTest(retries);
        break;
    }
    if (AlgorithmTestResult)
    {
        std::cerr << "Posortowana" << std::endl;
    }
    else
    {
        std::cerr << "Blad" << std::endl;
    }
}




int main(int argc, char *argv[])
{
    srand(time(NULL));
    TestNotification(500, *argv[1]);
}