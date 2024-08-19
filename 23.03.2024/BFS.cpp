#include<iostream>
#include<queue>
#include <vector>
#include <iomanip>

using namespace std;

const int IleWierzcholkow = 8;


int main()
{
    // tworzenie grafu

    vector<int>graf[IleWierzcholkow] ;
    graf[0] = {1,3,5};
    graf[1] = {2,4,6};
    graf[2] = {3,5,0};
    graf[3] = {4,6,1};
    graf[4] = {7,1};
    graf[5] = {3,4,6};
    graf[6] = {0,3,7};
    graf[7] = {1,2,4};

    cout<<endl;
    int *tab1 = new int [8];
    int *tab2 = new int [8];
    int *tab3 = new int [8];//BIALY SZARY CZARNY
    for(int i=0; i<8; i++)
    {
        tab3[i]=0;
    }
    tab1[3]=0;
    tab2[3]=-1;
    tab3[3]=1;
    queue<int> q;
    q.push(4);
    int tmp;
    while(!q.empty())
    {
         tmp=q.front();
         q.pop();
         tab3[tmp]=2;
         for(int i =0;i<graf[tmp].size();i++)
         {
             if(tab3[graf[tmp][i]]==0)
             {
                 tab3[graf[tmp][i]]=1;
                 tab1[graf[tmp][i]]=tab1[tmp]+1;
                 tab2[graf[tmp][i]]=tmp;
                 q.push(graf[tmp][i]);
             }
         }
    }
    cout<<"numer"<<setw(10)<<"dystans"<<setw(10)<<"poprzenik"<<setw(10)<<"kolor"<<endl;
    for(int i=0; i<8; i++)
    {
        cout<<i<<setw(10)<<tab1[i]<<setw(10)<<tab2[i]<<setw(10)<<tab3[i]<<endl;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
    }

    delete []tab1;
    delete []tab2;
    delete []tab3;
}

