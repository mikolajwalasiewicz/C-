#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
template<typename typ>
typ zamien (typ *a,typ *b)
{
    int pom=a[0];
    for(int i=0;i<8;i++)
    {
        a[i]=b[i];
        b[i]=pom;
        pom=a[i+1];
    }
}
template<typename typ1>
void losuj(typ1 *tab)
{
    for (int i=0;i<8;i++)
    {
        tab[i]=rand()%10;
    }
}
template<typename typ1>
void wypisz(typ1 *tab)
{
    int j=0;
    int o=0;
    for (int i=0;i<8;i++)
    {
        cout<<tab[i];
        j++;
        o++;
        if(j==2)
        {
            cout<<" ";
        }
        if(o==4)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int *tab1=new int [8];
    int *tab2=new int [8];
    int *tab3=new int [8];
    char *tab4=new char [8];
    char *tab5=new char [8];
    char *tab6=new char [8];
    losuj<int>(tab1);
    losuj<int>(tab2);
    losuj<int>(tab3);
    wypisz<int>(tab1);
    wypisz<int>(tab2);
    wypisz<int>(tab3);
    zamien<int>(tab1,tab3);
    cout<<endl;
    wypisz(tab1);
    wypisz (tab2);
    wypisz (tab3);

    losuj<char>(tab4);
    losuj<char>(tab5);
    losuj<char>(tab6);

    wypisz<char>(tab4);
    wypisz<char>(tab5);
    wypisz<char>(tab6);
}
