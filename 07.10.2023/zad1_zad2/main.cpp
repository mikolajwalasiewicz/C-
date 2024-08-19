#include "bib.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int n=10;
    Studnet * tab = new Studnet [n];
    losuj(tab,n);
    float suma_s;
    suma_stypendium(tab,n,suma_s);
    cout<<"suma stypendii= "<<suma_s<<endl;
    najwyrzsze_styp(tab,n);
    cout<<endl;
    wypisz(tab,n);
    sortowanie(tab,n);
    cout<<endl<<"posortowane"<<endl;
    wypisz(tab,n);
}
