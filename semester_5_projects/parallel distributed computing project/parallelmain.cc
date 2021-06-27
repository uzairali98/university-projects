#include<iostream>
#include<omp.h>
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
   

    int no_of_threads = omp_get_max_threads();
    int partition_size = round(1000000000/no_of_threads);//250000000
    unsigned long long int word_length_counter=0;
    cout<<"\t\t\tWelcome to WORD COUNT PROJECT made by Uzair Ali and Hassan Shafiq"<<endl;
    cout<<"##first we will create 4 equal partitions form the 1GB text file we already generated earlier then we will pass that each partition to each thread"<<endl;
    cout<<"##Now creating partitions"<<endl;
    string temp_word_holder;    
   auto start = high_resolution_clock::now();
    #pragma omp parallel firstprivate(word_length_counter,partition_size) private(temp_word_holder)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
             //   cout<<"partition_size p0 "<<partition_size<<endl;
                ifstream main_file;
                ofstream temp_file_holder;
                main_file.open("generated.txt",ios::in);
                temp_file_holder.open("partition0.txt",ios::out);

                while(word_length_counter <= partition_size)
                {
                    main_file>>temp_word_holder; 
                    word_length_counter += temp_word_holder.length()+1;
                    temp_file_holder<<temp_word_holder<<endl;
                }
              //  cout<<"word_length_counter p0 "<<word_length_counter<<endl;
                main_file.close();
                temp_file_holder.close();
            }

            #pragma omp section
            {
               // cout<<"partition_size p1 "<<partition_size<<endl;
                ifstream main_file1;
                ofstream temp_file_holder1;
                main_file1.open("generated.txt",ios::in);
                temp_file_holder1.open("partition1.txt",ios::out);
                main_file1.seekg(partition_size);
                while(word_length_counter <= partition_size)
                {
                    main_file1>>temp_word_holder; 
                    word_length_counter += temp_word_holder.length()+1;
                    temp_file_holder1<<temp_word_holder<<endl;
                }
             //   cout<<"word_length_counter p1 "<<word_length_counter<<endl;
                main_file1.close();
                temp_file_holder1.close();
            }

            #pragma omp section
            {
              //  cout<<"partition_size p2 "<<partition_size<<endl;
                ifstream main_file2;
                ofstream temp_file_holder2;
                main_file2.open("generated.txt",ios::in);
                temp_file_holder2.open("partition2.txt",ios::out);
                main_file2.seekg((partition_size*2));
                while(word_length_counter <= partition_size)
                {
                    main_file2>>temp_word_holder; 
                    word_length_counter += temp_word_holder.length()+1;
                    temp_file_holder2<<temp_word_holder<<endl;
                }
             //   cout<<"word_length_counter p2 "<<word_length_counter<<endl;
                main_file2.close();
                temp_file_holder2.close();
            }

            #pragma omp section
            {
              //  cout<<"partition_size p3 "<<partition_size<<endl;
                ifstream main_file3;
                ofstream temp_file_holder3;
                main_file3.open("generated.txt",ios::in);
                temp_file_holder3.open("partition3.txt",ios::out);
                main_file3.seekg((partition_size-1)*3);
                while(word_length_counter <= partition_size && !main_file3.eof())
                {
                    main_file3>>temp_word_holder; 
                    word_length_counter += temp_word_holder.length()+1;
                    temp_file_holder3<<temp_word_holder<<endl;
                }
              //  cout<<"word_length_counter p3 "<<word_length_counter<<endl;
                main_file3.close();
                temp_file_holder3.close();
            }
        }
        
    }
    #pragma omp barrier
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<milliseconds>(stop - start);
    cout<<"##partitions generated"<<endl;
    cout<<"\n\t###Time taken to generate partitions is "<<duration.count()<<" Milli seconds###"<<endl;
    cout<<"\n\n////////////////////////////////////////////////////////////////"<<endl;

    
    
//// now inititiating word count using OMP sections
cout<<"\n##Now calculating words in parallel"<<endl;
start = high_resolution_clock::now();
unsigned long long int counts[4],sum=0;
    #pragma omp parallel shared(counts)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                counts[0]=0;
                fstream in;
                in.open("partition0.txt",ios::in);
                string temp;
                while(!in.eof())
                {
                    getline(in,temp);
                    counts[0]++;
                }
                in.close();
              //  cout<<"\npartition 0 has "<<counts[0]<<endl;
            }

            #pragma omp section
            {
                counts[1]=0;
                fstream in;
                in.open("partition1.txt",ios::in);
                string temp;
                while(!in.eof())
                {
                    getline(in,temp);
                    counts[1]++;
                }
                in.close();
              //  cout<<"\npartition 1 has "<<counts[1]<<endl;
            }

            #pragma omp section
            {
                counts[2]=0;
                fstream in;
                in.open("partition2.txt",ios::in);
                string temp;
                while(!in.eof())
                {
                    getline(in,temp);
                    counts[2]++;
                }
                in.close();
              //  cout<<"\npartition 2 has "<<counts[2]<<endl;
            }

            #pragma omp section
            {
                counts[3]=0;
                fstream in;
                in.open("partition3.txt",ios::in);
                string temp;
                while(!in.eof())
                {
                    getline(in,temp);
                    counts[3]++;
                }
                in.close();
              //  cout<<"\npartition 3 has "<<counts[3]<<endl;
            }
        }
        #pragma omp barrier
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout<<"##word counting completed"<<endl;
    cout<<"\n\t###Time taken to count words is "<<duration.count()<<" Milli seconds###"<<endl;
    for(int a=0;a<4;a++)
    {
        sum+=counts[a];
        cout<<"partition "<<a<<" has "<<counts[a]<<" words "<<endl;
    }
    cout<<"Total words in the file are : "<<sum<<endl;
}