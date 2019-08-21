
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

//Forward declares-------------------------------------------------------------
int runTests();


//Main-------------------------------------------------------------------------
int main()
{
	std::cout << "Starting test runs..." << std::endl;

	runTests();

	std::cout << "Hit a key to exit test application..." << std::endl;
	std::cin.get();

    return 0;
}

int runTests()
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
		std::cout << "Validating empty construction of MyString type" << std::endl;
		MyString emptyConstTest;
		/* Validating that the string is nullptr */
		{
			auto compare = emptyConstTest == nullptr;
			std::cout << "Validate for nullptr:  " << (int)compare << std::endl;
			CHECK("Testing MyString is nullptr construction: expected: Succeeded | result: ", emptyConstTest == nullptr);
		}
		/* Ensuring that the length is 0 as expected */
		{
			const int expectedStrLen = 0;
			auto compare = emptyConstTest.length() == expectedStrLen;
			std::cout << "Validate length is 0:  " << (int)compare << std::endl;
			CHECK("Testing MyString length returns 0 after construction: expected: Succeeded | result: ", emptyConstTest.length() == expectedStrLen);
		}
		/* Ensuring that the string is empty as expected */
		{
			auto compare = emptyConstTest.empty() == true;
			std::cout << "Validate empty is true:  " << (int)compare << std::endl;
			CHECK("Testing MyString empty returns true after construction: expected: Succeeded | result: ", emptyConstTest.empty() == true);
		}
	}

	/*
		Validate the copy construction from other string results in a string the same as the initial string
	*/
	{
		MyString string1("test1");
		MyString string2(string1);
		auto compare = string1 == string2;
		std::cout << "Validate copy construction: " << (int)compare << std::endl;
		CHECK("Testing Copy Construction from other string: expected: Succeeded | result: ", string1 == string2);
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


	/*
		Validate Empty returns true when the string is empty and false when not empty
	*/

	std::cout << "Test runs complete..." << std::endl;

	return 1;
}
