#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
void odwroc(int* poczatek, int* koniec)
{
    while (poczatek < koniec)
    {
        int temp = *poczatek;
        *poczatek = *koniec;
        *koniec = temp;
        ++poczatek;
        --koniec;
    }
}
void maks(int arr[], int n)
{
    int* pom = new int[n];
    pom[0] = arr[0];
    pom[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; ++i)
    {
        pom[i] = max(pom[i-1], pom[i-2] + arr[i]);
    }


    // Odtworzenie wybranych liczb
    int* pom2 = new int[n];
    int id = 0;
    int i = n - 1;
    while (i >= 0)
    {
        if (i == 0)
        {
            pom2[id++] = arr[i];
            break;
        }
        if (pom[i] == pom[i-1])
        {
            i -= 1;
        }
        else
        {
            pom2[id++] = arr[i];
            i -= 2;
        }
    }
    odwroc(pom2, pom2 + id);
    int sum=0;
    for (int i = 0; i <= id; ++i)
    {
        sum=sum+pom2[i];
        cout<<pom2[i]<<", ";
    }
    cout<<"]"<<endl<<"SUMA = "<<sum<<endl;
}
int main()
{
    int n=100;
    int *tab= new int [n];
    for (int i = 0; i < n; ++i)
    {
            tab[i]=i+1;
    }
    cout<<"TABLICA WEJ = [";
    for (int i = 0; i < n; ++i)
    {
        cout<<tab[i]<<", ";
    }
    cout<<"]";
    cout<<endl<<"TABLICA WYJ = [";
    maks(tab,n);
}
