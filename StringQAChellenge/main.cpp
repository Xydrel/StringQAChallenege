
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
        CHECK("Testing MyString construction with string literal: expected: Succeeded | result: ", result == "a");
    }

    //...TODO: Add more tests

	/*
		Validate the default constructor is initializing an empty MyString type
	*/
	{
		MyString emptyConstTest;
		const int expectedEmptyStringLen = 0;
		auto compare = emptyConstTest.length() <= expectedEmptyStringLen;
		std::cout << "Validate Empty Constructed string:  " << (int)compare << std::endl;
		CHECK("Testing MyString Empty construction: expected: Succeeded | result: ", emptyConstTest.length() <= expectedEmptyStringLen);
	}

	/*
		Validate that the length method is returning the correct size value
	*/
	{
		MyString lengthTest("test");
		const int expectedCharLen = 4;
		auto compare = lengthTest.length() == expectedCharLen;
		std::cout << "Validate length method: " << (int)compare << std::endl;
		CHECK("Testing MyString test length() is 4: expected: Succeeded | result: ", lengthTest.length() == expectedCharLen);
	}


	std::cout << "Hit a key to exit test application..." << std::endl;
	std::cin.get();

    return 0;
}
