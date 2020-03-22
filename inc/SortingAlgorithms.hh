#ifndef SORTINGALGORITHMS_HH
#define SORTINGALGORITHMS_HH

#include "../inc/ArrayTools.hh"
#include "../inc/AlgorithmTools.hh"




template <typename T>
void Quicksort(T* array, int startIndex, int endIndex, const char order)
{
    if(startIndex < endIndex)
    {
        int pivotIndex = Partition(array, startIndex, endIndex, order);
        Quicksort(array,  startIndex, pivotIndex-1, order);
        Quicksort(array, pivotIndex+1, endIndex, order);
    }
}


template <typename T>
void Heapsort(T* array, int startIndex, int endIndex, const char order)
{

}


template <typename T>
void Mergesort(T* array, int startIndex, int endIndex, const char order)
{

}


template <typename T>
void Introsort(T* array, int startIndex, int endIndex, const char order)
{

}



#endif