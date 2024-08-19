#include <iostream>
#include "bib.h"

using namespace std;

int main()
{
    Prostokat a(2,3);
    cout<<a.Obwod_P()<<endl;
    cout<<a.Pole_P()<<endl;
    a.Bok_a(5);
    a.Bok_b(6);
    cout<<a.Obwod_P()<<endl;
    cout<<a.Pole_P()<<endl;
    Kwadrat b(5);
    cout<<b.Obwod_P()<<endl;
    cout<<b.Pole_P()<<endl;
}
