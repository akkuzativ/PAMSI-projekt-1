#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <ios>
#include <string>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"
#include "../inc/ArraySet.hh"


int main()
{

    int N=10000;
    int* introTestArraySet[100];
    for(int i = 0; i <= 99; i++)
    {
        introTestArraySet[i] = Create<int>(N);
    }
    for(int i = 0; i <= 99; i++)
    {
        Fill(introTestArraySet[i], N-1, 0, '<');
    }
    for(int i = 0; i <= 99; i++)
    {
        Introsort(introTestArraySet[i], 0, N-1);
        if (IsSorted(introTestArraySet[i], N-1, '<'))
            std::cout << "Posortowalo dobrze" << std::endl;
        else
            std::cout << "Nie posortowalo poprawnie" << std::endl;
    }


 /*

    char userChoice;

    std::cout << "===========================================" << std::endl;
    std::cout << "Prosty manager testow algorytmow sortowania" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "q - Testuj algorytm quicksort" << std::endl;
    std::cout << "m - Testuj algorytm mergesort" << std::endl;
    std::cout << "h - Testuj algorytm heapsort" << std::endl;
    std::cout << "e - Wyjscie" << std::endl;
    std::cout << std::endl;
    std::cout << "Twoj wybor > ";

    ArraySet<int> UniversalArraySet;
    float sortedPercentset[7] = {0, 25, 50, 75, 95, 99, 99.7};

    do
    {
        std::cin >> userChoice;
        switch(userChoice)
        {
          case 'q':
            std::cout << "Rozpoczynam test algorytmu quicksort:" << std::endl;
            for (int i=0; i <= 6; i++ )
                UniversalArraySet.TestQuicksort("Quicksort.txt", sortedPercentset[i], '<');   
            UniversalArraySet.TestQuicksort("Quicksort.txt", 100, '>');
            std::cout << "Test Zakonczony" << std::endl;
            break;
         case 'm':
            std::cout << "Rozpoczynam test algorytmu mergesort:" << std::endl;
            for (int i=0; i <= 6; i++ )
                UniversalArraySet.TestMergesort("Mergesort.txt", sortedPercentset[i], '<');   
            UniversalArraySet.TestMergesort("Mergesort.txt", 100, '>');
            std::cout << "Test Zakonczony" << std::endl;
          break;
        case 'h':
            std::cout << "Rozpoczynam test algorytmu heapsort:" << std::endl;
            for (int i=0; i <= 6; i++ )
                UniversalArraySet.TestHeapsort("Heapsort.txt", sortedPercentset[i], '<');   
            UniversalArraySet.TestHeapsort("Heapsort.txt", 100, '>');
            std::cout << "Test Zakonczony" << std::endl;
          break;
        case 'e':
            std::cout << "Zamykam program..." << std::endl;
            break;
        default:
            std::cout << "Nie rozpoznano polecenia" << std::endl;
            break;
        }
    } while (userChoice != 'e');
*/
 
}