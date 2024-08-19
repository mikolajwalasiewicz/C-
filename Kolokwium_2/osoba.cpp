#include <iostream>
#include "osoba.h"
Osoba::Osoba(string a,int b)
{
    this->nazwisko=a;
    this->wiek=b;
}
void Osoba::wypisz () const
{
    cout<<"nazwisko: "<<this->nazwisko<<endl;
    cout<<"wiek: "<<this->wiek<<endl;
}
void Osoba::zmien_wiek(int b)
{
    this->wiek=b;
}
ostream& operator<<(ostream& os, const Osoba& ob)
{
    os<<"nazwisko: "<<ob.nazwisko<<"\n";
    os<<"wiek: "<<ob.wiek<<"\n";
    return os;
}
