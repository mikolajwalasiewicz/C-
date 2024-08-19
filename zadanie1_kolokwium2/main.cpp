#include <iostream>
#include <ctime>
#include <cmath>
#include "pracownik.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    int n;
    cout<<"podaj dlugosc:";
    cin>>n;
    Osoba **tab=new Osoba*[n];
    for(int i=0;i<n;i++)
    {
        switch (rand()%2)
        {
        case 0:
            tab[i]=new Osoba("maciek",rand()%10);
            break;
        case 1:
            tab[i]=new Pracownik("maciek",rand()%10,rand()%6000 * 10.00);
            break;


        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\n-------------------------";
        cout<<"\n"<<i+1<<".\n";
        tab[i]->wypisz();
        if(Osoba *wsk = dynamic_cast<Osoba*>(tab[i]))
        {
            wsk->zmien_wiek(rand()&90+10);
        }
        if(Pracownik *wsk = dynamic_cast<Pracownik*>(tab[i]))
        {
            wsk->zmien_pensje(rand()&90+10);
        }
        cout<<endl<<"zmiany "<<endl<<endl;
        tab[i]->wypisz();
    }
    for(int i=0;i<n;i++)
        delete tab[i];
    return 0;
}
