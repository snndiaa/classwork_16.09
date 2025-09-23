#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    MyString s1("Arina");
    MyString s2("Vanya");

    s1.print();
    s2.print();

    MyString s3 = s1;
    s3.print();

    if (s1.MyStrStr("ri")) 
    {
        cout << "Substring found in Arina\n";
    }
    else
    {
        cout << "Substring not found in Arina\n";
    }

    cout << "Index of 'n' in Vanya: " << s2.MyChr('n') << endl;

    cout << "Length of Arina: " << s1.MyStrLen() << endl;

    s1.MyStrCat(s2);
    cout << "After concatenation: ";
    s1.print();

    s1.MyDelChr('a');
    cout << "After deleting 'a': ";
    s1.print();

    int cmp = s2.MyStrCmp(s3);
    if (cmp == 0)
    {
        cout << "Vanya == Arina\n";
    }
    else if (cmp < 0)
    {
        cout << "Vanya < Arina\n";
    }
    else
    {
        cout << "Vanya > Arina\n";
    }

    MyString::GetCount();

    MyString a("Hello");
    MyString b("lo");

    MyString c = a + b;
    cout << "a + b = ";
    c.print();

    MyString d = a - b;
    cout << "a - b = ";
    d.print();

    MyString e = a * 3;
    cout << "a * 3 = ";
    e.print();

    MyString f = a / 2;
    cout << "a / 2 = ";
    f.print();

    return 0;
}