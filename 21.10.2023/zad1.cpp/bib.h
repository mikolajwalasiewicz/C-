#include <cstring>
using namespace std;
pracownik::pracownik(string a,int b,float c,float d,float e)
{
    nazwisko=a;
    staz_pracy=b;     //w godzinach
    miesieczne_wynagrodzenie_netto=c;
    dodatki=d;
    potracenia=e;
    kwote_do_wyplaty=c+d+e;

}
pracownik::~pracownik()
{
    cout<<"pracownik: "<<nazwisko<<endl<<" zostal usuniety"<<endl;
}
ostream& operator<<(ostream &wyjscie,const pracownik arg)
{
    return wyjscie<<arg.nazwisko<<" "<<arg.staz_pracy<<" "<<arg.miesieczne_wynagrodzenie_netto<<" "<<arg.dodatki<<" "<<arg.potracenia<<" "<<arg.kwote_do_wyplaty<<endl;
}
pracownik::dodaj(float a)
{
    dodatki=dodatki+a;
    kwote_do_wyplaty=kwote_do_wyplaty+a;
}
pracownik::odejmij(float a)
{
    potracenia=potracenia+a;
    kwote_do_wyplaty=kwote_do_wyplaty-a;
}
