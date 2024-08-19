#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Figura
{
protected:
    double obwod{0};
public:
    Figura()=default;
    virtual void oblicz_obwod()= 0;
    virtual void wypisz() const = 0;
    virtual ~Figura(){};

};

class Prostokat : public Figura
{
protected:
    double bok1;
    double bok2;

public:
    Prostokat(double, double);
    void oblicz_obwod() override;
    virtual void wypisz() const;
    virtual void ustaw_bok1(double);
    virtual void ustaw_bok2(double);
    //virtual ~Prostokat() {}
};

class Kwadrat : public Prostokat
{
public:
    Kwadrat(double);
    void wypisz() const override;
    void ustaw_bok1(double) override;
    void ustaw_bok2(double) override;
};

class Kolo : public Figura
{
protected:
    double promien;
public:
    Kolo(double);
    void wypisz() const override;
    void oblicz_obwod() override;
    void ustaw_promien(double);

};
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
    Figura **tab=new Figura*[n];
    for(int i=0; i<n; ++i)
        switch(rand()%3)
        {
        case 0:
            tab[i]=new Prostokat((rand()%1000+1)/10.0,(rand()%1000+1)/10.0);
            break;
        case 1:
            tab[i]=new Kwadrat((rand()%1000+1)/10.0);
            break;
        case 2:
            tab[i]=new Kolo((rand()%1000+1)/10.0);
            break;
        }


    for(int i=0; i<n; ++i)
    {
        cout<<"\n---------------------------------------------------------";
        cout<<"\n"<<i+1<<".\n";
        tab[i]->wypisz();
        cout<<"\nZmiany\n";
        if(Prostokat *wsk = dynamic_cast<Prostokat*>(tab[i]))
        {
            wsk->ustaw_bok1((rand()%1000+1)/10.0);
            wsk->ustaw_bok2((rand()%1000+1)/10.0);
        }
        if(Kolo *wsk = dynamic_cast<Kolo*>(tab[i]))
        {
            wsk->ustaw_promien((rand()%1000+1)/10.0);
        }
        tab[i]->wypisz();
    }
    cout<<"\n---------------------------------------------------------\n";

    for(int i=0; i<n; ++i)
        delete tab[i];
    delete []tab;
    return 0;
}

//skladowe klasy Prostokat

Prostokat::Prostokat(double a,double b)
    :bok1{a}, bok2{b}
{
    this->oblicz_obwod();
}

void Prostokat::wypisz() const
{
    cout<<"Prostokat o bokach: "<<this->bok1<<", "<<this->bok2<<"; ";
    cout<<"obowod: "<<obwod;
}

void Prostokat::ustaw_bok1(double x)
{
    this->bok1=x;
    this->oblicz_obwod();
}

void Prostokat::ustaw_bok2(double x)
{
    this->bok2=x;
    this->oblicz_obwod();
}

//skladowe klasy Kwadrat

Kwadrat::Kwadrat(double arg)
    :Prostokat{arg,arg}
{}

void Kwadrat::wypisz() const
{
    cout<<"Kwadrat o boku: "<<this->bok1<<"; ";
    cout<<"obowod: "<<obwod;
}
void Kwadrat::ustaw_bok1(double x)
{
    bok1=x;
    bok2=x;
    this->oblicz_obwod();
}

void Kwadrat::ustaw_bok2(double x)
{
    Kwadrat::ustaw_bok1(x);
}
void Prostokat::oblicz_obwod()
{
    obwod=2*bok1+2*bok2;
}
Kolo::Kolo(double arg)
    :promien{arg}
{
    this->oblicz_obwod();
}
void Kolo::oblicz_obwod()
{
    obwod=2*3.14*promien;
}
void Kolo::wypisz() const
{
    cout<<"Kolo o promieniu: "<<this->promien<<"; ";
    cout<<"obowod: "<<obwod;
}
void Kolo::ustaw_promien(double arg)
{
    promien=arg;
    oblicz_obwod();
}

