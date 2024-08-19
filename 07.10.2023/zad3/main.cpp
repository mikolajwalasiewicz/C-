#include "bib.h"

using namespace std;

int main()
{
    srand(time(NULL));
    cout<<"Podaj liczbe uczestnikow :";
    int n=1;
    cin>>n;
    system("CLS");
    user *tab = new user [n];
    for(int i=0;i<n;i++)
    {
        tab[i].setkod(i+1);
    }
    for(int i=0;i<n;i++)
    {
        tab[i].wyswietl();
    }
}
