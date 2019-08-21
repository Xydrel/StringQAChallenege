
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
	/*
		Validating the construction of a string from a const char*
	*/
	{
		MyString literalConstructTest("a");
		{
			auto compare = literalConstructTest == "a";
			std::cout << "Compare result: " << (int)compare << std::endl;
			CHECK("Testing MyString construction with string literal: expected: Succeeded | result: ", literalConstructTest == "a");
		}
		/* Ensuring that the length is 1 as expected */
		{
			const int expectedStrLen = 1;
			auto compare = literalConstructTest.length() == expectedStrLen;
			std::cout << "Validate length is 1:  " << (int)compare << std::endl;
			CHECK("Testing MyString length returns 1 after single char construction: expected: Succeeded | result: ", literalConstructTest.length() == expectedStrLen);
		}
		/* Ensuring that the string is not empty as expected */
		{
			auto compare = literalConstructTest.empty() == false;
			std::cout << "Validate empty is true:  " << (int)compare << std::endl;
			CHECK("Testing MyString empty returns false after single char construction: expected: Succeeded | result: ", literalConstructTest.empty() == false);
		}
	}

	//...TODO: Add more tests

	/*
		Validate the copy construction from other string results in a string the same as the initial string
	*/
	{
		MyString string1("test1");
		MyString string2(string1);
		{
			auto compare = string1 == string2;
			std::cout << "Validate copy construction: " << (int)compare << std::endl;
			CHECK("Testing MyString copy construction from other string: expected: Succeeded | result: ", string1 == string2);
		}
		/* Ensuring that the length is 5 as expected */
		{
			const int expectedStrLen = 5;
			auto compare = string2.length() == expectedStrLen;
			std::cout << "Validate length is 1:  " << (int)compare << std::endl;
			CHECK("Testing MyString length returns 5 after copy construction: expected: Succeeded | result: ", string2.length() == expectedStrLen);
		}
		/* Ensuring that the string is not empty as expected */
		{
			auto compare = string2.empty() == false;
			std::cout << "Validate empty is true:  " << (int)compare << std::endl;
			CHECK("Testing MyString empty returns false after copy construction: expected: Succeeded | result: ", string2.empty() == false);
		}
	}
	
	/*
		Validate the default constructor is initializing an empty MyString type
	*/
	{
		std::cout << "Validating default construction of MyString type" << std::endl;
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
		Validate Empty returns true when the string is empty and false when not empty
	*/
	{
		MyString emptyTest;
		auto compare = emptyTest.empty() == true;
		std::cout << "Validate new empty is empty: " << (int)compare << std::endl;
		CHECK("Testing MyString empty method returns empty when MyString is empty: expected: Succeeded | result: ", emptyTest.empty() == true);
	}

	/*
		Validate the the clear method appropriately clears the objects data member to nullptr
	*/
	{
		MyString clearTest("clearme!");
		clearTest.clear();
		auto compare = clearTest == nullptr;
		std::cout << "Validate clear method: " << (int)compare << std::endl;
		CHECK("Testing MyString clear method clears string value: expected: Succeeded | result: ", clearTest == nullptr);
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
		Validate assignment operator overload from string literal
	*/
	{
		MyString fromLiteralTest;
		fromLiteralTest = "literal";
		auto compare = fromLiteralTest == "literal";
		std::cout << "Validate from literal assignment: " << (int)compare << std::endl;
		CHECK("Testing MyString assigned from literal is the literal: expected: Succeeded | result: ", fromLiteralTest == "literal");
	}

	/*
		Validate assignment operator overload from MyString type value
	*/
	{
		MyString fromMyStrnTest;
		fromMyStrnTest = MyString("mystring");
		auto compare = fromMyStrnTest == "mystring";
		std::cout << "Validate from literal assignment: " << (int)compare << std::endl;
		CHECK("Testing MyString assigned from MyString is the MyString value: expected: Succeeded | result: ", fromMyStrnTest == "mystring");
	}

	/*
		Validate literal equality logical operator overload
	*/
	{
		MyString literalCompTest("testpass");
		const char* cStr = "testpass";
		auto compare = literalCompTest == cStr;
		std::cout << "Validate C string against MyString equality: " << (int)compare << std::endl;
		CHECK("Test MyString value equality against C string: expected: Succeeded | result: ", literalCompTest == cStr);
	}

	/*
		Validate MyString equality logical operator overload
	*/
	{
		MyString myCompStr1Test("testpass");
		MyString myCompStr2test("testpass");
		auto compare = myCompStr1Test == myCompStr2test;
		std::cout << "Validate MyString against MyString equality: " << (int)compare << std::endl;
		CHECK("Test MyString value equality against MyString: expected: Succeeded | result: ", myCompStr1Test == myCompStr2test);
	}

	/*
		Validate return of new string from MyString and literal string
	*/
	{
		MyString literalConcatTest("test");
		MyString resultStr = literalConcatTest + "pass";
		auto compare = resultStr == "testpass";
		std::cout << "Validate literal concatenation: " << (int)compare << std::endl;
		CHECK("Test MyString literal concatenation to new string: expected: Succeeded | Result: ", resultStr == "testpass");
	}

	/*
		Validation of concatenation of MyString and literal string operator directly
	*/
	{
		MyString literalConcatTest("test");
		literalConcatTest += "pass";
		auto compare = literalConcatTest == "testpass";
		std::cout << "Validate literal concatenation: " << (int)compare << std::endl;
		CHECK("Test MyString and literal concatenation to this string: expected: Succeeded | Result: ", literalConcatTest == "testpass");
	}

	/*
		Validate return of new string from MyString and MyString
	*/
	{
		MyString concatTest("test");
		MyString resultStr = concatTest + MyString("pass");
		auto compare = resultStr == "testpass";
		std::cout << "Validate literal concatenation: " << (int)compare << std::endl;
		CHECK("Test MyString concatenation to new MyString: expected: Succeeded | Result: ", resultStr == "testpass");
	}

	/*
		Validation of concatenation of MyString and MyString operator directly
	*/
	{
		MyString concatTest("test");
		concatTest += MyString("pass");
		auto compare = concatTest == "testpass";
		std::cout << "Validate literal concatenation: " << (int)compare << std::endl;
		CHECK("Test MyString and MyString concatenation to this string: expected: Succeeded | Result: ", concatTest == "testpass");
	}

	/*
		Validate that the MyString can return a C style string
	*/
	{
		MyString cReturnTest("testpass");
		const char* cStr = cReturnTest.c_str();
		const char* testString = "testpass";
		auto compare = strcmp(cStr, testString) == 0;
		std::cout << "Validate C style string return: " << (int)compare << std::endl;
		CHECK("Test MyString return of C style string: expected: Succeeded | Result: ", strcmp(cStr, testString) == 0);
	}

	/*
		Validate that the MyString can return a std::string
	*/
	{
		MyString stdStrReturnTest("testpass");
		std::string retStr = stdStrReturnTest.toString();
		std::string testStr = "testpass";
		auto compare = testStr == retStr;
		std::cout << "Validate std string return: " << (int)compare << std::endl;
		CHECK("Test MyString return of std string: expected: Succeeded | Result: ", testStr == retStr);
	}

	std::cout << "Test runs complete..." << std::endl;
	std::string  temp;

	return 1;
}
