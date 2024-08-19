#include<iostream>
using namespace std;
class pracownik
{
private:
    string nazwisko;
    int staz_pracy;     //w godzinach
    float miesieczne_wynagrodzenie_netto;
    float dodatki;
    float potracenia;
    float kwote_do_wyplaty;
public:
    pracownik(string,int,float,float,float);
    ~pracownik();
    friend ostream& operator<<(ostream&,const pracownik);
    dodaj(float);
    odejmij(float);

};


