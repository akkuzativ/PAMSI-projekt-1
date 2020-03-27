#ifndef ARRAYSET_HH
#define ARRAYSET_HH


#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <ios>
#include <string>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"


template <typename T>
class ArraySet
{
private:
    T* arraySet[5][100];
    int sizes[5] = {10000, 50000, 100000, 500000, 1000000};
public:
    ArraySet();
    bool Test(char algorithmLetter, std::string filename, float percentSorted, const char order);
};

template <typename T>
ArraySet<T>::ArraySet()
{
    for (int i=0; i<=4; i++)
    {
        for (int j=0; j<=100-1; j++)
        {
            arraySet[i][j] = Create<T>(sizes[i]);
        }
    }
}


template <typename T>
bool ArraySet<T>::Test(char algorithmLetter, std::string filename, float percentSorted, const char order)
{
    std::ofstream resultsFile;
    resultsFile.open(filename,  std::ios::out | std::ios::app);
    resultsFile << "Testowany algorytm: "<< algorithmLetter << std::endl;
    resultsFile << "procent wstepnego posortowania: " << percentSorted << ", kolejnosc: " << order << std::endl;

    for (int i=0; i<=4; i++)
    {
        for (int j=0; j<=100-1; j++)
        {
            Fill<T>(arraySet[i][j], sizes[i]-1, percentSorted, order);
        }
    }
    switch(algorithmLetter)
    {
      case 'q':
        for (int i=0; i<=4; i++)
        {
            auto sortingStart = std::chrono::high_resolution_clock::now();
            for (int j=0; j<=100-1; j++)
            {
                Quicksort(arraySet[i][j], 0, sizes[i]-1);
            }
            auto sortingEnd = std::chrono::high_resolution_clock::now();
            auto sortingDuration = std::chrono::duration_cast<std::chrono::milliseconds>(sortingEnd - sortingStart);
            resultsFile << " rozmiar tablicy: " << sizes[i] << std::endl;
            resultsFile << " laczny czas sortowania zestawu 100 tablic: " << sortingDuration.count() << " milisekund" << std::endl;
        }
        break;
      case 'm':
        for (int i=0; i<=4; i++)
        {
            auto sortingStart = std::chrono::high_resolution_clock::now();
            for (int j=0; j<=100-1; j++)
            {
                Mergesort(arraySet[i][j], 0, sizes[i]-1);
            }
            auto sortingEnd = std::chrono::high_resolution_clock::now();
            auto sortingDuration = std::chrono::duration_cast<std::chrono::milliseconds>(sortingEnd - sortingStart);
            resultsFile << " rozmiar tablicy: " << sizes[i] << std::endl;
            resultsFile << " laczny czas sortowania zestawu 100 tablic: " << sortingDuration.count() << " milisekund" << std::endl;
        }
        break;
      case 'i':
        for (int i=0; i<=4; i++)
        {
            auto sortingStart = std::chrono::high_resolution_clock::now();
            for (int j=0; j<=100-1; j++)
            {
                Introsort(arraySet[i][j], 0, sizes[i]-1);
            }
            auto sortingEnd = std::chrono::high_resolution_clock::now();
            auto sortingDuration = std::chrono::duration_cast<std::chrono::milliseconds>(sortingEnd - sortingStart);
            resultsFile << " rozmiar tablicy: " << sizes[i] << std::endl;
            resultsFile << " laczny czas sortowania zestawu 100 tablic: " << sortingDuration.count() << " milisekund" << std::endl;
        }
        break;
    }
    for (int i=0; i<=4; i++)
    {
        for (int j=0; j<=100-1; j++)
        {
            if(IsSorted(arraySet[i][j], 0, sizes[i]-1) == false)
            {
                resultsFile << "  (!) Proces nie powiodl sie, elementy nie sa posortowane w 100%." << std::endl;
                resultsFile.close();
                return false;
            }
        }
    }
    resultsFile << "  Posortowanie wykonano poprawnie." << std::endl << std::endl;
    resultsFile.close();
    return true;   
}


#endif