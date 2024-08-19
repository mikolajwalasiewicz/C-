#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pracownik.h"
using namespace std;
int main()
{
    srand(time(nullptr));
    int n;
    cout<<"Podaj liczbe elementow: ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Bledna liczba elementow";
        return 0;
    }
    Osoba **tab=new Osoba*[n];
    for(int i=0; i<n; ++i)
        switch(rand()%2)
        {
        case 0:
            tab[i]=new Osoba("abc",(rand()%1000+1));
            break;
        case 1:
            tab[i]=new Pracownik((rand()%1000+1)/10.0,"abc",(rand()%1000+1));
            break;
        }


    for(int i=0; i<n; ++i)
    {

        cout<<"\n---------------------------------------------------------";
        cout<<"\n"<<i+1<<".\n";
        if(Pracownik *wsk = dynamic_cast<Pracownik*>(tab[i]))
        {
            tab[i]->wypisz();
            wsk->zmien_pensja((rand()%1000+1)/10.0);
        }
        else if(Osoba *wsk = dynamic_cast<Osoba*>(tab[i]))
        {
            cout<<*tab[i];
            wsk->zmien_wiek((rand()%1000+1)/10.0);
        }
        cout<<"\nZmiany\n";
        tab[i]->wypisz();
    }
    cout<<"\n---------------------------------------------------------\n";

    for(int i=0; i<n; ++i)
        delete tab[i];
    delete []tab;
    return 0;
}
