#ifndef ARRAYTOOLS_HH
#define ARRAYTOOLS_HH

#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>



template <typename T>
T* Create(int elementAmount)
{
    return new T[elementAmount];
}


template <typename T>
void PrintFormatted(T* array, int startIndex, int endIndex)
{
    std::cout << '{' << array[startIndex];
    for (int i = startIndex+1; i <= endIndex; i++)
    {
        std::cout << ',' << array[i];
    }
    std::cout << '}' << '\n';
}


template <typename T>
void SwapValues(T& value1, T& value2)
{
    T helper = value1;
    value1 = value2;
    value2 = helper;
}


template <typename T>
bool IsSorted(T* array, int endIndex, const char order)
{
    if (endIndex==0 || endIndex==1)
    {
        return true;
    }
    switch(order)
    {
        case '<':
        for (int i=1; i <= endIndex; i++)
        {
            if (array[i] < array[i-1]) return false;
        }
        break;

        case '>':
        for (int i=1; i <= endIndex; i++)
        {
            if (array[i] > array[i-1]) return false;
        }
        break;
    }
    return true;
}


template <typename T>
void Fill(T* array, int endIndex, float percentSorted, const char order)
{
    for (int i = 0; i <= endIndex; i++)
    {
        array[i] = std::rand();
    }
    int lastIndexSorted = ceil(0.01*endIndex*percentSorted);
    switch(order)
    {
        case '<':
        std::sort(array, array+lastIndexSorted, std::less<T>());
        break;

        case '>':
        std::sort(array, array+lastIndexSorted, std::greater<T>());
        break;
    }
}




#endif