#ifndef osoba
#define osoba
using namespace std;
class Osoba
{
protected:
    string nazwisko;
    int wiek;
public:
    Osoba ()=default;
    Osoba (string,int);
    virtual void wypisz()const;
    virtual void zmien_wiek(int);
    virtual ~Osoba() {};
    friend ostream& operator<<(ostream& os, const Osoba& ob);

};
#endif // osoba
