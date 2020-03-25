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
    for (int i = endIndex/2; i>= 0; i--)
        Heapify(array, endIndex, i);
    for (int i = endIndex; i>=0; i--)
    {
            SwapValues(array[0], array[i]);
            Heapify(array, i, 0);
    }
}


template <typename T>
void Mergesort(T* array, int startIndex, int endIndex, const char order)
{
    int middleIndex;
    if (startIndex != endIndex)
    {
        middleIndex = (startIndex+endIndex)/2;
        Mergesort(array, startIndex, middleIndex, order);
        Mergesort(array, middleIndex+1, endIndex, order);
        MergeArrays(array, startIndex, middleIndex, endIndex, order);
    }
}


template <typename T>
void Insertionsort(T* array, int startIndex, int endIndex, const char order)
{
    int j;
    T helper;
    for (int i = startIndex; i <= endIndex; i++)
    {
        helper = array[i];
        for (j = i; j>0 && helper < array[j-1]; j--)
            array[j] = array[j-1];
        array[j] = helper;
    }

}

template <typename T>
void Introsort(T* array, int startIndex, int endIndex, int depth, const char order)
{
    if (depth <= 0)
    {
        Heapsort(array, startIndex, endIndex, order);
    }
    else
    {
        int i = Partition(array, startIndex, endIndex, order);
        if (i>9)
            Introsort(array, startIndex, i, depth-1, order);
        if (endIndex-1-i>9)
            Introsort(array, startIndex+i+1, endIndex-1, depth-1, order);
    }
}



#endif