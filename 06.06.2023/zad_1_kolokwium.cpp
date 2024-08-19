#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string line;
    string filename;
    cout<<"File name :";
    cin>>filename;
    fstream file(filename, ios_base:: app | ios_base:: out );
    file.open(filename,ios::out);
    if(file.is_open())
    {
        cout<<"opened\n";
        int N;
        cout<<"N= ";
        cin>>N;
        char *characters= new char [4];
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout<<"*Click ENTER after you type*";
                cin>>characters[j];
                if(characters[j] == '1' || '2'|| '3'|| '4'|| '5'|| '6'|| '7'|| '8'|| '9'|| '0' )
                {
                    string c;
                    c=characters[j];
                    file<<c<<" ";
                }
            }
        }
        file.close();
        fstream file1;
        file1.open(filename);
        cout<<filename;
        if(file1.good())
        {
            while (!file1.eof())
            {
                getline(file1, line);
                cout<<line<<endl;
            }
        }
        else
        {
            cout<<"fatal error";
        }

    }
    else
    {
        cout<<"fatal error";
    }

}
