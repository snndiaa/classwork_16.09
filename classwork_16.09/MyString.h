#pragma once
class MyString
{
	char* str;
	int length;
	static int count; // количество созданных объектов
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();
	MyString(const MyString& other);  // конструктор копирования
	MyString(MyString&& obj); //контруктор переноса 

	void print();
	void MyStrcpy(MyString& obj);// копирование строк 
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1) 
	int MyStrLen();// возвращает длину строки 
	void MyStrCat(MyString& b); // объединение строк
	void MyDelChr(char c); // удаляет указанный символ
	int MyStrCmp(MyString& b); // сравнение строк 

	static void GetCount(); // статический метод для получения количества созданных объектов
	MyString operator+(MyString& other); // конкатенация
	MyString operator-(MyString& other); // удалить символы второй строки из первой
	MyString operator*(int times); // повтор строки
	MyString operator/(int parts); // укорочение строки
};