#include "MyString.h"
#include<iostream>
#include <cstring>
using namespace std;

int MyString::count = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length] {};

	count++;
}


MyString::MyString(int size)
{
    length = size;
    str = new char[length] {};

    count++;
}

MyString::MyString(const char* st)
{
    length = strlen(st);
    str = new char[length + 1];
    strcpy_s(str, length + 1, st);

    count++;
}

MyString::~MyString()
{
    delete[] str;
    length = 0;

    count--;
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

	count++;
}

MyString::MyString(MyString&& obj)
{
	str = obj.str;
    obj.str = nullptr;

	length = obj.length;
	obj.length = 0;
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
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen()
{
    return strlen(str);
}

void MyString::MyStrCat(MyString& b)
{
    int len_a = strlen(this->str);
    int len_b = strlen(b.str);
    char* temp = new char[len_a + len_b + 1];

    strcpy_s(temp, len_a + len_b + 1, this->str);
    strcat_s(temp, len_a + len_b + 1, b.str);

    delete[] this->str;
    this->str = temp;
    this->length = len_a + len_b;
}

void MyString::MyDelChr(char c)
{
    int keep = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) keep++;
    }


    char* temp = new char[keep + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            temp[j++] = str[i];
        }
    }

    temp[j] = '\0';

    delete[] str;
    str = temp;
    length = keep;
}

int MyString::MyStrCmp(MyString& b)
{
    int cmp = strcmp(this->str, b.str);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;
    return 0;
}

void MyString::GetCount()
{
	cout << "Count of created objects: " << count << endl;
}