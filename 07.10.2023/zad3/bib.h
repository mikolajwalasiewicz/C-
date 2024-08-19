#include<iostream>
#include<ctime>
using namespace std;
class user
{
private:
    int kod=0;
    float odp1=rand()%10000/100;
    float odp2=rand()%10000/100;
    float odp3=rand()%10000/100;
    float srednia=(odp1+odp2+odp3)/3;
public:
    void wyswietl();
    user(int,float,float,float);
    ~user();
    user()=default;
    int getkod();
    float getodp1();
    float getodp2();
    float getodp3();
    int setkod(int);
    float setodp1(float);
    float setodp2(float);
    float setodp3(float);


};
user::user(int a,float b,float c,float d)
{
    kod=a;
    odp1=b;
    odp2=c;
    odp3=d;
}
void user::wyswietl()
{
    cout<<endl<<"kod="<<kod<<"  ";
    cout<<"test1="<<odp1<<"  ";
    cout<<"test2="<<odp2<<"  ";
    cout<<"test3="<<odp3<<"  ";
    cout<<"srednia="<<srednia<<endl;

}
int user::getkod()
{
    return kod;
}
float user::getodp1()
{
    return odp1;
}
float user::getodp2()
{
    return odp2;
}
float user::getodp3()
{
    return odp3;
}
int user::setkod(int a)
{
    kod=a;
}
float user::setodp1(float a)
{
    odp1=a;
}
float user::setodp2(float a)
{
    odp2=a;
}
float user::setodp3(float a)
{
    odp3=a;
}

