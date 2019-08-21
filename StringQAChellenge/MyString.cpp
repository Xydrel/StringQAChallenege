
//Includes---------------------------------------------------------------------
#include "MyString.h"


//Implementation---------------------------------------------------------------
MyString::MyString()
{
    _s = nullptr;
}

/*
	Destructing the object however my knowledge of the internal working of free and malloc are limited
	I know in cases the destructor are not called. I would prefer using again more modern C++ if applicable.
*/
MyString::~MyString()
{
    if (_s != nullptr)
        free(_s);
}

/*
	MOD: Added validation on the other input as the call to 
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
	

	MOD: Added validation on the other input for empty as the call to
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

/*
	Returns a const pointer to the internal data, this is good as the returned
	data can not be modified.
*/
const char* MyString::c_str() const
{
	return _s;
}

/*
	Returns the comparison of the member and nullptr to inform the caller if the 
	internal data is empty or not. Another way of going about this could have been
	to use the length method and if that returns a 0 then the internal string is empty.
*/
bool MyString::empty() const
{
    return _s == nullptr;
}

/*
	Checks that the internal data is not null and if not frees the allocated 
	memory and sets it to nullptr. This is old style C programming and I would 
	take advantage of delete[] and delete in these cases using more modern C++.
*/
void MyString::clear()
{
    if (_s != nullptr)
    {
        free(_s);
        _s = nullptr;
    }
}

/*
	MOD: This method was attempting to return the length of _s property 
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

/*
	This method is performing the allocation and assignment of the incoming string to this object.
	This method is using C style calls to free and malloc and perhaps using more modern methods of C++
	would be better if they are usable.
*/
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

/* 
	This method is performing the assignment from another MyString instead of like above taking in a C 
	style string.

	Same feedback as above, I can't really think of a better way of doing these assignments other then
	using more modern C++ features. 
*/
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
	MOD: Added a validation on the input before attempting to operate on it 
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
	MOD: Added validation on the other input for empty as well as a test for 
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
	MOD: Adding validation on the input as to not perform construction procedures when not needed
	This method utilizes the MyString operator overloads to perform the concatenation of 
	the incoming c style string and the copy of this string.
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
	MOD: Added validation to other input as there are operations performed on it which can result
	with application execution halt or unexpected termination.

	BUG FIX: corrected the use of memcpy by adding 1 to the length for the null
	character at the end of the string to be returned
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
		memcpy(concatenated._s + currentLength, other, otherLength + 1);

		operator = (concatenated);
	}
    
    return *this;
}

/*
	MOD: Adding validation on the input as to not perform construction procedures when not needed
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
	MOD: Added validation to other input as there are operations performed on it which can result
	with application execution halt or unexpected termination.

	BUG FIX: Also: corrected the use of memcpy by adding 1 to the length for the null 
	character at the end of the string to be returned
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
		memcpy(concatenated._s + currentLength, other._s, otherLength + 1);

		operator = (concatenated);
	}

    return *this;
}

/*
	Returns a new std::string being cunstructed from the internal data.
*/
std::string MyString::toString() const
{
    return std::string(_s);
}
