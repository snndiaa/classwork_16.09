#include "MyString.h"
#include<iostream>
#include <cstring>
using namespace std;

MyString::MyString()
{
    length = 80;
    str = new char[length] {};
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length] {};
}

MyString::MyString(const char* st)
{
    length = strlen(st);
    str = new char[length+1];
    strcpy_s(str, length + 1, st);
}

MyString::~MyString()
{
    delete[] str;
    length = 0;
}

void MyString::print()
{
    cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
    if (this == &obj)
    {
        return;
    }
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);
}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);
    if (s != nullptr)
    {
        return true;
    }
	return false;
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == c) return i;
    }   
    return -1;
}

int MyString::MyStrLen()
{
    return static_cast<int>(strlen(str));
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);
} 
