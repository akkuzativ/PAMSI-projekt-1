#ifndef ARRAYTOOLS_HH
#define ARRAYTOOLS_HH



template <typename T>
int GetLenght(T * array);

template <typename T>
int GetMiddleIndex(T * array);

template <typename T>
bool IsSorted(T * array);

template <typename T>
void PrintArray(T * array);

template <typename T>
void FillWithSortedData(T * array);

template <typename T>
void FillWithRandomData(T * array);



#endif