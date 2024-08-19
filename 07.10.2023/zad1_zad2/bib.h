#include<iostream>
#include<ctime>
using namespace std;
class Studnet
{
private:
    int nr_indexu=0;
    int rok=2000;
    float stypendiom=0;
public:
    void wypisz();
    Studnet(int,int,float);
    Studnet()=default;                       //konstruktor defaultowy
    ~Studnet();                              //destruktor
    void zmiania_wysokosci_stypedium();
    float getterstypendium();
    int getrok();
    int getnr_indexu();
    float setterstypendium(float);
    int setrok(int);
    int setnr_indexu(int);

};
void Studnet::wypisz()
{
    cout<<"nr_indexu: "<<nr_indexu<<endl;
    cout<<"rok: "<<rok<<endl;
    cout<<"stypendiom: "<<stypendiom<<endl;
}
Studnet::Studnet(int a,int b,float c)        //konstruktor
{
    nr_indexu=a;
    rok=b;
    stypendiom=c;
}
Studnet::~Studnet()                           //destruktor
{
    cout<<"Usuwam dane studenta o indeksie:"<<nr_indexu;
}
void Studnet::zmiania_wysokosci_stypedium()
{
    float a;
    cout<<"zmien stypendium na :";
    cin>>a;
    stypendiom=a;
}
float Studnet::getterstypendium()
{
    return stypendiom;
}
int Studnet::getrok()
{
    return rok;
}
int Studnet::getnr_indexu()
{
    return nr_indexu;
}
float Studnet::setterstypendium(float a)
{
    stypendiom=a;
}
int Studnet::setrok(int a)
{
    rok=a;
}
int Studnet::setnr_indexu(int a)
{
    nr_indexu=a;
}
void losuj(Studnet *tab,int n)
{
    for(int i=0; i<n; i++)
    {
        tab[i].setnr_indexu(445000+rand()%336+1);
        tab[i].setrok(2020+rand()%4);
        tab[i].setterstypendium(rand()%1000);

    }
}
void suma_stypendium(Studnet *tab,int n,float &suma_s)
{
    for(int i=0; i<n; i++)
    {
        suma_s=suma_s+tab[i].getterstypendium();
    }
}
void wypisz(Studnet *tab,int n)
{
    for(int i=0; i<n; i++)
    {
         tab[i].wypisz();
    }
}
void najwyrzsze_styp(Studnet *tab,int n)
{
    float max_s=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i].getterstypendium()>=max_s)
        {
            max_s=tab[i].getterstypendium();
        }
    }
    for(int i=0; i<n; i++)
    {
        if(tab[i].getterstypendium()==max_s)
        {
            tab[i].wypisz();
        }
    }
}
int sortowanie(Studnet *tab,int n)
{

    Studnet pom;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n-i; j++)
        {
            if(tab[j-1].getterstypendium()<tab[j].getterstypendium())
            {
                pom=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=pom;

            }
       }
    }
}


