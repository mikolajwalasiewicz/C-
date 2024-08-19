#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

const int limit_miast=30;
const int K=(limit_miast*(limit_miast-1))/2;

struct edge
{
    int from;
    int to;
    float len;
    edge * next;
    bool wybrana;
};
edge* krawedzie[(limit_miast*(limit_miast-1))/2];

void Add(edge*& h, int _to, float _len)
{
    edge* temp = new edge;
    temp->to = _to;
    temp->len = _len;
    temp->next = h;
    h = temp;
}

struct miasto
{
    float x, y; // reprezentacja punktu na p≥aszczyünie
    string nazwa;
    edge *sasiedzi;

    miasto(string _nazwa, float _x, float _y)
    {
        x=_x;
        y=_y;
        nazwa = _nazwa;
    }
};

miasto* M[2318];

float dist(miasto A, miasto B)
{
    return sqrt(pow(A.x - B.x,2)+pow(A.y - B.y,2))*100;
}

void WypelnianieMiast()
{
    ifstream Wodczyt("Miasta5.txt");
    string wiersz;
    int i = 0;
    while (!Wodczyt.eof() && i < limit_miast)
    {
        getline(Wodczyt,wiersz);
        string str2 = wiersz.substr (0, wiersz.find('#'));
        wiersz = wiersz.substr (wiersz.find('#')+1);
        string str3 = wiersz.substr (0, wiersz.find('#'));
        wiersz = wiersz.substr (wiersz.find('#')+1);
        string str4 = wiersz.substr (0, 100);
        //cout << str2 << '\n' << str3 << '\n' << str4 << '\n';
        M[i]= new miasto(str2,stof(str3),stof(str4));
        i++;
    }
    Wodczyt.close();
}
int *kolory = new int [limit_miast];
void WypelnianieKrawedzi()
{
    for(int i=0; i<limit_miast; i++)
    {
        int z = 0;
        //cout<<M[i]->nazwa;
        for(int j=i+1; j<limit_miast; j++)
        {
            float D = dist(*M[i],*M[j]);
            edge* e = new edge;
            e->from=i;
            e->to=j;
            e->len=D;
            krawedzie [z]=e;
            kolory[z]=
            z++;
        }
    }
}

float E(int droga[], int ile)
{
    float s = 0;
    for(int i=0; i<ile-1; i++) s += dist(*M[droga[i]], *M[droga[i+1]]);
    s+= dist(*M[droga[0]], *M[droga[ile-1]]);
    return s;
}


void Wypisz_Krawedzie()
{
    //for(int i=0; i<ile; i++) cout<<M[droga[i]]->nazwa<<", ";
    for(int i=0; i<limit_miast; i++)
    {
        cout<<krawedzie[i]->from<<endl;
        cout<<krawedzie[i]->to<<endl;
        cout<<krawedzie[i]->len<<endl;
        cout<<endl;

    }
}

void Sortuj()
{
    edge* tmp;
    for (int i=0; i<28; i++)
    {
        for(int j=0; j<28; j++)
        {
            if(krawedzie[j]->len > krawedzie[j+1]->len)
            {
                tmp = krawedzie[j];
                krawedzie[j]= krawedzie[j+1];
                krawedzie[j+1]=tmp;
            }

        }
    }
}
void Lacz_krawedzie()
{
    int idx = 0;
    int ileWybranych = 0;
    while(ileWybranych<limit_miast-1)
    {
        int f = krawedzie[idx]->from;
        int t = krawedzie[idx]->from;
        int kf = kolory[f];
        int kt = kolory[t];
        if(kt!=kf)
        {
            krawedzie[idx]->wybrana;
            for(int p=0;p<limit_miast;p++)
            {
                if(kolory[p]==kf)
                {
                    kolory[p]=kt;
                }
                ileWybranych++;
            }
        }

    }
}
int main()
{
    int num = 438;
    WypelnianieMiast();
    //cout<<M[num]->nazwa<<"      "<<M[num]->x<<"      "<<M[num]->y<<endl;
    WypelnianieKrawedzi();
    //Wypisz_Krawedzie();
    Sortuj();
    Wypisz_Krawedzie();
    Lacz_krawedzie();
    for(int i=0;i<limit_miast;i++)
    {
        cout<<kolory[i]<<endl;
    }


}


