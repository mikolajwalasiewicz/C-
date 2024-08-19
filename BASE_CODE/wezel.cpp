#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
struct wezel
{
    int nr;
    wezel * next;

};
void wypisz(wezel* n)
{
    for ( ; n->next!=NULL ; n=n->next )
    {
        cout<<n<<endl;
        cout<<" - - - - - - - - - -\n " ;
        cout<<" nr = "<<setw ( 12 )<<n->nr<<" | "<<endl ;
        cout<<" - - - - - - - - - -\n " ;
        cout<<" next = "<<setw ( 10 )<<n->next<<" | "<<endl ;
        cout<<" - - - - - - - - - -\n " ;
        cout<<" | \n " ;
        cout<<" V \n " ;
    }
    cout<<" NULL \n ";

}
int main()
{
    int x;
    cout<<"aby zatrzymac daj 0 ";
    cin>>x;
    if(x==0)
    {
        cout<<"lista pusta";
    }
    else
    {
        wezel *head;
        head=new wezel;
        head->nr=0;
        head->next=NULL;
        cout<<"Podaj liczbê calokwita ";
        cin>>x;
         while(x!=0)
         {
             wezel *n;
             n=new wezel;
             n->nr=x;
             n->next=head;
             head=n;
             cin>>x;
         }
        wypisz(head);
        delete head;
    }


}
