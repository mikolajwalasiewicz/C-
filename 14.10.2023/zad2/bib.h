#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class bank_accout
{
private:
    string imie="JAN";
    string  nazwisko="KOWALSKI";
    int numer_konta=10000;
    float oprocentowanie=12;
    float saldo=1000;
public:
    void wypisz();
    bank_accout()=default;
    bank_accout(string,string,int,float,float);
    ~bank_accout();
    wplacanie(float);
    wyplacanie(float);
    odsetki();
};
bank_accout::bank_accout(string a,string b,int c,float d,float e)
{
    imie=a;
    nazwisko=b;
    numer_konta=c;
    oprocentowanie=d;
    saldo=e;
}
bank_accout::~bank_accout()
{
    cout<<"usuniete"<<endl;
}
void bank_accout::wypisz()
{
    cout<<imie<<" ";
    cout<<nazwisko<<" ";
    cout<<numer_konta<<" ";
    cout<<oprocentowanie<<" ";
    cout<<saldo<<" ";
}
bank_accout::wplacanie(float a)
{
    saldo=saldo+a;
}
bank_accout::wyplacanie(float a)
{
    saldo=saldo-a;
}
bank_accout::odsetki()
{
    saldo=saldo+saldo*(oprocentowanie/100);
}
