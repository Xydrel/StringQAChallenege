
//Includes---------------------------------------------------------------------
#include "MyString.h"


//Implementation---------------------------------------------------------------
MyString::MyString()
{
    _s = nullptr;
}

MyString::~MyString()
{
    if (_s != nullptr)
        free(_s);
}

MyString::MyString(const char* other)
{
    _s = nullptr;

    operator = (other);
}

MyString::MyString(const MyString& other)
{
    _s = nullptr;

    operator = (other);
}

const char* MyString::c_str() const
{
    return _s;
}

bool MyString::empty() const
{
    return _s == nullptr;
}

void MyString::clear()
{
    if (_s != nullptr)
    {
        free(_s);
        _s = nullptr;
    }
}

/*
	This method was attempting to return the length of _s property 
	without performing any validation on it which can result in attempting
	to access uninitialized property and causing application execution halt.
	Te method now performs a validation on the property for nullptr and returns
	0 if the property is nullptr.
*/
size_t MyString::length() const
{
	if (_s != nullptr)
	{
		return strlen(_s);
	}
	else
	{
		return 0;
	}
}

MyString& MyString::operator = (const char* other)
{
    if (_s != nullptr)
        free(_s);

    auto length = strlen(other);
    _s = static_cast<char*>(malloc(length + 1));
    memcpy(_s, other, length);
    _s[length] = 0;

    return *this;
}

MyString& MyString::operator = (const MyString& other)
{
    if (_s != nullptr)
        free(_s);

    auto length = other.length();
    _s = static_cast<char*>(malloc(length + 1));
    memcpy(_s, other._s, length);
    _s[length] = 0;

    return *this;
}

bool MyString::operator == (const char* other) const
{
    auto otherLength = strlen(other);
    return length() == otherLength && memcmp(_s, other, length()) == 0;
}

bool MyString::operator == (const MyString& other) const
{
    return length() == other.length() && memcmp(_s, other._s, length()) == 0;
}

MyString MyString::operator + (const char* other) const
{
    MyString copy(*this);
    copy += other;
    return copy;
}

MyString& MyString::operator += (const char* other)
{
    auto currentLength = length();
    auto otherLength = strlen(other);
    auto newLength = currentLength + otherLength;

    MyString concatenated;
    concatenated._s = static_cast<char*>(malloc(newLength + 1));
    memcpy(concatenated._s, _s, currentLength);
    memcpy(concatenated._s + currentLength, other, otherLength);
    
    operator = (concatenated);
    
    return *this;
}

MyString MyString::operator + (const MyString& other) const
{
    auto copy = *this;
    copy += other;
    return copy;
}

MyString& MyString::operator += (const MyString& other)
{
    auto currentLength = length();
    auto otherLength = other.length();
    auto newLength = currentLength + otherLength;

    MyString concatenated;
    concatenated._s = static_cast<char*>(malloc(newLength + 1));
    memcpy(concatenated._s, _s, currentLength);
    memcpy(concatenated._s + currentLength, other._s, otherLength);

    operator = (concatenated);

    return *this;
}

std::string MyString::toString() const
{
    return std::string(_s);
}
