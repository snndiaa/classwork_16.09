#pragma once
class MyString
{
	char* str;
	int length;
	static int count; // ���������� ��������� ��������
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();
	MyString(const MyString& obj);  // ����������� �����������
	MyString(MyString&& obj); //���������� �������� 

	void print();
	void MyStrcpy(MyString& obj);// ����������� ����� 
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1) 
	int MyStrLen();// ���������� ����� ������ 
	void MyStrCat(MyString& b); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������
	int MyStrCmp(MyString& b); // ��������� ����� 

	static void GetCount(); // ����������� ����� ��� ��������� ���������� ��������� ��������
	MyString operator+(MyString& obj); // ������������
	MyString operator-(MyString& obj); // ������� ������� ������ ������ �� ������
	MyString operator*(int times); // ������ ������
	//MyString operator/(int parts); // ���������� ������

	MyString& operator+=(const char* s); 
	MyString& operator-=(const char* s);
	MyString& operator++(); // ���������� ��������� 
	MyString& operator--(); // ���������� ���������
	bool operator==(MyString& obj); // ��������� �� ���������
	bool operator>(MyString& obj); // ��������� 
};