#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>
#include<cmath>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
using namespace std;
using namespace std::chrono;
int main()
{
    srand(time(0));
    time_t crrtm;
    crrtm=time(NULL);
    char *time=ctime(&crrtm);
    cout<<"\t\t\tThis is the serial version of the project made to see the difference between serial and parallel performance"<<endl;
   

    
    
        //// now inititiating word count using OMP sections
        cout<<"\n##Now calculating words in serial"<<endl;
     auto  start = high_resolution_clock::now();
        unsigned long long int sum=0;
                fstream in;
                in.open("generated.txt",ios::in);
                string temp;
                while(!in.eof())
                {
                    getline(in,temp);
                    sum++;
                }
                in.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<"##word counting completed"<<endl;
    cout<<"\n\t###Time taken to count words in serial enviroment is "<<duration.count()<<" Milli seconds###"<<endl;
    cout<<"Total words in the file are : "<<sum<<endl;
}