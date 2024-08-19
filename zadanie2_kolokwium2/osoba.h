#ifndef osoba
#define osoba
using namespace std;
class Osoba
{
protected:
    string imie;
    int wiek;
public:
    Osoba()=default;
    Osoba(string,int);
    virtual void wypisz()const;
    void zmien_wiek(int);
    virtual ~Osoba(){cout<<"deletet osoba"<<endl;};
    friend ostream& operator <<(ostream& os,const Osoba& ob);

};
#endif // osoba
