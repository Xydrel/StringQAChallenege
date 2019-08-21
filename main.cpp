
//Includes---------------------------------------------------------------------
#include "MyString.h"
#include <iostream>


//Macros-----------------------------------------------------------------------
#define CHECK(label, condition) \
    { \
        auto testResult = (condition); \
        std::cout << label << ": " << (testResult ? "Succeeded" : "Failed") << std::endl; \
        if (!testResult) \
            return 1; \
    }


//Main-------------------------------------------------------------------------
int main()
{
    {
        MyString result("a");
        auto compare = result == "a";
        std::cout << "Compare result: " << (int)compare << std::endl;
        CHECK("Testing MyString construction with string literal", result == "a");
    }

    //...TODO: Add more tests

    return 0;
}
