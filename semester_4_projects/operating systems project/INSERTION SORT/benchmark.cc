#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <cstring>

using namespace std;
using namespace std::chrono;

struct vars
{
 int *arr;
 int size;
};
void insertionsort(int arr[],int size)
{
	for(int i=1,j;i<size;i++)
	{
		int temp=arr[i];
		
		for(j=i;j>0 && temp<arr[j-1];j--)
		{
         arr[j]=arr[j-1];
		}
		arr[j]=temp;
	}
}
void *thread1(void *args)
{
 struct vars *v=(vars *)args;
 insertionsort(v->arr,v->size);
  return (void *)v;
}

void *thread2(void *args)
{
 struct vars *v=(vars *)args;
  insertionsort(v->arr,v->size);
  return (void *)v;
}
void *thread3(void *args)
{
 struct vars *v=(vars *)args;
  insertionsort(v->arr,v->size);
  return (void *)v;
}
void *thread4(void *args)
{
 struct vars *v=(vars *)args;
  insertionsort(v->arr,v->size);
  return (void *)v;
}

int main()
{
srand(time(0));
time_t crrtm;
crrtm=time(NULL);
char *time=ctime(&crrtm);
ofstream out;
out.open("insertionsort result.txt",ios::out);

cout<<"\t\t\t\t\t\tINSERTION SORT BENCHMARK"<<endl;
cout<<"\t\t\t\t\t\t\t(THREADS)"<<endl<<endl;
out<<"\t\t\t\t\t\tINSERTION SORT BENCHMARK"<<endl;
out<<"\t\t\t\t\t\t\t(THREADS)"<<endl<<endl;

cout<<"\nNOTE: Terminal only support limited no of lines so we will write the output to the output text file  'insertionsort result.txt'"<<endl;
int max_size=400000;
int sub_size=max_size/4;
cout<<"\n### Creating test array of size "<<max_size;
out<<"\n### Creating test array of size "<<max_size;
int *test_data=new int[max_size];//array of Max size is created;
cout<<"\n### Done creating array";
out<<"\n### Done creating array";
////////////////////////////////////
cout<<"\n### Now filling array with random data";
out<<"\n### Now filling array with random data";

auto start = high_resolution_clock::now();

for(int a=0;a<max_size;a++)
{
 test_data[a]=rand()%max_size+1000; //filling array with random data
}
auto stop = high_resolution_clock::now();

cout<<"\n### Done filling array with random data";
out<<"\n### Done filling array with random data";
auto duration = duration_cast<milliseconds>(stop - start);
cout<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;
out<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;


////////////////////////////////////

int *ar1,*ar2,*ar3,*ar4; //4 threads so 4 arrays;

ar1=new int[sub_size];
ar2=new int[sub_size];
ar3=new int[sub_size];
ar4=new int[sub_size];
cout<<"\n### Breaking array into 4 different arrays so to sort them on each core";
out<<"\n### Breaking array into 4 different arrays so to sort them on each core";
//////////////////////////////////////////////////////////////////////////////////
//Now creating a shared memory block for processes and allocating pointers to it//
//////////////////////////////////////////////////////////////////////////////////
	int shm1 = shmget (IPC_PRIVATE, sub_size * sizeof (int), IPC_CREAT | 0666);
	if (shm1 < 0)
	{
		perror ("shmget");
		return 1;
	}
	int *arr1 = (int*) shmat(shm1, NULL, 0);

	int shm2 = shmget (IPC_PRIVATE, sub_size * sizeof (int), IPC_CREAT | 0666);
	if (shm2 < 0)
	{
		perror ("shmget");
		return 1;
	}
	int *arr2 = (int*) shmat(shm2, NULL, 0);
	
	int shm3 = shmget (IPC_PRIVATE, sub_size * sizeof (int), IPC_CREAT | 0666);
	if (shm3 < 0)
	{
		perror ("shmget");
		return 1;
	}
	int *arr3 = (int*) shmat(shm3, NULL, 0);

	int shm4 = shmget (IPC_PRIVATE, sub_size * sizeof (int), IPC_CREAT | 0666);
	if (shm4 < 0)
	{
		perror ("shmget");
		return 1;
	}
	int *arr4 = (int*) shmat(shm4, NULL, 0);
///////////////////////////////////////////////////////////////
start = high_resolution_clock::now();

int temp=0;
for(int a=0;a<max_size/4;a++)
{
 arr1[a]=test_data[temp];
 ar1[a]=test_data[temp];
 temp++;
}

for(int a=0;a<max_size/4;a++)
{
 arr2[a]=test_data[temp];
 ar2[a]=test_data[temp];
 temp++;
}

for(int a=0;a<max_size/4;a++)
{
 arr3[a]=test_data[temp];
 ar3[a]=test_data[temp];
 temp++;
}

for(int a=0;a<max_size/4;a++)
{
 arr4[a]=test_data[temp];
 ar4[a]=test_data[temp];
 temp++;
}

cout<<"\n### Done breaking array into 4 sub arrays";
out<<"\n### Done breaking array into 4 sub arrays";

stop = high_resolution_clock::now();
duration = duration_cast<milliseconds>(stop - start);
cout<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;
out<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;

vars v1,v2,v3,v4;
v1.arr=ar1;
v1.size=sub_size;

v2.arr=ar2;
v2.size=sub_size;

v3.arr=ar3;
v3.size=sub_size;

v4.arr=ar4;
v4.size=sub_size;

pthread_t tid1,tid2,tid3,tid4; //most systems have 4 physical cores

cout<<"\n### Sending array 1 to core 1";
out<<"\n### Sending array 1 to core 1";
start = high_resolution_clock::now();
pthread_create(&tid1,NULL,thread1,(void *)&v1);

cout<<"\n### Sending array 2 to core 2";
out<<"\n### Sending array 2 to core 2";
pthread_create(&tid2,NULL,thread2,(void *)&v2);

cout<<"\n### Sending array 3 to core 3";
out<<"\n### Sending array 3 to core 3";
pthread_create(&tid3,NULL,thread3,(void *)&v3);

cout<<"\n### Sending array 4 to core 4";
out<<"\n### Sending array 4 to core 4";
pthread_create(&tid4,NULL,thread4,(void *)&v4);


pthread_join(tid1,NULL);
cout<<"\n### Array 1 sorted by core 1";
out<<"\n### Array 1 sorted by core 1";

pthread_join(tid2,NULL);
cout<<"\n### Array 2 sorted by core 2";
out<<"\n### Array 2 sorted by core 2";

pthread_join(tid3,NULL);
cout<<"\n### Array 3 sorted by core 3";
out<<"\n### Array 3 sorted by core 3";

pthread_join(tid4,NULL);
cout<<"\n### Array 4 sorted by core 4";
out<<"\n### Array 4 sorted by core 4";
stop = high_resolution_clock::now();
duration = duration_cast<milliseconds>(stop - start);
cout<<"\n\tsorting took "<<duration.count()<<" Milli seconds"<<endl;
out<<"\n\tsorting took "<<duration.count()<<" Milli seconds"<<endl;

int thread_time=duration.count();
///////////////////////////////////////////////////////////////////////////////
/////////////////PROCESS BENCHMARK STARTS HERE/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
cout<<"\t\t\t\t\t\tINSERTION SORT BENCHMARK"<<endl;
cout<<"\t\t\t\t\t\t\t(PROCESS)"<<endl;
out<<"\t\t\t\t\t\tINSERTION SORT BENCHMARK"<<endl;
out<<"\t\t\t\t\t\t\t(PROCESS)"<<endl;

pid_t p1,p2;
	start = high_resolution_clock::now();
	p1 = fork(); 
	p2 = fork();
	//2 fork call will create 4 processes
	if (p1 > 0 && p2 > 0) 
	{
		cout<<"\n### 1st Process Running";
		out<<"\n### 1st Process Running";
		insertionsort(arr1,sub_size);
		wait(NULL);
		wait(NULL);
		stop = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(stop - start);
		int process_time=duration.count();
		cout<<"\n\tsorting took "<<duration.count()<<" Milli seconds"<<endl;
		out<<"\n\tsorting took "<<duration.count()<<" Milli seconds"<<endl;

		int i,j,k,l;
		i=j=k=l=0;
	
		cout<<"\n### Merging all 4 arrays to one array";
		out<<"\n### Merging all 4 arrays to one array";
		start = high_resolution_clock::now();
		for(int a=0;a<max_size;a++)
		{
		 if(arr1[i]<=arr2[j] && arr1[i]<=arr3[k] && arr1[i]<=arr4[l])
		 {
		  test_data[a]=arr1[i++];
		 }
		 else if(arr2[j]<=arr1[i] && arr2[j]<=arr3[k] && arr2[j]<=arr4[l])
		 {
		  test_data[a]=arr2[j++];
		 }
		 else if(arr3[k]<=arr1[i] && arr3[k]<=arr2[j] && arr3[k]<=arr4[l])
		 { 
		  test_data[a]=arr3[k++];
		 }
		 else
		 {
		  test_data[a]=arr4[l++];
		 }
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(stop - start);
		cout<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;
		out<<"\n\tTime taken "<<duration.count()<<" Milli seconds"<<endl;
		
		cout<<"\n\t\t\t\t\t\t BENCH MARK RESULT"<<endl<<endl;
		out<<"\n\t\t\t\t\t\t BENCH MARK RESULT"<<endl<<endl;
                if(thread_time<process_time)
		{
		cout<<"\nTHREADS took less time processing the array of size "<<max_size<<" which makes THREAD a better option than PROCESS to process array\nin case of 'INSERTION SORT' PROCESS took "<<process_time-thread_time<<" milliseconds more than THREAD";
		out<<"\nTHREADS took less time processing the array of size "<<max_size<<" which makes THREAD a better option than PROCESS to process array\nin case of 'INSERTION SORT' PROCESS took "<<process_time-thread_time<<" milliseconds more than THREAD";
		}		
		else if(thread_time>process_time)
		{			
		cout<<"\nPROCESS took less time processing the array of size "<<max_size<<" which makes PROCESS a better option than TREADS to process array\nin case of 'INSERTION SORT' THREAD took "<<thread_time-process_time<<" milliseconds more than PROCESS";
		out<<"\nPROCESS took less time processing the array of size "<<max_size<<" which makes PROCESS a better option than TREADS to process array\nin case of 'INSERTION SORT' THREAD took "<<thread_time-process_time<<" milliseconds more than PROCESS";
		}		
		else
		{
		cout<<"\nprocess and threads took same time processing the array of size "<<max_size;
		out<<"\nprocess and threads took same time processing the array of size "<<max_size;
		}
		cout<<endl<<endl;
		cout<<"\n### writing output arrray to file insertionsort result.txt";
		out<<"\n### Now printing sorted array:"<<endl;
		sleep(3);
		for(int a=0;a<max_size;a++)
		out<<"\narray["<<a<<"]-->"<<test_data[a];
		cout<<"\n### Writing to file is now finished please open insertionsort result.txt to view the complete result of this benchmark"<<endl;
	
		out.close();
		return 0;
	}
	else if (p1 == 0 && p2 > 0)
	{
		cout<<"\n### 2nd Process Running";
		out<<"\n### 2nd Process Running";
		insertionsort(arr2,sub_size);
	}
	else if (p1 > 0 && p2 == 0)
	{
		cout<<"\n### 3rd Process Running";
		out<<"\n### 3rd Process Running";
		insertionsort(arr3,sub_size);
	}
	else if (p1 == 0 && p2 == 0)
	{
		cout<<"\n### 4th Process Running";
		out<<"\n### 4th Process Running";
		insertionsort(arr4,sub_size);
	}
	else
	{
		cout<<"\n### Process Failed";
		out<<"\n### Process Failed";
		exit(0);
	}
}
