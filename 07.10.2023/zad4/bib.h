#include<iostream>
#include<cmath>
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
    double getx();
    double gety();
};
void Punkt::wypisz()
{
    cout<<"("<<x<<" "<<","<<y<<")"<<endl;
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
double Punkt::getx()
{
    return x;
}
double Punkt::gety()
{
    return y;
}
void ktora_cwiartka(Punkt *tab,int n)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i].getx()>0)
        {
            if(tab[i].gety()>0)
            {
                cout<<"Jest w I cwiartce"<<endl;
            }
            else
            {
                cout<<"Jest w IV cwiartce"<<endl;
            }
        }
        else
        {
            if(tab[i].gety()>0)
            {
                cout<<"Jest w II cwiartce"<<endl;
            }
            else
            {
                cout<<"Jest w III cwiartce"<<endl;
            }
        }
    }
}
void ktora_jest_najblziej_0(Punkt *tab,int n)
{
    double pom;
    double minimum=sqrt(pow(tab[0].getx(),2)+pow(tab[0].gety(),2));
    for(int i=0; i<n; i++)
    {
        pom=sqrt(pow(tab[i].getx(),2)+pow(tab[i].gety(),2));
        if(pom<minimum)
        {
            minimum=pom;
        }
    }
    for(int i=0; i<n; i++)
    {
        pom=sqrt(pow(tab[i].getx(),2)+pow(tab[i].gety(),2));
        if(pom==minimum)
        {
            cout<<"najblizej punktu (0,0) jest punkt: ";tab[i].wypisz();
        }
    }

}


