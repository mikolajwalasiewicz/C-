#include "bib.h"

using namespace std;

int main()
{
    bank_accout a{},b("MACIEK","WALAS",10001,20,1000);
    a.wplacanie(100);
    a.wyplacanie(100);
    a.odsetki();
    a.wypisz();
    cout<<endl;
    b.odsetki();
    b.wypisz();
}
