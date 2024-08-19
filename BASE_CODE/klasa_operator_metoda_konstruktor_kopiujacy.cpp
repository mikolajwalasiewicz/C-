#include <iostream>

/**
uzupelnic ponizszy program, o brakujaca funkcjonalnosc
Nastepnie zdefiniowac
- konstruktor kopiujacy
oraz
- kopiujacy operator przypisania
**/


using namespace std;

class MojaKlasa
{
private:
    double x;
    string y;
public:
    MojaKlasa(double,string);
    ~MojaKlasa();
    friend ostream& operator<<(ostream&,const MojaKlasa);                                                 //operator wyswietlajacy
    MojaKlasa& operator=(const MojaKlasa&);                                                               //operator porownania (musi byc metoda)
    friend void wypisz(const MojaKlasa&);
    MojaKlasa(const MojaKlasa&);                                                                         //konstruktor kopiujacy
};

int main()
{
    MojaKlasa x{12,"Hello"};
    cout<<x<<endl;

    MojaKlasa y{x};
    cout<<y<<endl;

    MojaKlasa z{99,"World"};
    y=z;
    cout<<y<<endl;

    return 0;
}

MojaKlasa::MojaKlasa(double xx,string yy)
    : x{xx}, y{yy}
{ }

MojaKlasa::~MojaKlasa()
{
    cout<<"\nDestruktor obiektu\n";
    wypisz(*this);
}

ostream& operator<<(ostream& wyjscie ,const MojaKlasa arg)
{
   return wyjscie<<arg.x<<" "<<arg.y;
}

void wypisz(const MojaKlasa &a)
{
    cout<<a.x<<" (wypisz)  "<<a.y;
}

MojaKlasa::MojaKlasa(const MojaKlasa& a):x(a.x),y(a.y){cout<<"kopiujemy";}


MojaKlasa& MojaKlasa::operator=(const MojaKlasa& wzor)
{
    cout<<"przypisanie kopjowane";
    if(this==&wzor)
    {
        return *this;
        y=wzor.y;
        x=wzor.x;
        return *this;
    }
}
