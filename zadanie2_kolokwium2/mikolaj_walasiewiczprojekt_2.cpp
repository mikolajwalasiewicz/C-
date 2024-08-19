#include <iostream>
using namespace std;
void najwieksza_suma_podzbioru(int tab[],int n)
{

    int* pom = new int[n];
    bool* isgood = new bool[n];

    pom[0] = tab[0];
    isgood[0] = true;

    if (tab[1] > tab[0])
    {
        pom[1] = tab[1];
        isgood[1] = true;
    }
    else
    {
        pom[1] = tab[0];
        isgood[1] = false;
    }

    for (int i = 2; i < n; ++i)
    {
        if (pom[i - 2] + tab[i] > pom[i - 1])
        {
            pom[i] = pom[i - 2] + tab[i];
            isgood[i] = true;
        }
        else
        {
            pom[i] = pom[i - 1];
            isgood[i] = false;
        }
    }
    for (int i=n; i>=0; i--)
    {
        if (isgood[i]==1)
        {
            cout<<tab[i]<<" ";
            i--;
        }
    }
}
int main()
{
    int n=100;
    int *tab= new int [n];
    for (int i = 0; i < n; ++i)
    {
        tab[i]=i+1;
    }
    cout<<"Najwieksza suma: ";
    najwieksza_suma_podzbioru(tab,n);
    return 0;
}
