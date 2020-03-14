#ifndef ARRAYTOOLS_HH
#define ARRAYTOOLS_HH

#include <iostream>
#include <random>





template <typename T> int GetLength(T * array)
{
    return *(&array + 1) - array;
}

template <typename T> int GetMiddleIndex(T * array);

template <typename T> bool IsSorted(T * array);

template <typename T> void PrintArray(T * array)
{
    for(int i = 0; array[i]!='\0'; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T> void FillWithSortedData(T * array);

template <typename T> T* CreateArray(int length)
{
    return new T[length];
}



#endif