#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

int main()
{
 ofstream out;
 ifstream in;
 long double count=0;
 string take;
 out.open("generated.txt",ios::out);
 in.open("dictionary.txt",ios::in);
 cout<<"\ngenerating file";

       while(count<=1000000000)
        {
                if(take=="ZZZ")
                {
                        in.seekg(ios::beg);
                }
         in>>take;
         count+=take.length()+1;
         out<<take<<endl;
         //cout<<"\n "<<count;
        }
cout<<"\nfile generated";
        out.close();
        in.close();
 }
