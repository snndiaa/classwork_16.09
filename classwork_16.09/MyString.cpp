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

MyString::MyString(const MyString& obj) 
{
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);

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

MyString MyString::operator+(MyString& obj)
{
    MyString temp;
    delete[] temp.str;
    temp.length = this->length + obj.length;
    temp.str = new char[temp.length + 1];
    strcpy_s(temp.str, this->length + 1, this->str);
    strcat_s(temp.str, temp.length + 1, obj.str);
    return temp;
}

MyString MyString::operator-(MyString& obj)
{
    MyString temp(*this);

    for (int i = 0; i < obj.length; i++)
    {
        temp.MyDelChr(obj.str[i]);
    }
    return temp;
}

MyString MyString::operator*(int times)
{
    if (times <= 0)
    {
        return MyString("");
    }
    MyString temp;
    delete[] temp.str;
    temp.length = this->length * times;
    temp.str = new char[temp.length + 1];
    temp.str[0] = '\0';

    for (int i = 0; i < times; i++)
    {
        strcat_s(temp.str, temp.length + 1, this->str);
    }
    return temp;
}

//MyString MyString::operator/(int parts)
//{
//    if (parts <= 0)
//    {
//        return MyString("");
//    }
//
//    int newLen = this->length / parts;
//    if (newLen < 0)
//    {
//        newLen = 0;
//    }
//
//    MyString temp;
//    delete[] temp.str;
//    temp.length = newLen;
//    temp.str = new char[newLen + 1];
//    strncpy_s(temp.str, newLen + 1, this->str, newLen);
//    temp.str[newLen] = '\0';
//
//    return temp;
//}

MyString& MyString::operator+=(const char* s)
{
    int add_len = strlen(s);
	char* temp = new char[length + add_len + 1];

	strcpy_s(temp, length + 1, str);
    strcat_s(temp, length + add_len + 1, s);

	delete[] str;
	str = temp;
	length += add_len;
	return *this;   
}

MyString& MyString::operator-=(const char*s)
{
	int remove_len = strlen(s);
    for (int i = 0; i < remove_len; i++)
    {
		MyDelChr(s[i]);
    }
	return *this;
}

MyString& MyString::operator++()
{
	char* temp = new char[length + 2];
	strcpy_s(temp, length + 2, str);
	temp[length] = ' ';
	temp[length + 1] = '\0';

    delete[] str;
	str = temp;
    length++;
	return *this;
}

MyString& MyString::operator--()
{
    if (length > 0) 
    {
		str[length - 1] = '\0';
		length--;
    }
	return *this;
}

bool MyString::operator==(MyString& obj)
{
	return strcmp(this->str, obj.str) == 0;
}

bool MyString::operator>(MyString& obj)
{
	return strcmp(this->str, obj.str) > 0;
}
