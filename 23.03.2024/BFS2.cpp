#include<iostream>
#include<queue>
#include <vector>
#include <iomanip>

using namespace std;

const int IleWierzcholkow = 8;
 vector<int>poprz(IleWierzcholkow,-1);
    vector<int>kolor(IleWierzcholkow,0);
    vector<int>czasOdw(IleWierzcholkow,-1);
    vector<int>CzasPrzetw(IleWierzcholkow,-1);
    int czas=0;

void odwiez(int bierzacy, int poprzednik)
{
    kolor[bierzacy]=1;
    czasOdw[bierzacy]=czas++;
    for(int sasiad : graf[bierzacy])
    {
        odwiez(sasiad,bierzacy);
    }
}

int main()
{
    // tworzenie grafu

    vector<int>graf[IleWierzcholkow] ;
    graf[0] = {4};
    graf[1] = {4,5};
    graf[2] = {0};
    graf[3] = {2,4};
    graf[4] = {0,1,6};
    graf[5] = {3,6};
    graf[6] = {7};
    graf[7] = {3};

    cout<<endl;
    int *tab1 = new int [IleWierzcholkow];
    int *tab2 = new int [IleWierzcholkow];
    int *tab3 = new int [IleWierzcholkow];//BIALY SZARY CZARNY
    int *tab4 = new int [IleWierzcholkow];
    for(int i=0; i<8; i++)
    {
        tab3[i]=0;
        tab4[i]=0;
    }
    tab1[4]=0;
    tab2[4]=-1;
    tab3[4]=1;
    queue<int> q;
    q.push(4);
    int tmp;


    cout<<"numer"<<setw(10)<<"dystans"<<setw(10)<<"poprzenik"<<setw(10)<<"kolor"<<setw(10)<<"koniec"<<endl;
    for(int i=0; i<8; i++)
    {
        cout<<i<<setw(10)<<tab1[i]<<setw(10)<<tab2[i]<<setw(10)<<tab3[i]<<setw(10)<<tab4[i]<<endl;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    delete []tab1;
    delete []tab2;
    delete []tab3;
    delete []tab4;
}

