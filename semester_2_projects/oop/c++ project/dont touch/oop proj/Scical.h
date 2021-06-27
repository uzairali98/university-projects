#ifndef SCICAL_H
#define SCICAL_H
#include<iostream>
#include<math.h>
using namespace std;
class scientificcalculator
{
 public:

     double rootofanynumber(int base,float exp)
     {
         return pow(base,(1/exp));
     }
    float add(float x,float y)
    {
        return x+y;
    }
    float subtract(float x,float y)
    {
        return x-y;
    }
    float multiply(float x,float y)
    {

        return x*y;
    }
    float divide(float x,float y)
    {
        return x/y;
    }
    long long int factorial(long int num)
    {
        long long int result=1;
        for(int i=num;i>=1;i--)
        {
            result*=i;
        }
        return result;
    }
double logarithm(float num)
{
    system("cls");int cho;
    cout<<"\t\t\tLOGARITHM\n\t1.Natural Log\n\t2.Base 10 Log"<<endl;
    cursor cursor1;
    int x=1;cursor1.gotoxy(0,x,"->");char a;char enter='\r';
    cursor1.ShowConsoleCursor(false);
    for(int i=0;i>=0;i++)
    {
       a=getch();
    	if(a==enter)
    	{
    		break;
		}
    	else if(a==80)
    	{
    	    if(x==2)
			{
				continue;
				}
				else
				{
            cursor1.gotoxy(0,x,"  ");
    		cursor1.gotoxy(0,x+1,"->");
    		x++;
    	}
}
		else if(a==72)
		{
			if(x==1)
			{
				continue;
			}
			else{
          cursor1.gotoxy(0,x,"  ");
			cursor1.gotoxy(0,x-1,"->");
			x--;
		}
		}
		else if(a==75||a==77)
		{
			continue;
		}

	}
    cho=x;
	cursor1.gotoxy(0,3);
	cursor1.ShowConsoleCursor(true);
    if(cho==1)
        return log(num);
    else if(cho==2)
        return log10(num);

}
void transpose(ofstream &log)
{
    int row,colums;
    cout<<"Enter Rows: ";
    cin>>row;
    cout<<"Enter Colums: ";
    cin>>colums;
    float **array=new float*[row];
        for(int i=0;i<row;i++)
        {
          array[i]=new float[colums];
        }
        for(int i=0;i<row;i++)
        {

            for(int j=0;j<colums;j++)
            {
                cout<<"Enter Element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
                cin>>array[i][j];
            }
        }
        system("cls");
        cout<<"Transposed Array: "<<endl;
        log<<"\nTransposed Array: ";
        for(int i=0;i<colums;i++)
        {

            for(int j=0;j<row;j++)
            {
                cout<<array[j][i]<<" ";
                log<<array[j][i]<<" ";
            }
            cout<<endl;
            log<<endl;
        }


}
float matrixdeter(int cho)
{
    system("cls");float det=0.0;
    if(cho==1)
    {
        float **array=new float*[2];
        for(int i=0;i<2;i++)
        {
          array[i]=new float[2];
        }
        for(int i=0;i<2;i++)
        {

            for(int j=0;j<2;j++)
            {
                cout<<"Enter Element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
                cin>>array[i][j];
            }
        }

         det=((array[0][0]*array[1][1])-(array[0][1]*array[1][0]));


    }
    else if(cho==2)
    {

        float **intptr=new float*[3];
        for(int i=0;i<3;i++)
        {
          intptr[i]=new float[3];
        }
        for(int i=0;i<3;i++)
        {

            for(int j=0;j<3;j++)
            {
                cout<<"Enter Element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
                cin>>intptr[i][j];
            }
        }

         det=intptr[0][0]*((intptr[1][1]*intptr[2][2]) - (intptr[2][1]*intptr[1][2])) -intptr[0][1]*(intptr[1][0]*intptr[2][2] - intptr[2][0]*intptr[1][2]) + intptr[0][2]*(intptr[1][0]*intptr[2][1] - intptr[2][0]*intptr[1][1]);


    }

    return det;
}
bool identitycheck()
{
    system("cls");int size;
    cout<<"Enter Size: "<<endl;
    cin>>size;
    float **intptr=new float *[3];
    for(int i=0;i<size;i++)
    {

        intptr[i]=new float[size];
    }
    for(int i=0;i<size;i++)
        {

            for(int j=0;j<size;j++)
            {
                cout<<"Enter Element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
                cin>>intptr[i][j];
            }
        }
        for(int x=0;x<size;x++)
            {
            for(int y=0;y<size;y++)
            {
            if(y==x)
        {
        if(intptr[x][y]!=1)
        {
           return false;
        }
    else
    continue;
        }
        if(intptr[x][y]!=0)
    {
    return false;
    }
    }
}

return true;
}
double sine(float x)
{
    return sin(x);
}
double cosine(float x)
{
    return cos(x);
}
double tangent(float x)
{
    return tan(x);
}
double cosec(float x)
{
    double a=sine(x);
    return (1/a);
}
double sec(float x)
{

    double a=cosine(x);
    return (1/a);
}
double cotangent(float x)
{
    double a=tangent(x);
    return (1/a);
}

double sininverse(float x)
{
return asin(x);
}
double cosinverse(float x)
{
    return acos(x);
}
double taninverse(float x)
{
    return atan(x);
}
double cosecinverse(float x)
{

    return asin(1/x);
}
double secinverse(float x)
{

    return acos(1/x);
}
double cotinverse(float x)
{
 return atan(1/x);

}
double nPr(int n,int r)
{
    double n1=factorial(n);
    double r1=factorial(n-r);
    return (n1/r1);
}
double nCr(int n,int r)
{
  double result=nPr(n,r);
    double r1=factorial(r);

    return (result*(1/r1));
}
long long int power(int base,int exp)
{
    return pow(base,exp);
}

};
#endif // SCICAL_H
