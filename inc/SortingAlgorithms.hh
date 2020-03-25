#ifndef SORTINGALGORITHMS_HH
#define SORTINGALGORITHMS_HH

#include "../inc/ArrayTools.hh"
#include "../inc/AlgorithmTools.hh"




template <typename T>
void Quicksort(T* array, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int pivotIndex = Partition(array, startIndex, endIndex);
        Quicksort(array,  startIndex, pivotIndex-1);
        Quicksort(array, pivotIndex+1, endIndex);
    }
}


template <typename T>
void Heapsort(T* array, int startIndex, int endIndex)
{
    for (int i = endIndex/2+1; i>= startIndex; i--)
        Heapify(array, endIndex, i);

    for (int i = endIndex+1; i >= startIndex; i--)
    {
        SwapValues(array[startIndex], array[i]);
        Heapify(array, i, startIndex);
    }
}


template <typename T>
void Mergesort(T* array, int startIndex, int endIndex)
{
    int middleIndex;
    if (startIndex != endIndex)
    {
        middleIndex = (startIndex+endIndex)/2;
        Mergesort(array, startIndex, middleIndex);
        Mergesort(array, middleIndex+1, endIndex);
        MergeArrays(array, startIndex, middleIndex, endIndex);
    }
}


template <typename T>
void Insertionsort(T* array, int startIndex, int endIndex)
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
void Introsort(T* array, int startIndex, int endIndex, int depth)
{
    if (depth<=0)
    {
        Heapsort(array, startIndex, endIndex);
        return;
    }
    int i = Partition(array, startIndex, endIndex);
    if (i>9)
        Introsort(array, startIndex, i, depth-1);
    if (endIndex-1-i>9)
        Introsort(array, startIndex+i+1, endIndex-1-i, depth-1);
}

template <typename T>
void HybridIntrosort(T* array, int startIndex, int endIndex)
{
  Introsort(array, startIndex, endIndex, (int)floor(2*log(endIndex)/M_LN2));
  Quicksort(array, startIndex, endIndex);
}
 



#endif