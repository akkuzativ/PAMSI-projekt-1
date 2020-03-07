#ifndef ARRAYMANAGER_HH
#define ARRAYMANAGER_HH

class ArrayManager
{
private:
public:
    //typename CreateArray();
    void SaveArrayToFile();
    void LoadArrayFromFile();
    int GetArrayLenght();
    const char* getArrayType();
    void SortArray();
    void PrintArrayFormatted();
};

#endif