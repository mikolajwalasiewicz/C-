#include <iostream>
#include "bib.h"

using namespace std;
float srenida_objetosc(Bryla *tab,int n)
{
    float suma=0;
    for(int i=0;i<n;i++)
    {
        suma=suma+tab[i].Objetosc();
    }
    return suma/n;
}
int main()
{
    int n=10;
    Bryla *tab = new Bryla [n];
    cout<<srenida_objetosc(tab,n);
    delete [] tab;
}
