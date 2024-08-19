#include <iostream>
#include "osoba.h"
    Osoba::Osoba(string a,int b)
    {
        this->imie=a;
        this->wiek=b;
    }
    void Osoba::wypisz()const
    {
        cout<<"nazwisko: "<<this->imie<<endl<<"wiek: "<<this->wiek<<endl;
    }
    void Osoba::zmien_wiek(int c)
    {
        this->wiek=c;
    }
    ostream& operator <<(ostream& os,const Osoba& ob)
    {
        os<<"nazwisko: "<<ob.imie<<"\n";
        os<<"wiek: "<<ob.wiek<<"\n";
        return os;

    }
