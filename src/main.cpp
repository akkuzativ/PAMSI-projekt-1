#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"


template <typename T>
class ArraySet
{
private:
    T arrays10K[100];
    T arrays50K[100];
    T arrays100K[100];
    T arrays500K[100];
    T arrays1M[100];
public:
    ArraySet();
    void SortArrays(const char alogrithm, const char order);
};

template <typename T>
void ArraySet<T>::SortArrays(const char algorithm, const char order)
{
    Quicksort(arrays10K, 0, 10000, order);
}








bool AlgorithmTest(int retries)
{
    int length = 100;
    int* testArray = Create<int>(length);
    for (int i=0; i <= retries; i++)
    {
        Fill(testArray, length-1, 0, '<');
        Introsort(testArray, 0, length-1, 50, '<');
        if (!IsSorted(testArray, length-1, '<'))
        {
            return false;
        }
        std::cout << i << std::endl;
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
    TestNotification(50);
}
