#include<iostream>
#include "class.cpp"
#include "bib.h"
#include<string>
using namespace std;

int main()
{
    pracownik a("adam",180,4000,3,4);
    cout<<a<<endl;
    a.dodaj(100);
    cout<<a<<endl;
    a.odejmij(100);
    cout<<a<<endl;
}
