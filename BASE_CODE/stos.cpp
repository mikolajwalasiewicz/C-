#include<iostream>
#include<cstdlib>
#include<ctime>00
using namespace std;
struct stos
{
    int nr;
    stos * next;
};
stos *top = new stos;
void push()
{
    cout<<"Podaj nr : ";
    stos *w=new stos;
    cin>> w->nr;
    (w->next)=top;
    top=w;

}
void pop()
{
    if(top!=NULL)
    {
        top=top->next;
    }

}
void wypisz_stos()
{
    cout<<endl;
    stos *t =new stos;
    if(top!=NULL)
    {
        t=top;
        while(t!=NULL)
        {
            cout<<t->nr<<endl;
            t=(t->next);
        }
        delete t;
    }
    else
    {
        cout<<"stos pusty"<<endl;
    }
    cout<<endl;
}
int main()
{
    top=NULL;
    int c=0;
    for(;;)
    {
        cout<<"1: dodaj do stosu \n2: usun ze stosu \n3: wypisz stos\n4: koniec\n Odp: ";
        cin>>c;
        if(c==1)
        {
            push();
        }
        else if(c==2)
        {
            pop();
        }
        else if(c==3)
        {
            wypisz_stos();
        }
        else
        {
            break;
        }
    }
}
