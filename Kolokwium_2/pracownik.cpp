#include <iostream>
#include "pracownik.h"

Pracownik::Pracownik(double a,string b,int c)
    :Osoba(b,c), pensja{a}
{

}
void Pracownik::zmien_pensja(double a)
{
    pensja=a;
}
void Pracownik::wypisz() const
{
//    cout<<"nazwisko: "<<this->nazwisko<<endl;
//    cout<<"wiek: "<<this->wiek<<endl;
    cout<<"pensjsa: "<<this->pensja<<endl;
}
