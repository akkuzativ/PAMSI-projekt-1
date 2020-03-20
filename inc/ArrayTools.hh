#ifndef ARRAYTOOLS_HH
#define ARRAYTOOLS_HH

#include <iostream>
#include <random>
#include <algorithm>



namespace ArrayTools
{


    template <typename T>
    bool IsSorted(T* array, int endPoint, const char order)
    {
        if (endPoint==0 || endPoint==1)
        {
            return true;
        }

        switch(order)
        {
          case '<':
            for (int i=1; i < endPoint; i++)
            {
                if (array[i] < array[i-1]) return false;
            }
            break;

          case '>':
            for (int i=1; i < endPoint; i++)
            {
                if (array[i] > array[i-1]) return false;
            }
            break;
        }

        return true;
    }

    
    template <typename T>
    void PrintFormatted(T* array, int endPoint)
    {
        std::cout << '{' << array[0];
        for (int i = 1; i < endPoint; i++)
        {
            std::cout << ',' << array[i];
        }
        std::cout << '}' << '\n';
    }


    template <typename T>
    void Fill(T* array, int endPoint, float percentSorted, const char order)
    {
        for (int i=0; i<endPoint; i++)
        {
            array[i] = rand() % 1000;
        }

        int lastIndex = ceil(endPoint*percentSorted);
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


    template <typename T>
    T* Create(int endPoint)
    {
        return new T[endPoint];
    }


    template <typename T>
    void SwapValues(T& value1, T& value2)
    {
        T helper = value1;
        value1 = value2;
        value2 = helper;
    }

    template <typename T>
    void Partition(T* array, int startPoint, int endPoint, const char order)
    {
        int pivot;
        return pivot;
    }

}


#endif