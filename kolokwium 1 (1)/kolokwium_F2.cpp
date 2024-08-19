//dodaj konstruktor,                                                    DONE
//destruktor,                                                           DONE
//konstruktor kopiuj¹cy,                                                DONE
//operator przypinania                                                  DONE
//oraz metodê wypisuj¹c¹ informacje na temat obiektów klasy Moja        DONE
#include<iostream>
#include<cmath>
using namespace std;
class Moja
{
private:
    int a;
    double* b;
public:
    Moja(int aa,double *bb):a(aa),b(bb) {};
    ~Moja()
    {
        if(b!=nullptr)
            delete b;
        cout<<"\nusuniety";
    };
    Moja(const Moja &other)
    {
        b=new double [other.a];
        a=other.a;
        for (int i=0; i<a; i++)
        {
            b[i]=other.b[i];
        }
    }
    void wypisz()
    {
        cout<<a;
        for (int i=0; i<a; i++)
        {
            cout<<b[i];
        }
    }
    Moja& operator = (const Moja& other)
    {
        b=new double [other.a];
        a=other.a;
        for (int i=0; i<a; i++)
        {
            b[i]=other.b[i];
        }
    }
};
int main()
{
    double *abc= new double [5];
    for (int i=0; i<5; i++)
    {
        abc[i]=i+100;
    }
    Moja a(5,abc);
    double *abc1= new double [5];
    for (int i=0; i<5; i++)
    {
        abc1[i]=i+2;
    }
    Moja b(5,abc1);
    //Moja b(a);
    b=a;
    a.wypisz();
    b.wypisz();
    return 0;
}
