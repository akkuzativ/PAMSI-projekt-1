#ifndef TESTMANAGER_HH
#define TESTMANAGER_HH

#include "../inc/ArrayManager.hh"

class TestManager
{
private:
    ArrayManager ArrayManager;
    //Test Stack
    //Test Records
public:
    void SaveTestsRecordsToFile();
    void RunTests();
};



#endif