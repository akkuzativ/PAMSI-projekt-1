#ifndef ALGORITHMTOOLS_HH
#define ALGORITHMTOOLS_HH

#include "../inc/ArrayTools.hh"

template <typename T>
int Partition(T* array, int startIndex, int endIndex, const char order)
{
    int pivotIndex = (endIndex+startIndex)/2;
    T pivotValue = array[pivotIndex];
    ArrayTools::SwapValues(array[pivotIndex], array[endIndex]); //wyrzucenie pivota na koniec, tak zeby nie bral udzialu w podziale tablicy
    
    int currentPosition = startIndex;
    for (int i = startIndex; i <= (endIndex-1); i++)
    {
        if (array[i] < pivotValue) //zmiana znaku tutaj zmienia order sortowania -- do ogarniecia ladniej
        {
            ArrayTools::SwapValues(array[i], array[currentPosition]);
            currentPosition++;
        }
    }
    ArrayTools::SwapValues(array[currentPosition], array[endIndex]); //przywrocenie pivota na wlasciwe miejsce
    return currentPosition;
}

template <typename T>
void MergeArrays(T* array, int startIndex, int middleIndex, int endIndex, char order)
{
    
}

#endif