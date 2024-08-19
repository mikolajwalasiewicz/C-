#ifndef pracownik
#define pracownik
#include "osoba.h"
using namespace std;
class Pracownik : public Osoba
{
protected:
    double pensja;
public:
    Pracownik(string,int,double);
    void wypisz()const override;
    void zmien_pensje(double);
    ~Pracownik(){cout<<"deletet pracwonik"<<endl;};
};
#endif
