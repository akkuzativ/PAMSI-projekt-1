#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"


bool AlgorithmTest(int retries)
{
    int length = 1000;
    int* testArray = ArrayTools::Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        ArrayTools::Fill(testArray, length-1, 0, '<');
        Quicksort(testArray, 0, length-1, '<');
        if (!ArrayTools::IsSorted(testArray, length-1, '<'))
        {
            return false;
        }
        //std::cout << i << std::endl;
    }
    //std:: cout << (time2 - time1) << "s" << std::endl;
    return true;
}

void TestNotification(int retries)
{
    if (AlgorithmTest(retries))
    {
        std::cerr << "Posortowana" << std::endl;
    }
    else
    {
        std::cerr << "Blad" << std::endl;
    }
}




int main()
{

    srand(time(NULL));


    TestNotification(10);

    

}
