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
    int heapSize = endIndex-startIndex+1;
    T* helperArray = Create<T>(heapSize);
    for(int i = 0; i <= endIndex-startIndex; i++)
        helperArray[i] = array[startIndex+i];

    for (int i = (heapSize-1)/2; i >= 0; i--)
        Heapify(helperArray, heapSize, i);
    for (int i = heapSize-1; i >= 0; i--)
    {
        SwapValues(helperArray[0], helperArray[i]);
        Heapify(helperArray, i, 0);
    }
    for (int i = 0; i <= (endIndex-startIndex); i++)
        array[startIndex+i] = helperArray[i];
    delete[] helperArray;
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
void IntrosortR(T* array, int startIndex, int endIndex, int depth)
{
    if ((endIndex-startIndex) < 16)
    {
        Insertionsort(array, startIndex, endIndex);
    }
    else if (depth == 0)
    {
        Heapsort(array, startIndex, endIndex);
    }
    else
    {
        int pivotIndex = Partition(array, startIndex, endIndex);
        IntrosortR(array, startIndex, pivotIndex-1, depth-1);
        IntrosortR(array, pivotIndex+1, endIndex, depth-1);
    }
    
}


template <typename T>
void Introsort(T* array, int startIndex, int endIndex)
{
    int depth = log(endIndex+1)*2;
    IntrosortR(array, startIndex, endIndex, depth);
 
}
 



#endif