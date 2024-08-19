#include <iostream>
using namespace std;
class Pacjent
{
private:
    int numer_identyfikacyjny=000000;
    float waga=0;
    float wzrost=0;
public:
    Pacjent(int,float,float);
    Pacjent()=default;
    ~Pacjent();
    void wypisz();
    void ustaw_wage();
    friend ostream& operator<<(ostream&,const Pacjent&);
};
Pacjent::Pacjent(int a,float b,float c)
:numer_identyfikacyjny(a),waga(b),wzrost(c){}

Pacjent::~Pacjent()
{
    cout<<"usuwam studenta o danych :"<<endl;
    cout<<"numer_identyfikacyjny="<<numer_identyfikacyjny<<" waga="<<waga<<"  wzrost="<<wzrost<<endl;
}
void Pacjent::ustaw_wage()
{
    cin>>waga;
}
void Pacjent::wypisz()
{
    cout<<"numer_identyfikacyjny="<<numer_identyfikacyjny<<" waga="<<waga<<"  wzrost="<<wzrost<<endl;
}
ostream& operator<<(ostream& wyjscie,const Pacjent& wej)
{
   wyjscie<<wej.numer_identyfikacyjny<<endl;
   wyjscie<<wej.waga<<endl;
   wyjscie<<wej.wzrost<<endl;
}
