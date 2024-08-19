#include<iostream>
using namespace std;
struct ulamek
{
    int licznik;
    int mianownik;
};
void wypisz(ulamek x)
{
    cout<<x.licznik<<"/"<<x.mianownik;
}
ulamek suma(ulamek x,ulamek y)
{
    ulamek z;
    z.licznik=(x.licznik*y.mianownik)+(y.licznik*x.mianownik);
    z.mianownik=x.mianownik*y.mianownik;

    return z;
}
int main()
{
    ulamek u1;
    cout<<"Podaj ulamek u1 \n---------------------\n";
    cout<<"Podaj licznik: ";
    cin>>u1.licznik;
    cout<<"Podaj mianownik: ";
    cin>>u1.mianownik;
    wypisz(u1);
    cout<<endl;
    ulamek u2;
    cout<<"Podaj ulamek u2 \n---------------------\n";
    cout<<"Podaj licznik: ";
    cin>>u2.licznik;
    cout<<"Podaj mianownik: ";
    cin>>u2.mianownik;
    wypisz(u2);
    ulamek u3 = suma(u1,u2);
    cout<<"\n---------------------\n";
    wypisz(u1);
    cout<<" + ";
    wypisz(u2);
    cout<<" = ";
    wypisz(u3);
    cout<<"\n---------------------\n";


}
