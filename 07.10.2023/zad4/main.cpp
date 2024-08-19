#include "bib.h"

using namespace std;

int main()
{
    int n=2;
    //Punkt obiekt1{5,20};
    //obiekt1.wypisz();
    //Punkt obiekt2{};
    //obiekt2.wypisz();
    Punkt *tab = new Punkt[n];
    for(int i=0;i<n;i++)
    {
        tab[i].pobierz();
    }
    system("CLS");
    for(int i=0;i<n;i++)
    {
        tab[i].wypisz();
    }
    ktora_cwiartka(tab,n);
    ktora_jest_najblziej_0(tab,n);
    delete[]tab;
}

