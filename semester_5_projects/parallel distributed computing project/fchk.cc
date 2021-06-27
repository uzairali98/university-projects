#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<omp.h>
using namespace std;

int main()
{
    ifstream in;
    string temp;
    in.open("dictionary.txt",ios::in);
    getline(in,temp);
    cout<<temp<<endl;
    in.seekg(ios::beg);
    getline(in,temp);
    cout<<temp<<endl;
}