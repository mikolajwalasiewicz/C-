#include "bib.h"
#ifndef abc
#define abc
#include <iostream>
using namespace std;

Bryla::Bryla()
{
    bok1=1;
    bok2=1;
    bok3=1;
    cout<<"dzialam\n";
}
Bryla::Bryla(float a,float b,float c)
{
    bok1=a;
    bok2=b;
    bok3=c;
    cout<<"dzialam\n";
}
Bryla::~Bryla()
{
    cout<<"dzialam destruktor\n";
}
float Bryla::Pole()
{
    return bok1*bok2*2+bok2*bok3*2+bok1*bok3*2;
}
float Bryla::Objetosc()
{
    return bok1*bok2*bok3;
}
float Kula::Pole()
{
    return 4*3.14*bok1;
}
float Kula::Objetosc()
{
    return 3/4*3.14*bok1*bok1*bok1;
}
void Bryla::wyswietl()
{
    cout<<bok1<<endl<<bok2<<endl<<bok3;
}
void Prostopaloscian::wyswietl()
{
    cout<<bok1<<endl<<bok2<<endl<<bok3;
}
void Kula::wyswietl()
{
    cout<<bok1;
}
float Prostopaloscian::zmien_bok()
{
    cin>>bok1>>bok2>>bok3;
}
float Kula::zmien_bok()
{
    cin>>bok1;
    bok2=bok1;
    bok3=bok1;
}

#endif // abc

