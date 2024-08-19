#ifndef pracownik
#define pracownik
#include "osoba.h"
using namespace std;
class Pracownik : public Osoba
{
protected:
    double pensja;
public:
    Pracownik(double,string,int);
    void zmien_pensja(double);
    void wypisz()const override;
    ~Pracownik() {cout<<"Deleted Pracownik";};
};
#endif // pracownik
