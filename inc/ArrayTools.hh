#ifndef ARRAYTOOLS_HH
#define ARRAYTOOLS_HH

#include <iostream>
#include <random>
#include <algorithm>



namespace ArrayTools
{

    template <typename T>
    bool IsSorted(T* array, int length)
    {
        if (length==0 || length==1)
        {
            return true;
        }
        for (int i=1; i<length; i++)
        {
            if (array[i] < array[i-1])
            {
                return false;
            }
        }
        return true;
    }

    
    template <typename T>
    void PrintFromattedArray(T* array, int length)
    {
        std::cout << '{' << array[0];
        for (int i = 1; i < length; i++)
        {
            std::cout << ',' << array[i];
        }
        std::cout << '}' << std::endl;
    }

    
    template <typename T>
    void FillRandom(T* array, int length)
    {
        for (int i=0; i<length; i++)
        {
            array[i] = rand() % 100;
        }
    }

    
    template <typename T>
    T* CreateArray(int length)
    {
        return new T[length];
    }    

    
    template <typename T>
    void FillRandomAndSortFromBeginning(T* array, int length, float percentSorted, const char order)
    {
        FillRandom(array, length);  
        int lastIndex = ceil(length*percentSorted);
        switch(order)
        {
          case '<':
            std::sort(array, array + lastIndex, std::less<T>());
            break;

          case '>':
            std::sort(array, array + lastIndex, std::greater<T>());
            break;
        }
    }

    
}


#endif
