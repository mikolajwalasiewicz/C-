#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    int n;
    string linijka;

    fstream plik( "cytaty.txt", ios_base:: app | ios_base:: out );

    if( plik.is_open() )
    {
        char znak = 'N';

        while( znak=='N' )
        {
            cout<<"Podaj nazwisko: ";
            getline( cin, linijka );
            plik<<linijka<<"\n";

            cout<<"Podaj cytat: ";
            getline( cin, linijka );
            plik<<linijka<<"\n"<<"\n";

            cout<<"Czy chcesz zakonczyc? (T/N)";
            cin>>znak;
            cin.get();
            //cin.ignore( 100,'\n' );
        }
        plik.close();
    }
    else
    {
        cout<<"Niestety, pliku nie udalo sie otworzyc";
    }

    fstream plik1;

    plik1.open("cytaty.txt") ;

    if ( plik1.good() )
    {
        while( !plik1.eof() )
        {
            getline( plik1, linijka );
            cout<<linijka<<endl;
        }
    }
    else
        cout<<"ERROR - Brak dostepu do pliku!\n\n" ;
    plik.close();
    return 0;
}
