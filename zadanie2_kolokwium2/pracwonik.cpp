#include <iostream>
#include "pracownik.h"
Pracownik::Pracownik(string a,int b,double c)
    :Osoba(a,b),pensja{c}
{}
void Pracownik::wypisz()const
{
    cout<<"nazwisko: "<<this->imie<<endl<<"wiek: "<<this->wiek<<endl;
    cout<<"pensja: "<<this->pensja<<endl;
}
void Pracownik::zmien_pensje(double a)
{
    this->pensja=a;
}
