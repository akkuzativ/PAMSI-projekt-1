#ifndef ALGORITHMTOOLS_HH
#define ALGORITHMTOOLS_HH

#include "../inc/ArrayTools.hh"

template <typename T>
int Partition(T* array, int startIndex, int endIndex, const char order)
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
void MergeArrays(T* array, int startIndex, int middleIndex, int endIndex, char order)
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
    int startIndex = 2*heapRoot + 1;
    int endIndex = 2*heapRoot + 2;

    if (endIndex < heapSize && array[startIndex] > array[largest] )
        largest = startIndex;
    
    if (endIndex < heapSize && array[endIndex] > array[largest])
        largest = endIndex;
    
    if (largest != heapRoot)
    {
        SwapValues(array[heapRoot], array[largest]);
        Heapify(array, heapSize, largest);
    }
}


#endif