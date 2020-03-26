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


    char userChoice;

    std::cout << "=============================================" << std::endl;
    std::cout << "=Prosty manager testow algorytmow sortowania=" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "q - Testuj algorytm quicksort" << std::endl;
    std::cout << "m - Testuj algorytm mergesort" << std::endl;
    std::cout << "i - Testuj algorytm introsort" << std::endl;
    std::cout << "e - Wyjscie" << std::endl;
    std::cout << std::endl;


    ArraySet<int> UniversalArraySet;
    float sortedPercentset[7] = {0, 25, 50, 75, 95, 99, 99.7};

    do
    {
        std::cout << "Twoj wybor > ";
        std::cin >> userChoice;
        switch(userChoice)
        {
          case 'q':
            std::cout << "Rozpoczynam test algorytmu quicksort:" << std::endl;
            for (int i=0; i <= 6; i++ )
            {
                UniversalArraySet.Test(userChoice,"quicksort.txt", sortedPercentset[i], '<');
            }
            UniversalArraySet.Test(userChoice,"quicksort.txt", 100, '>');
            std::cout << "Test Zakonczony" << std::endl;
            break;
         case 'm':
            std::cout << "Rozpoczynam test algorytmu mergesort:" << std::endl;
            for (int i=0; i <= 6; i++ )
            {
                UniversalArraySet.Test(userChoice,"mergesort.txt", sortedPercentset[i], '<');  
            } 
            UniversalArraySet.Test(userChoice, "mergesort.txt", 100, '>');
            std::cout << "Test Zakonczony" << std::endl;
          break;
        case 'i':
            std::cout << "Rozpoczynam test algorytmu introsort:" << std::endl;
            for (int i=0; i <= 6; i++ )
            {
                UniversalArraySet.Test(userChoice,"introsort.txt", sortedPercentset[i], '<');  
            } 
            UniversalArraySet.Test(userChoice,"introsort.txt", 100, '>');
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

 
}