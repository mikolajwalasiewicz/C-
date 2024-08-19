//F1
//dodaj konstruktor,                                                DONE
//metodê zmieniaj¹c¹ wartoœæ pola bok,                              DONE
// sta³¹ metodê wyznaczaj¹c¹ obwód prostok¹ta,                      DONE
//przyjaciela wypisuj¹cego informacje nt. obiektów klasy Kwadrat.   DONE

//F2
//dodaj konstruktor,                                                DONE
// metodê zmieniaj¹c¹ wartoœæ pola bok,                             DONE
//sta³¹ metodê wyznaczaj¹c¹ obwód prostok¹ta,                       DONE
//przyjaciela wypisuj¹cego informacje nt. obiektów klasy Kwadrat.   DONE

//F3
// dodaj konstruktor, destruktor,
// konstruktor kopiuj¹cy,
//operator przypinania
//oraz metodê wypisuj¹c¹ informacje na temat obiektów klasy Moja
#include<iostream>
#include<cmath>
using namespace std;

class Kwadrat
{
private:
    double bok=0;
    double obwod=bok*4;
public:
    Kwadrat()=default;
    Kwadrat(double);
    ~Kwadrat();
    double Obwod()
    {
        obwod=bok*4;
        return bok*4;
    }
    friend void wypisz(const Kwadrat&);
    void setterbok(double a){bok=a,obwod=a*4;};

};
Kwadrat::Kwadrat(double a)
{
    bok=a;
    a=a*a;
    obwod=a;
}
Kwadrat::~Kwadrat()
{
    cout<<"usuniete";
}
void wypisz(const Kwadrat& k)
{
    cout<<"bok:"<<k.bok;
}
class Moja
{
private:
    int a;
    double* b;
public:
    Moja(int aa,double *bb):a(aa),b(bb) {};
    ~Moja()
    {
        delete b,cout<<"\nusuniety";
    };

};
int main ()
{
    Kwadrat a;
    a.Obwod();
}

