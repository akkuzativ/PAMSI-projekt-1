#include <iostream>
#include <chrono>
#include <ctime>

#include "../inc/ArrayTools.hh"
#include "../inc/SortingAlgorithms.hh"

int main()
{

    srand(time(NULL));
    int N = 10;

    int* int_array = ArrayTools::Create<int>(N);
    float* float_array = ArrayTools::Create<float>(N);

    ArrayTools::Fill(int_array, N, 1, '>');
    ArrayTools::PrintFromatted(int_array, N);

    ArrayTools::Fill(float_array, N, 1, '>');
    ArrayTools::PrintFromatted(float_array, N);


    return 0;

}
