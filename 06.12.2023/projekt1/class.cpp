#include "bib.h"
#ifndef abc
#define abc
#include <iostream>
Prostokat::Prostokat()
{
    bok1=1;
    bok2=1;
}
Prostokat::Prostokat(float a,float b)
{
    bok1=a;
    bok2=b;
}
float Prostokat::Pole_P()
{
    return bok1*bok2;
}
float Prostokat::Obwod_P()
{
    return bok1*2+bok2*2;
}
float Kwadrat::Bok_a(float a)
{
    bok1=a;
    bok2=a;
}
float Kwadrat::Bok_b(float a)
{
    bok1=a;
    bok2=a;
}
Kwadrat::Kwadrat()
{
    bok1=1;
    bok2=1;
}
Kwadrat::Kwadrat(float a)
{
    bok1=a;
    bok2=a;
}

float Prostokat::Bok_a(float a)
{
    bok1=a;
}
float Prostokat::Bok_b(float a)
{
    bok2=a;
}
void Prostokat::wyswietl()
{
    std::cout<<bok1<<std::endl;
    std::cout<<bok2<<std::endl;
}

#endif
