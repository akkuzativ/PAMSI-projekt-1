#ifndef ALGORITHMTOOLS_HH
#define ALGORITHMTOOLS_HH

#include "../inc/ArrayTools.hh"

template <typename T>
int Partition(T* array, int startIndex, int endIndex)
{
    int pivotIndex = (endIndex+startIndex)/2;
    T pivotValue = array[pivotIndex];
    SwapValues(array[pivotIndex], array[endIndex]); //wyrzucenie pivota na koniec, tak zeby nie bral udzialu w podziale tablicy
    
    int currentPosition = startIndex;
    for (int i = startIndex; i <= (endIndex-1); i++)
    {
        if (array[i] < pivotValue) //zmiana znaku tutaj zmienia order sortowania -- do ogarniecia ladniej
        {
            SwapValues(array[i], array[currentPosition]);
            currentPosition++;
        }
    }
    SwapValues(array[currentPosition], array[endIndex]); //przywrocenie pivota na wlasciwe miejsce
    return currentPosition;
}


template <typename T>
void MergeArrays(T* array, int startIndex, int middleIndex, int endIndex)
{
    T* helperArray = Create<T>(endIndex+1);
    int i = startIndex;
    int j = middleIndex+1;
    int k = startIndex;
    while ( (i <= middleIndex) && (j <= endIndex ) )
    {
        if (array[i] <= array[j])
            helperArray[k++] = array[i++];
        else
            helperArray[k++] = array[j++];
    }
    while (i <= middleIndex)
        helperArray[k++] = array[i++];
    while (j <= endIndex)
        helperArray[k++] = array[j++];
    for(i=startIndex; i<=endIndex; i++)
        array[i]=helperArray[i];
    delete[] helperArray; // bardzo wazne !!!! inaczej zapcha pamiec
}


template <typename T>
void Heapify(T* array, int heapSize, int heapRoot)
{
    int largest = heapRoot;
    int leftChildIndex = 2*heapRoot;
    int rightChildIndex = 2*heapRoot+1;
    if (leftChildIndex < heapSize && array[leftChildIndex] > array[largest])
        largest = leftChildIndex;
    if (rightChildIndex < heapSize && array[rightChildIndex] > array[largest])
        largest = rightChildIndex;
    if (largest != heapRoot)
    {
        SwapValues(array[heapRoot], array[largest]);
        Heapify(array, heapSize, largest);
    }
}


#endif