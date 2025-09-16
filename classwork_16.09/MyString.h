#pragma once
class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();
	MyString(const MyString& other);  // ����������� �����������

	void print();
	void MyStrcpy(MyString& obj);// ����������� ����� 
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1) 
	int MyStrLen();// ���������� ����� ������ 
	void MyStrCat(MyString& b); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������
	int MyStrCmp(MyString& b); // ��������� ����� 
};

