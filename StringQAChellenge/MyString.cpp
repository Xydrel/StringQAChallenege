
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

/*
	Added validation on the other input as the call to 
	operator = is additional work to allocate memory for the 
	string which is not needed since an empty or null value 
	is being passed in.
*/
MyString::MyString(const char* other)
{
    _s = nullptr;

	if (other != nullptr)
	{
		operator = (other);
	}
}

/*
	Added validation on the other input for empty as the call to
	operator = is additional work to allocate memory for the
	string which is not needed since an empty or null value
	is being passed in.
*/
MyString::MyString(const MyString& other)
{
    _s = nullptr;

	if (!other.empty())
	{
		operator = (other);
	}
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

/*
	Added a validation on the input before attempting to operate on it 
	to prevent application halt or unexpected termination.
*/
bool MyString::operator == (const char* other) const
{
	if (length() > 0 && other != nullptr)
	{
		auto otherLength = strlen(other);
		return length() == otherLength && memcmp(_s, other, length()) == 0;
	}
	else if (length() <= 0 && other == nullptr)
	{
		return true;
	}

	return false;
}

/*
	Added validation on the other input for empty as well as a test for 
	if this string is empty and the other string is empty true is 
	returned because both strings are effectively the same.
*/
bool MyString::operator == (const MyString& other) const
{
	if (!other.empty())
	{
		return length() == other.length() && memcmp(_s, other._s, length()) == 0;
	}
	else if (this->empty() && other.empty())
	{
		return true;
	}

	return false;
}

/*
	Adding validation on the input as to not perform construction procedures when not needed
*/
MyString MyString::operator + (const char* other) const
{
	if (other != nullptr)
	{
		MyString copy(*this);
		copy += other;
		return copy;
	}

	return *this;
}

/*
	Added validation to other input as there are operations performed on it which can result
	with application execution halt or unexpected termination.
*/
MyString& MyString::operator += (const char* other)
{
	if (other != nullptr)
	{
		auto currentLength = length();
		auto otherLength = strlen(other);
		auto newLength = currentLength + otherLength;

		MyString concatenated;
		concatenated._s = static_cast<char*>(malloc(newLength + 1));
		memcpy(concatenated._s, _s, currentLength);
		memcpy(concatenated._s + currentLength, other, otherLength);
    
		operator = (concatenated);
	}
    
    return *this;
}

/*
	Adding validation on the input as to not perform construction procedures when not needed
*/
MyString MyString::operator + (const MyString& other) const
{
	if (!other.empty())
	{
		auto copy = *this;
		copy += other;
		return copy;
	}

	return *this;
}

/*
	Added validation to other input as there are operations performed on it which can result
	with application execution halt or unexpected termination.
*/
MyString& MyString::operator += (const MyString& other)
{
	if (!other.empty())
	{
		auto currentLength = length();
		auto otherLength = other.length();
		auto newLength = currentLength + otherLength;

		MyString concatenated;
		concatenated._s = static_cast<char*>(malloc(newLength + 1));
		memcpy(concatenated._s, _s, currentLength);
		memcpy(concatenated._s + currentLength, other._s, otherLength);

		operator = (concatenated);
	}

    return *this;
}

std::string MyString::toString() const
{
    return std::string(_s);
}
