#include<iostream>
using namespace std;
class Punkt
{
private:
    double x=1;
    double y=5;
public:
    void wypisz();
    void pobierz();
    Punkt(double,double);
    Punkt()=default;
    ~Punkt();
};
void Punkt::wypisz()
{
    cout<<"x="<<x<<" "<<"y="<<y<<endl;
}
Punkt::Punkt(double a,double b)
{
    x=a;
    y=b;
}
Punkt::~Punkt()
{
    cout<<"usuniete";
}
void Punkt::pobierz()
{
    int a,b;
    cout<<"x=";
    cin>>a;
    x=a;
    cout<<"y=";
    cin>>b;
    y=b;
}
int main()
{
    //Punkt obiekt1{5,20};
    //obiekt1.wypisz();
    //Punkt obiekt2{};
    //obiekt2.wypisz();
    Punkt *tab = new Punkt[2];
    for(int i=0;i<2;i++)
    {
        tab[i].pobierz();
    }
    for(int i=0;i<2;i++)
    {
        tab[i].wypisz();
    }
    delete[]tab;
}
