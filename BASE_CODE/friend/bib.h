#include<iostream>
using namespace std;
class Lokata
{
private:
    const double oprocentowanie;
    double kwota;
public:
    Lokata()=delete;
    Lokata(double,double);
    void wypisz()const;
    friend void wyswietl(const Lokata&);
    friend ostream& operator<<(ostream&,const Lokata&);
    friend double suma_kwot(const Lokata*,int);
};
Lokata::Lokata(double x, double y)
:oprocentowanie{x},kwota{y}{}

void Lokata::wypisz ()const
{
    cout<<"kwota= "<<kwota <<"\noprocentowanie= "<<oprocentowanie;
}
void wyswietl(const Lokata& x)
{
    cout<<"\n"<<x.oprocentowanie<<"*";
}
ostream& operator<<(ostream& wyjscie, const Lokata & wej)
{
    wyjscie<<wej.oprocentowanie<<"*****"<<wej.kwota;
}
double suma_kwot(const Lokata* tab,int a)
{
    double suma=0;
    for(int i=0;i<a;i++)
    {
        suma=suma+tab[i].kwota;
    }
    return suma;
}

