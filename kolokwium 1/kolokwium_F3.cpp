//dodaj konstruktor,                                                    DONE
//destruktor                                                            DONE
//oraz sta³¹ metodê wypisuj¹c¹ informacje na temat sk³adowych obiektów klasy Produkt.  DONE
//Zabroñ wywo³ywania konstruktora kopiuj¹cego oraz operatora przypisania. DONE
//Przeci¹¿ na rzecz tej klasy operator wyjœcia.                            DONE
#include<iostream>
#include<cmath>
using namespace std;
class Produkt
{
    static int licznik;
    const int identyfikator=licznik;
    double cena;
    Produkt(const Produkt& other)
    {
        //nic nie da sie zrobic
    }
    Produkt& operator = (const Produkt& other)
    {
        //nic nie da sie zrobic
    }
public:
    Produkt(double aaa)
    {
        cena=aaa;
        cout<<identyfikator;
        licznik++;
    }
    ~Produkt()
    {
        //if(licznik>0)licznik--;

    }
    const void wypisz()
    {
        cout<<identyfikator;
        cout<<cena;
    }
    friend ostream& operator << (ostream& wyjcie,const Produkt& other)
    {
       wyjcie<<other.identyfikator<<other.cena;
       return wyjcie;
    }
};
int Produkt::licznik=0;
int main()
{
    Produkt a(5);
    Produkt b(6);
    Produkt c(7);
    Produkt d(8);
    //a.wypisz();
    //a=b;
    cout<<a;
}
