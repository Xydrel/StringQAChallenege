#pragma once


//Includes---------------------------------------------------------------------
#include <string>
#include <vector>


//Types------------------------------------------------------------------------
class MyString
{
public:
    MyString(); //Default constructor
    ~MyString(); //Destructor
    MyString(const char* other); //Constructor. Constructs MyString from a C-string.
    MyString(const MyString& other); //Constructor. Constructs MyString from a MyString.

    const char* c_str() const; //Returns pointer to a C-string.

    bool empty() const; //Determines whether the string is empty.
    void clear(); //Clears the string.

    size_t length() const; //Returns the length of the string, not counting the null terminator.

    MyString& operator = (const char* other); //Assignment. Copies the C-string into 'this'.
    MyString& operator = (const MyString& other); //Assignment. Copies the MyString into 'this'.

    bool operator == (const char* other) const; //Equality test. Tests the string against a C-string. If they are equal, returns true. Otherwise, returns false.
    bool operator == (const MyString& other) const; //Equality test. Tests the string against a MyString. If they are equal, returns true. Otherwise, returns false.

    MyString operator + (const char* other) const; //Creates a MyString that contains the concatenation of 'this' and the 'other' C-string.
    MyString& operator += (const char* other); //Concatenates onto 'this', the 'other' C-string.

    MyString operator + (const MyString& other) const; //Creates a MyString that contains the concatenation of 'this' and 'other'.
    MyString& operator += (const MyString& other); //Concatenates onto 'this', the 'other' MyString.

    std::string toString() const; //Creates a std::string

private:
    char* _s; //Internal C-string
};
