#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include <unistd.h>

using namespace std;
struct Player
{
    int n;
    char *name=new char [n];
    float *stats = new float[8];
};
struct Team
{
    int n=4;
    char *name=new char [n];
    Player *Team_5_Players= new Player [5];
};
struct Maches
{
    Team *Team_database_of_maches_1= new Team [16];
    Team *Team_database_of_maches_2= new Team [8];
    Team *Team_database_of_maches_3= new Team [4];
    Team *Team_database_of_maches_4= new Team [2];
    Team *Winner= new Team [1];
};
Player make_a_player(Player gracz)
{
    gracz.n=4;
    gracz.name[0]=static_cast<char>('A' + rand() % 26);
    for(int i=1; i<4; i++)
    {
        gracz.name[i]=static_cast<char>('a' + rand() % 26);
    }
    gracz.stats[1]=rand()%100;
    gracz.stats[0]=100-gracz.stats[1];
    gracz.stats[2]=rand()%100;
    gracz.stats[3]=(rand()%10000)/100;
    gracz.stats[4]=rand()%100;
    gracz.stats[5]=rand()%100;
    gracz.stats[6]=rand()%100;
    gracz.stats[7]=rand()%100;
}
void show_players_stats(Player gracz)
{
    cout<<"---Stats for 100 last rounds---"<<endl;
    cout<<"Nick: "<<gracz.name<<endl;
    cout<<"Kills: "<<gracz.stats[0]<<endl;
    cout<<"Deaths: "<<gracz.stats[1]<<endl;
    cout<<"Assists: "<<gracz.stats[2]<<endl;
    cout<<"HS %: "<<gracz.stats[3]<<endl;
    cout<<"HE Damage/round: "<<gracz.stats[4]<<endl;
    cout<<"Molly Damage/round: "<<gracz.stats[5]<<endl;
    cout<<"Movement: "<<gracz.stats[6]<<endl;
    cout<<"Positioning: "<<gracz.stats[7]<<endl;
}
void show_players_name(Player gracz)
{
    cout<<"Nick: "<<gracz.name<<endl;
}
Team make_a_team(Team Druzyna,Player *Players_batabase, int &a)
{
    Druzyna.n=4;
    Druzyna.name[0]=static_cast<char>('A' + rand() % 26);
    for(int i=1; i<Druzyna.n; i++)
    {
        Druzyna.name[i]=static_cast<char>('a' + rand() % 26);
    }
    for(int i=0; i<5; i++)
    {
        Druzyna.Team_5_Players[i] = Players_batabase [a];
        a++;
    }
}
void show_team_name(Team Druzyna)
{
    for(int i=0; i<Druzyna.n; i++)
    {
        cout<<Druzyna.name[i];
    }
}
void show_player_from_team(int p,Team *a,int v)
{
    show_players_stats(a[v-1].Team_5_Players[p-1]);
}
void show_a_team(Team Druzyna)
{
    cout<<"Teamname:"<<setw(2);
    for(int i=0; i<Druzyna.n; i++)
    {
        cout<<Druzyna.name[i];
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        show_players_name(Druzyna.Team_5_Players[i]);
    }
}
Maches generate_matches(int k,Team *Team_database,Maches x)
{
    int y=0;
    for(int i=0; i<16; i++)
    {
        x.Team_database_of_maches_1[i]=Team_database[i];
    }
    int p=0;
    for(int i=0; i<8; i++)
    {
        y=rand()%2;
        x.Team_database_of_maches_2[i]=Team_database[p+y];
        p++;
        p++;

    }
    p=0;
    for(int i=0; i<4; i++)
    {

        y=rand()%2;
        x.Team_database_of_maches_3[i]=x.Team_database_of_maches_2[p+y];
        p++;
        p++;
    }
    p=0;
    for(int i=0; i<2; i++)
    {
        y=rand()%2;
        x.Team_database_of_maches_4[i]=x.Team_database_of_maches_3[p+y];
        p++;
        p++;
    }
    y=rand()%2;
    x.Winner[0]=x.Team_database_of_maches_4[y];
}
void show_ladder(int &y,Maches x)
{
    if(y==1)
    {
        show_team_name(x.Team_database_of_maches_1[0]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[1]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[2]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[3]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[4]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[5]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[6]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[7]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[8]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[9]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[10]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[11]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[12]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[13]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
        show_team_name(x.Team_database_of_maches_1[14]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->"<<endl;
        show_team_name(x.Team_database_of_maches_1[15]);
        cout<<setw(1)<<"--|"<<endl;
    }
    if(y==2)
    {
        show_team_name(x.Team_database_of_maches_1[0]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[0]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[1]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->"<<endl;
        show_team_name(x.Team_database_of_maches_1[2]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[1]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[3]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[4]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[2]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[5]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->"<<endl;
        show_team_name(x.Team_database_of_maches_1[6]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[7]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[8]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[4]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[9]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->"<<endl;
        show_team_name(x.Team_database_of_maches_1[10]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[5]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[11]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[12]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[6]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[13]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->"<<endl;
        show_team_name(x.Team_database_of_maches_1[14]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[7]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[15]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
    }
    if(y==3)
    {
        show_team_name(x.Team_database_of_maches_1[0]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[0]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[1]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[0]);
        cout<<setw(1)<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[2]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[1]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[3]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl<<setw(25)<<"|";
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[4]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[2]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[5]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[1]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[6]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[7]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[8]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[4]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[9]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[2]);
        cout<<setw(1)<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[10]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[5]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[11]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl<<setw(25)<<"|";
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[12]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[6]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[13]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[14]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[7]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[15]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
    }
    if(y==4)
    {
        show_team_name(x.Team_database_of_maches_1[0]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[0]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[1]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[0]);
        cout<<setw(1)<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[2]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[1]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[3]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl<<setw(27)<<"|->";
        show_team_name(x.Team_database_of_maches_4[0]);
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[4]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[2]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[5]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[1]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[6]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[7]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[8]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[4]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[9]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[2]);
        cout<<setw(1)<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[10]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[5]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[11]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl<<setw(27)<<"|->";
        show_team_name(x.Team_database_of_maches_4[1]);
        cout<<endl;

        show_team_name(x.Team_database_of_maches_1[12]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[6]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[13]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[14]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[7]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[15]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
    }
    if(y==5)
    {
        show_team_name(x.Team_database_of_maches_1[0]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[0]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[1]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[0]);
        cout<<setw(1)<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[2]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[1]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[3]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl<<setw(27)<<"|->";
        show_team_name(x.Team_database_of_maches_4[0]);
        cout<<"--|"<<endl;

        show_team_name(x.Team_database_of_maches_1[4]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[2]);
        cout<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[5]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[1]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[6]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[3]);
        cout<<"--|"<<setw(18)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[7]);
        cout<<setw(1)<<"--|"<<setw(27)<<"|"<<endl;
        cout<<setw(36)<<"|->";
        show_team_name(x.Winner[0]);
        cout<<endl;


        show_team_name(x.Team_database_of_maches_1[8]);
        cout<<setw(1)<<"--|"<<setw(27)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[4]);
        cout<<"--|"<<setw(18)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[9]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(18)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[2]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[10]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[5]);
        cout<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[11]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<setw(9)<<"|"<<endl<<setw(27)<<"|->";
        show_team_name(x.Team_database_of_maches_4[1]);
        cout<<"--|"<<endl;

        show_team_name(x.Team_database_of_maches_1[12]);
        cout<<setw(1)<<"--|"<<setw(18)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[6]);
        cout<<"--|"<<setw(9)<<"|"<<endl;
        show_team_name(x.Team_database_of_maches_1[13]);
        cout<<setw(1)<<"--|"<<setw(9)<<"|"<<setw(9)<<"|"<<endl;
        cout<<setw(18)<<" |->";
        show_team_name(x.Team_database_of_maches_3[3]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[14]);
        cout<<setw(1)<<"--|";
        cout<<setw(9)<<"|"<<endl;
        cout<<setw(9)<<"|->";
        show_team_name(x.Team_database_of_maches_2[7]);
        cout<<"--|"<<endl;
        show_team_name(x.Team_database_of_maches_1[15]);
        cout<<setw(1)<<"--|"<<endl;
        cout<<endl;
    }
}
void rules(Player gracz)
{
    cout<<"101.Each Team's name is obligated to have 4 characters name (for example Xyzw)"<<endl;
    cout<<"102.Team player is obligated to have 4 characters name (for example Xyzw)"<<endl;
    cout<<"103.Team player has 8 types of stats (for example :"<<endl;
    cout<<"---Stats for 100 last rounds---"<<endl;
    cout<<setw(9);
    cout<<"Nick: "<<gracz.name<<endl;
    cout<<setw(9);
    cout<<"Kills: "<<gracz.stats[0]<<endl;
    cout<<setw(9);
    cout<<"Deaths: "<<gracz.stats[1]<<endl;
    cout<<setw(9);
    cout<<"Assists: "<<gracz.stats[2]<<endl;
    cout<<setw(9);
    cout<<"HS %: "<<gracz.stats[3]<<endl;
    cout<<setw(9);
    cout<<"HE Damage/round: "<<gracz.stats[4]<<endl;
    cout<<setw(9);
    cout<<"Molly Damage/round: "<<gracz.stats[5]<<endl;
    cout<<setw(9);
    cout<<"Movement: "<<gracz.stats[6]<<endl;
    cout<<setw(9);
    cout<<"Positioning: "<<gracz.stats[7]<<")"<<endl;
}
int main()
{
    srand(time(NULL));
    int a=0;
    Player *Players_batabase = new Player [160];
    for(int i=0; i<80; i++)
    {
        for(int i=0; i<80; i++)
            make_a_player(Players_batabase[i]);
        show_players_stats(Players_batabase[i]);
    }
    Team *Team_database= new Team [16];
    for(int i=0; i<16; i++)
    {
        make_a_team( Team_database[i],Players_batabase,a);
    }

    system("cls");
    int w=1;
    while(true)
    {
        int x;
        cout<<"======TOURNAMENT GENERATOR======"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1:GENERATE ROUND"<<endl;
        cout<<"2:SHOW PREVIOUS ROUND"<<endl;
        cout<<"3:SHOW LADDER"<<endl;
        cout<<"4:RULES"<<endl;
        cout<<"5:SHOW TEAM"<<endl;
        cout<<"6:PLAY A LITTLE GAME"<<endl;
        cout<<"7:EXIT"<<endl;
        cout<<"-:";
        cin>>x;
        Maches Winner;
        system("cls");
        generate_matches(1,Team_database,Winner);
        if(x==1)
        {
            cout<<"Generating a round..."<<endl;
            w=w+1;
        }
        else if(x==2)
        {
            cout<<"Generating a round..."<<endl;
            w=w-1;
        }
        else if(x==3)
        {
            cout<<w;
            system("cls");
            show_ladder(w,Winner);
            cout<<endl;
            int h;
            cout<<"(press "<<2<<" to continue)\n-:";
            cin>>h;
            system("cls");

        }
        else if(x==4)
        {
            int h;
            rules(Players_batabase[0]);
            cout<<"(press "<<2<<" to continue)\n-:";
            cin>>h;
            system("cls");
        }
        else if(x==5)
        {
            for(int i=0; i<16; i++)
            {
                cout<<"Team "<<i+1<<": ";
                show_team_name(Team_database[i]);
                cout<<endl;
            }
            cout<<"-:";
            int p;
            cin>>p;
            system("cls");
            if(0<p<17)
            {
                show_a_team(Team_database[p-1]);
            }
            else
            {
                cout<<"zle";
            }
            while(true)
            {
                cout<<"show players stats?(y/n;) -:";
                char l;
                cin>>l;
                if(l=='y')
                {
                    system("cls");
                    show_a_team(Team_database[p-1]);
                    cout<<"what player?(type 1-5)";
                    int u;
                    cin>>u;
                    show_player_from_team(u,Team_database,p);
                }
                if(l=='n')
                {
                    break;
                }
            }
            system("cls");

        }
        else if(x==6)
        {
            system("cls");
            for(int i=0; i<16; i++)
            {
                cout<<"Team "<<i+1<<": ";
                show_team_name(Team_database[i]);
                cout<<endl;
            }
            int g;
            cout<<"On what team are you betting on( 1-16)? -:";
            cin>>g;
            system("cls");
            if(0<g<17)
            {
                show_a_team(Team_database[g-1]);
                system("cls");
                cout<<"==================="<<endl<<setw(9)<<"FIRST ROUND"<<endl<<"==================="<<endl;
                if(g%2==0)
                {
                    show_a_team(Team_database[g-1]);
                    cout<<"==================="<<endl<<setw(9)<<"vs"<<endl<<"==================="<<endl;
                    show_a_team(Team_database[g-2]);
                    cout<<endl;
                }
                if(g%2==1)
                {
                    show_a_team(Team_database[g-1]);
                    cout<<"==================="<<endl<<setw(9)<<"vs"<<endl<<"==================="<<endl;
                    show_a_team(Team_database[g]);
                    cout<<endl;
                }
            }
            else
            {
                cout<<"zle";
            }
            while(true)
            {
                cout<<"generate round (g) see match (m) exit(x) -:";
                char l;
                cin>>l;
                if(l=='x')
                {
                    break;
                }
                int f=0;
                if(f==0 && l=='m')
                {

                    system("cls");
                    cout<<"==================="<<endl<<setw(9)<<"FIRST ROUND"<<endl<<"==================="<<endl;
                    if(g%2==0)
                    {
                        show_a_team(Team_database[g-1]);
                        cout<<"==================="<<endl<<setw(9)<<"vs"<<endl<<"==================="<<endl;
                        show_a_team(Team_database[g-2]);
                        cout<<endl;
                    }
                    else if(g%2==1)
                    {
                        show_a_team(Team_database[g-1]);
                        cout<<"==================="<<endl<<setw(9)<<"vs"<<endl<<"==================="<<endl;
                        show_a_team(Team_database[g]);
                        cout<<endl;
                    }
                }
                if(f==0 && l=='g')
                {
                    w++;
                    system("cls");
                    show_ladder(w,Winner);
                    int rt=f;
                    int q=0;
                    for(int j=0; j<8; j++)
                    {
                        q=0;
                        for(int i=0; i<4; i++)
                        {
                            if(Team_database[g-1].name[i]==Winner.Team_database_of_maches_2[j].name[i])
                            {
                                q++;
                            }
                            if (q==3)
                            {
                                f++;
                            }
                        }
                    }
                    if(f==rt)
                    {
                        cout<<"YOU LOST THE FIRST ROUND"<<endl;
                        break;

                    }
                    else
                    {
                        cout<<"YOU WON THE FIRST ROUND"<<endl;
                    }
                }
            }
        if(x==7)
        {
            break;
            return 0;
        }
    }
    delete [] Players_batabase;
    delete [] Team_database;
    return 0;
}
}
