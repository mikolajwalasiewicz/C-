#include <iostream>
#ifndef BIB_H
#define BIB_H
#include "class.cpp"
using namespace std;

class Osoba
{
protected:
    string nazwisko;
    int wiek;
public:
    Osoba ()=default;
    void wypisz();
    virtual ~Osoba(){};

};
class Pracownik : public Osoba
{

};
void Osoba::wypisz()
{
    cout<<"nazwisko: "<<this->nazwisko<<endl;
    cout<<"wiek: "<<this->wiek<<endl;
}
#endif // BIB_H
