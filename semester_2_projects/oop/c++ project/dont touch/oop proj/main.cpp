#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "cursor.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include<conio.h>
#include<thread>
#include <iostream>
#include<errno.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<cstring>
#include<complex.h>
#include "Scical.h"
#define pie 3.14159265
#define xmax  1280
#define ymax  720
int xh=xmax/2;
int yh=ymax/2;
using namespace std;
using namespace sf;
class calculations:public scientificcalculator
{
public:
float slopec(float x1,float y1,float x2,float y2)
{
	float ans;
	ans=(y2-y1)/(x2-x1);
	return(ans);
}
float fabsf(float a)
 {
 if(a<0)
 return(a-(a*2));
 else
 return(a);
 }
float disc(float x1,float y1,float x2,float y2)
{
	float ans;
	ans=sqrt(((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1));
	return (ans);
}

float *midpointc(float x1,float y1,float x2,float y2)
{
	float *coordptr;
	coordptr=new float[2];
	coordptr[0]=(x1+x2)/2;
	coordptr[1]=(y1+y2)/2;
	return(coordptr);
}

int *realxy(float x,float y)
{
    int *realxy;float tempx;float tempy;
    realxy=new int [2];
    tempx=x;tempy=y;

    if(x<0)
    {
        x=xh-(fabsf(tempx));
        if(x<0)
            x=0;
            realxy[0]=x;


        }
        else
        {
            x=xh+tempx;
            if(x>xmax)
            {
                x=xmax;
            }
            realxy[0]=x;
        }
        if(y<0)
        {
            y=yh+(fabsf(tempy));
            if(y>ymax)
            {
                y=ymax;
            }
            realxy[1]=y;
        }
        else
        {
            y=yh-tempy;
            if(y<0)
            {
                y=0;
            }
            realxy[1]=y;
        }

    return(realxy);
}


    float *poi(float x1,float y1,float cons1,float x2,float y2,float cons2)
{
    float y3,cons3,x3,yf,xf,tempy,tempcons;
    float *ptr=new float[2];
          if(x1==x2)
		    {
				y3=y1-y2;
				if(cons1<cons2)
				cons3=fabsf(cons1-cons2);
				else
				cons3=-(cons1-cons2);
				yf=cons3/y3;
				xf=(yf*y1)+cons1;
				if(xf>0)
				xf=-xf;
				else
				xf=fabsf(xf);
				ptr[0]=xf;
				ptr[1]=yf;
			}
			else if(y1==y2)
			{
				x3=x1-x2;
				if(cons1<cons2)
				cons3=fabsf(cons1-cons2);
				else
				cons3=-(cons1-cons2);
				xf=cons3/x3;
				yf=(x1*xf)+cons1;
				if(yf>0)
				yf=-yf;
				else
				yf=fabsf(yf);
				ptr[0]=xf;
				ptr[1]=yf;
			}
			else
			{
				if(x1>x2)
				{
					tempy=x1*y2;
					tempcons=x1*cons2;
					y3=y1-tempy;
					if(tempcons<cons1)
					cons3=-(cons1-tempcons);
					else
					cons3=fabsf(cons1-tempcons);
					yf=cons3/y3;
				   xf=(yf*y1)+cons1;
				   if(xf>0)
				   xf=-xf;
				   else
				   xf=fabsf(xf);
				   xf/=x1;
				   ptr[0]=xf;
				   ptr[1]=yf;
			    }
				else
				{
					tempy=x2*y1;
					tempcons=x2*cons1;
					y3=tempy-y2;
					if(tempcons<cons2)
					cons3=fabsf(tempcons-cons2);
					else
					cons3=-(tempcons-cons2);
					yf=cons3/y3;
					xf=(yf*y2)+cons2;
					if(xf>0)
					xf=-xf;
					else
					xf=fabsf(xf);
					xf/=x2;
					ptr[0]=xf;
				    ptr[1]=yf;
                }
             }
             return(ptr);
}
float angle(float x1,float x2,float x3,float x4,float y1,float y2,float y3,float y4)
{

    float ans,m1,m2;
	m1=slopec(x1,y1,x2,y2);
	m2=slopec(x3,y3,x4,y4);
	ans=atan((fabs(m1-m2)/fabs(1+(m1*m2))))*180/pie;
	return(ans);
}
};
class graphics:public calculations
{
    int *ptr,a,*intptr,fi1,f2,f3,f4;char *charptr; float x;char co[10];
    public:
    graphics()
    {
        fi1=0;
        f2=0;
        f3=0;
        f4=0;
        x=0;
    }
     void plotpolynomial(int cho,ofstream &log)
    {
        float x=0,y=0;int size=(2*xmax)+1;
        float cofx1,power1,con,cofx2,power2,cofx3,cofx4,power3,power4;
        vector< vector<int> > coordptr(size,vector<int>(2));
       int *ptr,**coordptr4u,**coordptr4u2;
       int counter2=0,counthold1=0,counthold2=0,counter=0;
        switch(cho)
        {

        case 1:
            {
                 cout<<"Enter the co-efficient of X: ";cin>>cofx1;
                cout<<"Enter the Power of X: ";cin>>power1;
                cout<<"Enter the Constant: ";cin>>con;float num1=0.2,num2=0.4,num3=0.6;
                if(power1>0&&power1<=1)
                {
                    cout<<"All set Graph is About to Plot"<<endl;
                }
                else{
                        cout<<"Renter the Power of X:(power>0 and power<=1) ";cin>>power1;
                }
                fflush(stdin);
               x=-1*xh;

                while(1)
                    {
                    if(x==0)
                       {
                        break;
                       }
                 else if((fmod(power1,num1))==0&&fmod(power1,num2)!=0)
                           {
                               ptr=realxy(x,(pow(abs(x),power1)*cofx1*-1)+con);
                               coordptr[counter][0]=ptr[0];
                               coordptr[counter][1]=ptr[1];
                           }
                           else if(fmod(power1,num2)==0)
                           {
                               ptr=realxy(x,(pow(abs(x),power1)*cofx1)+con);
                               coordptr[counter][0]=ptr[0];
                               coordptr[counter][1]=ptr[1];
                           }
                           else if(power1==num3)
                           {
                               ptr=realxy(x,(pow(abs(x),power1)*cofx1*-1)+con);
                               coordptr[counter][0]=ptr[0];
                               coordptr[counter][1]=ptr[1];
                           }
                           x+=0.5;
                            counter++;
                    }
                    while(1)
                    {
                        if(x==xh)
                            break;
                        ptr=realxy(x,(pow(abs(x),power1)*cofx1)+con);
                            coordptr[counter][0]=ptr[0];
                            coordptr[counter][1]=ptr[1];
                            x+=0.5;
                            counter++;
                    }
                    if(fmod(power1,num1)==0||power1==num3)
                    {
                     counter=0;
                     }
                     else
                     {counter=xmax ;}
            log<<"\npolynomial of degree 1 with co-efficient "<<cofx1<<",power "<<power1<<" and constant "<<con<<" plotted";
            CircleShape c(1,30);
        Font f1,f2;
 f1.loadFromFile("calibri.ttf");
 f2.loadFromFile("KBSticktoIt.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
Text t5("GRAPH PLOTTED!!",f2,20);
t5.move(Vector2f(10,10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       c.setPosition(coordptr[counter][0],coordptr[counter][1]);
       window.draw(c);
       window.display();
	  counter++;
     this_thread::sleep_for(chrono::milliseconds(1));
	  if(xmax*2==counter)
      {
          window.display();
          system("PAUSE");
          break;
      }
    }
            }
            return;
        case 2:
            {
            cout<<"\nBinomial:\nIt is an algebraic expression which comprises of two, unlike terms.\nFor example,\n3x + 4x^2 is binomial since it contains two unlike terms, that is, 3x and 4x^2";
			cout<<"\nenter value of coefficient of 1st X";
			cin>>cofx1;
			cout<<"\nenter value of coefficient of 2nd X";
			cin>>cofx2;
			cout<<"\nenter power/degree of 1st X ";
			cin>>power1;
             cout<<"\nenter power/degree of 2nd X ";
			cin>>power2;
			cout<<"\nenter value of constant ";
			cin>>con;
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			counter++;
			x+=0.1;
			}
			coordptr4u=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u[a]=new int[2];
			counthold1=counter;
			counter=0;
			x=0;
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			coordptr4u[counter][0]=ptr[0];
			coordptr4u[counter][1]=ptr[1];
			counter++;
			x+=0.1;
			}
             counter=0;
			 x=0;
			while(1)                                         //y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2);
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+con;
			ptr=realxy(x,-y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			counter++;
			x-=0.1;
			}
			coordptr4u2=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u2[a]=new int[2];
			counthold2=counter;
			x=0;
			counter=0;
			while(1)                                         //y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2);
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			coordptr4u2[counter][0]=ptr[0];
			coordptr4u2[counter][1]=ptr[1];
			counter++;
			x-=0.1;
			}
			log<<"\npolynomial of degree 2 with \nco-efficient 1:"<<cofx1<<",power 1:"<<power1<<"\nco-efficient 2:"<<cofx2<<",power 2:"<<power2<<"\nconstant 1:"<<con<<" PLOTTED";
            }//case 2 ends
            break;
        case (3):
            {
            cout<<"\nTrinomial:\nIt is an algebraic expression that comprises three, unlike terms.\nFor example- 3x + 5x^2 – 6x^3";
			cout<<"\nenter value of coefficient of 1st X";
			cin>>cofx1;
			cout<<"\nenter value of coefficient of 2nd X";
			cin>>cofx2;
			cout<<"\nenter value of coefficient of 3rd X";
			cin>>cofx3;
			cout<<"\nenter power/degree of 1st X ";
			cin>>power1;
			cout<<"\nenter power/degree of 2nd X ";
			cin>>power2;
			cout<<"\nenter power/degree of 3rd X ";
			cin>>power3;
			cout<<"\nenter value of constant ";
			cin>>con;
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			counter++;
			x+=0.1;
			}
	     	coordptr4u=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u[a]=new int[2];
			counthold1=counter;
			counter=0;
			 x=0;
			 while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			coordptr4u[counter][0]=ptr[0];
			coordptr4u[counter][1]=ptr[1];
			counter++;
			x+=0.1;
			}
			counter=0;
			 x=0;
			while(1)                                         //y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
		    y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			counter++;
			x-=0.1;
			}
			coordptr4u2=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u2[a]=new int[2];
			counthold2=counter;
			x=0;
			counter=0;
			while(1)                                         //y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
		    y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+con;
			else if(abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			coordptr4u2[counter][0]=ptr[0];
			coordptr4u2[counter][1]=ptr[1];
			counter++;
			x-=0.1;
			}
			log<<"\npolynomial of degree 3 with \nco-efficient 1:"<<cofx1<<",power 1:"<<power1<<"\nco-efficient 2:"<<cofx2<<",power 2:"<<power2<<"\nco-efficient 3:"<<cofx3<<",power 3:"<<power3<<"\nconstant 1:"<<con<<" PLOTTED";
            }//case 3 ends
            break;
        case(4):
            {
            cout<<"\nPolynomial Of Degree 4:\nIt is an algebraic expression that comprises four, unlike terms.\nFor example- 3x + 5x^2 – 6x^3 + 7x^(1/2)";
			cout<<"\nenter value of coefficient of 1st X";
			cin>>cofx1;
			cout<<"\nenter value of coefficient of 2nd X";
			cin>>cofx2;
			cout<<"\nenter value of coefficient of 3rd X";
			cin>>cofx3;
			cout<<"\nenter value of coefficient of 4th X";
			cin>>cofx4;
			cout<<"\nenter power/degree of 1st X ";
			cin>>power1;
			cout<<"\nenter power/degree of 2nd X ";
			cin>>power2;
			cout<<"\nenter power/degree of 3rd X ";
			cin>>power3;
			cout<<"\nenter power/degree of 4th X ";
			cin>>power4;
			cout<<"\nenter value of constant ";
			cin>>con;
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			counter++;
			x+=0.1;
			}
	     	coordptr4u=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u[a]=new int[2];
			counthold1=counter;
			counter=0;
			 x=0;
			 while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			coordptr4u[counter][0]=ptr[0];
			coordptr4u[counter][1]=ptr[1];
			counter++;
			x+=0.1;
			}
			while(1)                     //y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
		    y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(abs(4),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(2),power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(abs(4),power4)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			counter++;
			x-=0.1;
			}
			coordptr4u2=new int*[counter+5];
			 for(int a=0;a<counter+5;a++)
			coordptr4u2[a]=new int[2];
			counthold2=counter;
			x=0;
			counter=0;
			while(1)                     //y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			{
			if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
		    y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power3,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(abs(x),power4)+con;
			else if(abs(fmod(power2,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(x),power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power4,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(abs(4),power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power3,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0 && abs(fmod(power2,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(abs(x),power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power2,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(abs(2),power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power3,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(abs(x),power3)+cofx4*pow(x,power4)+con;
			else if(abs(fmod(power4,1))!=0)
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(abs(4),power4)+con;
			else
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			coordptr4u2[counter][0]=ptr[0];
			coordptr4u2[counter][1]=ptr[1];
			counter++;
			x-=0.1;
			}
			log<<"\npolynomial of degree 4 with \nco-efficient 1:"<<cofx1<<",power 1:"<<power1<<"\nco-efficient 2:"<<cofx2<<",power 2:"<<power2<<"\nco-efficient 3:"<<cofx3<<",power 3:"<<power3<<"\nco-efficient 4:"<<cofx4<<",power 4:"<<power4<<"\nconstant 1:"<<con<<" PLOTTED";
            }//case 4 ends
			break;
            }//switch ends here

    counter=0;
    CircleShape c(1,30),c1(1,30);
 Font f1,f2;f2.loadFromFile("KBSticktoIt.ttf");
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
Text t5("GRAPH PLOTTED!!",f2,20);
t5.move(Vector2f(10,10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       if(counter==counthold1 || counter>counthold1 || coordptr4u[counter][0]>=xmax || coordptr4u[counter][1]>=ymax || coordptr4u[counter][0]<=0 ||coordptr4u[counter][1]<=0)
       {
           c1.setPosition(coordptr4u2[counter2][0],coordptr4u2[counter2][1]);
           window.draw(c1);
           counter2++;
       }
       else
       {
       c.setPosition(coordptr4u[counter][0],coordptr4u[counter][1]);
       window.draw(c);
       }
       window.display();
	  counter++;
     // this_thread::sleep_for(chrono::milliseconds());
	  if( coordptr4u2[counter2][0]<=0 || coordptr4u2[counter2][1]<=0 || coordptr4u2[counter2][1]<=0 || counter2==counthold2 || coordptr4u2[counter2][0]>=xmax || coordptr4u2[counter2][1]>=ymax)
      {
          window.draw(t5);
          window.display();
          getch();
          break;
      }
    }
}//plotpolynomial ends here
void plothyperbola(float h,float k,float a,float b,int cho)//a and b cannot be negative
{
    int **coord1;int **coord2;int **coord3;int **coord4;
    int counter=0;int counterhold=0;int counterhold2=0;
    //c=sqrt(pow(b,2)+pow(a,2));
    int x=h,y=k;
    switch(cho)
    {
    case 1:
        {
            x=h+a;
            while(1)
                    {
                        if(x>xh)
                        break;
                        ptr=realxy(x,((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))+k);
                        counter++;
                        x++;

                    }
                    x=h+a;
                    coord1=new int *[counter+1];
                    for(int i=0;i<counter+1;i++)
                    {
                        coord1[i]=new int[2];
                    }
                    counterhold=counter;
                    counter=0;
                    while(1)
                    {
                        if(x>xh)
                            break;
                        ptr=realxy(x,(((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))+k)*-1);
                        counter++;
                        x++;
                    }
                    x=h+a;
                    coord2=new int *[counter+1];
                    for(int i=0;i<counter+1;i++)
                    {
                        coord2[i]=new int[2];
                    }

                    counter=0;
                    while(1)
                    {
                        if(x>xh)
                            break;
                        ptr=realxy(x,(((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))+k));
                        coord1[counter][0]=ptr[0];
                        coord1[counter][1]=ptr[1];

                        counter++;
                        x++;

                    }
                    x=h+a;
                    counter=0;
                    while(1)
                    {
                        if(x>xh)
                            break;
                        ptr=realxy(x,(((b/(float)a)*sqrt(abs(pow(x-h,2)-pow(a,2)))-k)*-1));
                        coord2[counter][0]=ptr[0];
                        coord2[counter][1]=ptr[1];

                        counter++;
                        x++;

                    }

                    x=h-a;
                    counter=0;
                    while(1)
                    {
                         if(abs(x)>xh)
                         break;
                         ptr=realxy(x,(((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))+k));
                         counter++;
                         x--;
                    }
                    counterhold2=counter;
                    x=h-a;
                    coord3=new int *[counter+1];
                    for(int i=0;i<counter;i++)
                    {
                        coord3[i]=new int[2];

                    }
                    coord4=new int *[counter+1];
                    for(int i=0;i<counter;i++)
                    {
                        coord4[i]=new int[2];

                    }
                    counter=0;

                    while(1)
                    {
                        if(abs(x)>xh)
                         break;
                         ptr=realxy(x,(((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))+k));
                         coord3[counter][0]=ptr[0];
                         coord3[counter][1]=ptr[1];
                         counter++;
                         x--;
                    }
                    counter=0;x=h-a;
                    while(1)
                    {
                        if(abs(x)>xh)
                         break;
                         ptr=realxy(x,(((b/(float)a)*sqrt(pow(x-h,2)-pow(a,2)))-k)*-1);
                         coord4[counter][0]=ptr[0];
                         coord4[counter][1]=ptr[1];
                         counter++;
                         x--;
                    }
}
        break;
    case 2:
        {
            y=k+a;
            while(1)
                    {
                        if(y>yh)
                        break;
                        ptr=realxy(((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))+h,y);
                        counter++;
                        y++;

                    }
                    y=k+a;
                    coord1=new int *[counter+1];
                    for(int i=0;i<counter+1;i++)
                    {
                        coord1[i]=new int[2];
                    }
                    counterhold=counter;
                    counter=0;
                    while(1)
                    {
                        if(y>yh)
                            break;
                        ptr=realxy((((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))+h)*-1,y);
                        counter++;
                        y++;
                    }
                    y=k+a;
                    coord2=new int *[counter+1];
                    for(int i=0;i<counter+1;i++)
                    {
                        coord2[i]=new int[2];
                    }

                    counter=0;
                    while(1)
                    {
                        if(y>yh)
                            break;
                        ptr=realxy((((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))+h),y);
                        coord1[counter][0]=ptr[0];
                        coord1[counter][1]=ptr[1];

                        counter++;
                        y++;

                    }
                    y=k+a;
                    counter=0;
                    while(1)
                    {
                        if(y>yh)
                            break;
                        ptr=realxy((((b/(float)a)*sqrt(abs(pow(y-k,2)-pow(a,2)))-h)*-1),y);
                        coord2[counter][0]=ptr[0];
                        coord2[counter][1]=ptr[1];

                        counter++;
                        y++;

                    }

                    y=k-a;
                    counter=0;
                    while(1)
                    {
                         if(abs(y)>yh)
                         break;
                         ptr=realxy((((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))+h),y);
                         counter++;
                         y--;
                    }
                    counterhold2=counter;
                    y=k-a;
                    coord3=new int *[counter+1];
                    for(int i=0;i<counter;i++)
                    {
                        coord3[i]=new int[2];

                    }
                    coord4=new int *[counter+1];
                    for(int i=0;i<counter;i++)
                    {
                        coord4[i]=new int[2];

                    }
                    counter=0;

                    while(1)
                    {
                        if(abs(y)>yh)
                         break;
                         ptr=realxy((((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))+h),y);
                         coord3[counter][0]=ptr[0];
                         coord3[counter][1]=ptr[1];
                         counter++;
                         y--;
                    }
                    counter=0;y=k-a;
                    while(1)
                    {
                        if(abs(y)>yh)
                         break;
                         ptr=realxy((((b/(float)a)*sqrt(pow(y-k,2)-pow(a,2)))-h)*-1,y);
                         coord4[counter][0]=ptr[0];
                         coord4[counter][1]=ptr[1];
                         counter++;
                         y--;
                    }
        }
    }
    CircleShape c1(1,30);
    CircleShape c2(1,30);
        Font f1,f2;f2.loadFromFile("KBSticktoIt.ttf");
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
counter=0;
Text t5("HYPERBOLA CREATED!!",f2,20);
t5.move(Vector2f(10,10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       c1.setPosition(coord1[counter][0],coord1[counter][1]);
       window.draw(c1);
      c2.setPosition(coord3[counter][0],coord3[counter][1]);
       window.draw(c2);

      c1.setPosition(coord2[counter][0],coord2[counter][1]);
       window.draw(c1);
       c2.setPosition(coord4[counter][0],coord4[counter][1]);
       window.draw(c2);
	  window.display();
	  counter++;

	  this_thread::sleep_for(chrono::milliseconds(1));
	  if(counterhold==counter||counterhold2==counter)
      {
          window.draw(t5);
          window.display();
          getch();
          break;
      }
    }
}
void plotparabola(int h,int k,float a,int choice)//graphics
{
     int **arrofcoord1,**arrofcoord2;
	int x=h,y=k;int *ptr;int counter=0,counthold=0;
	switch(choice)
	{
		case(1)://(y-k)^2=4a(x-h)
		if(a>0)
		{
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(x,sqrt(abs(4*a*(x-h)))+k);
				counter++;
				x++;
			}
			counthold=counter;
			 arrofcoord1=new int*[counter+1];
			 for(int a=0;a<counter;a++)
			arrofcoord1[a]=new int[2];
			 arrofcoord2=new int*[counter+1];
			  for(int a=0;a<counter;a++)
			arrofcoord2[a]=new int[2];
			counter=0;
			x=h;
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(x,sqrt(abs(4*a*(x-h)))+k);
				arrofcoord1[counter][0]=ptr[0];
				arrofcoord1[counter][1]=ptr[1];
				x++;
				counter++;
			}
			x=h;
			counter=0;
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(x,-1*sqrt(abs(4*a*(x-h)))+k);
				arrofcoord2[counter][0]=ptr[0];
				arrofcoord2[counter][1]=ptr[1];
				x++;
				counter++;
			}
		}
		else
		{
		    counter=0;
			if(h<0)
			x=abs(h);
			else
			x=-abs(h);
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(-x,sqrt(4*a*(-x-h))+k);
				counter++;
				x++;
			}
			if(h<0)
			x=abs(h);
			else
			x=-abs(h);
			counthold=counter;
			 arrofcoord1=new int*[counter+1];
			 for(int a=0;a<counter;a++)
			arrofcoord1[a]=new int[2];
			 arrofcoord2=new int*[counter+1];
			  for(int a=0;a<counter;a++)
			arrofcoord2[a]=new int[2];
			counter=0;
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(-x,sqrt(4*a*(-x-h))+k);
				arrofcoord1[counter][0]=ptr[0];
				arrofcoord1[counter][1]=ptr[1];
				counter++;
				x++;
			}
			counter=0;
			if(h<0)
			x=abs(h);
			else
			x=-abs(h);
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(-x,-1*sqrt(4*a*(-x-h))+k);
				arrofcoord2[counter][0]=ptr[0];
				arrofcoord2[counter][1]=ptr[1];
				x++;
				counter++;
			}
		}
			break;
		 case(2):
		     counter=0;                                     //(x-h)^2=4a(y-k)
		 if(a>0)
		 {
		 	while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(sqrt(abs(4*a*(y-k)))+h,y);
				counter++;
				y++;
			}
			counthold=counter;
			 arrofcoord1=new int*[counter+1];
			 for(int a=0;a<counter;a++)
			arrofcoord1[a]=new int[2];
			 arrofcoord2=new int*[counter+1];
			  for(int a=0;a<counter;a++)
			arrofcoord2[a]=new int[2];
			counter=0;
			y=k;
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(sqrt(fabsf(4*a*(y-k)))+h,y);
				arrofcoord1[counter][0]=ptr[0];
				arrofcoord1[counter][1]=ptr[1];
				counter++;
				y++;
			}
			counter=0;
			y=k;
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(-1*sqrt(abs(4*a*(y-k)))+h,y);
				arrofcoord2[counter][0]=ptr[0];
				arrofcoord2[counter][1]=ptr[1];
				counter++;
				y++;
			}
		}
		else
		{
			if(k<0)
			y=abs(k);
			else
			y=-abs(k);
				while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(sqrt(4*a*(-y-k))+h,-y);            //ptr=realxy(-x,sqrt(4*a*(-x-h))+k);
				counter++;
				y++;
			}
			counthold=counter;
			 arrofcoord1=new int*[counter+1];
			 for(int a=0;a<counter;a++)
			arrofcoord1[a]=new int[2];
			 arrofcoord2=new int*[counter+1];
			  for(int a=0;a<counter;a++)
			arrofcoord2[a]=new int[2];
			counter=0;
			if(k<0)
			y=abs(k);
			else
			y=-abs(k);
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(sqrt(4*a*(-y-k))+h,-y);            //ptr=realxy(-x,sqrt(4*a*(-x-h))+k);
				arrofcoord1[counter][0]=ptr[0];
				arrofcoord1[counter][1]=ptr[1];
				counter++;
				y++;
			}
			counter=0;
	    	if(k<0)
			y=abs(k);
			else
			y=-abs(k);
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(-1*sqrt(4*a*(-y-k))+h,-y);
				arrofcoord2[counter][0]=ptr[0];
				arrofcoord2[counter][1]=ptr[1];
				counter++;
				y++;
			}
		}
		break;

	}//switch ends
	CircleShape c(1,30);
	Font f1,f2;f2.loadFromFile("KBSticktoIt.ttf");
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
counter=0;
Text t5("PARABOLA CREATED!!",f2,20);
t5.move(Vector2f(10,10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       c.setPosition(arrofcoord1[counter][0],arrofcoord1[counter][1]);
       window.draw(c);
       c.setPosition(arrofcoord2[counter][0],arrofcoord2[counter][1]);
       window.draw(c);
	  window.display();
	  counter++;

	  this_thread::sleep_for(chrono::milliseconds(1));
	  if(counthold==counter)
      {
          window.draw(t5);
          window.display();
          getch();
          break;
      }
    }
}
    void plotcircle(int h,int k,int r)//graphics //by uzair
{//equation of circle (x - h)^2 + (y - k)^2 = r^2
	int *ptr,*nptr;float *mptr;float x; int y=0;char coord[50];
	Font f1,f2;f2.loadFromFile("KBSticktoIt.ttf");
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));

 Text t5("NOTE:R is the radius and C is the center",f2,20);
 t5.move(Vector2f(10,10));
	ptr=realxy(h,k);
	while(1)
	{
	 errno=0;
	 x=sqrt(pow(r,2)-pow(y-k,2))+h;//finding a point on circumference first using intercept
	 if(errno==0)//if error occurs in sqrt function then
	 break;
	 y=(rand()%400)-200;//another y value is generated to find a intercept without causing error in sqrt function
    }// this loop will run until a suitable point on the circle is found
    CircleShape drawc(r,100);
    drawc.setOutlineColor(Color::White);
    drawc.setOutlineThickness(1);
    drawc.setFillColor(Color::Black);
    drawc.setPosition(ptr[0]-r,ptr[1]-r);
    sprintf(coord,"C (%d,%d)",h,k);
    Text t6(coord,f1,15);
    t6.move(Vector2f(ptr[0]+10,ptr[1]+10));
	nptr=realxy(x,y);
	Vertex linetoc[2];
	linetoc[0]=Vertex(Vector2f(ptr[0],ptr[1]));
	linetoc[1]=Vertex(Vector2f(nptr[0],nptr[1]));
	linetoc[0].color=Color::Red;
	linetoc[1].color=Color::White;
	mptr=calculations::midpointc(ptr[0],ptr[1],nptr[0],nptr[1]);
	sprintf(coord,"R %0.0f units",calculations::disc(ptr[0],ptr[1],nptr[0],nptr[1]));
	Text t7(coord,f1,15);
	t7.move(Vector2f(mptr[0]+10,mptr[1]+10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        Event event;
        while (window.pollEvent(event))
        {
          if (event.type == Event::Closed)
          window.close();
          else if(event.type==Event::KeyPressed)
          {
              if(event.key.code==Keyboard::Enter)
                window.close();
          }
        }
        window.clear();
        Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};

        window.draw(drawc);
         window.draw(t5);
        window.draw(linetoc,2,Lines);
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.draw(t4);
        window.draw(line, 2, Lines);
        line[0]=Vertex(Vector2f(xh,0));
        line[1]=Vertex(Vector2f(xh,ymax));
        window.draw(line,2,Lines);
        window.draw(t6);
        window.draw(t7);
	    window.display();
	    getch();

}
  /*  void plottingcircle(float h,float k,float r)//graphics by arsalan
    {
        Font f1;
  f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
    CircleShape circle;
    intptr=calculations::realxy(h,k);
        circle.setRadius(r);
      circle.setFillColor(Color::Transparent);
      circle.setOutlineThickness(3);
      circle.setOutlineColor(Color::White);
        circle.setPosition(Vector2f(intptr[0]-r,intptr[1]-r));
     sprintf(co,"C(%.f,%.f)",h,k);
        Text t5(co,f1,12);
        t5.move(Vector2f(intptr[0],intptr[1]+5));
       Vertex centerline[]={Vertex(Vector2f(intptr[0],intptr[1])),Vertex(Vector2f(intptr[0]+r,intptr[1]-20))};
       centerline[0].color=Color::Yellow;
       centerline[1].color=Color::Cyan;
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        while(window.isOpen())
        {
            Event event;
          while(window.pollEvent(event))
          {
              if(event.type==Event::Closed)
                window.close();
          }
          window.clear();
            Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      Vertex line1[] ={Vertex(Vector2f(xh,0)),Vertex(Vector2f(xh, ymax))};
      window.draw(line1, 2, Lines);
            window.draw(t1);
            window.draw(t2);
            window.draw(t3);
            window.draw(t4);
            window.draw(circle);
            window.draw(t5);
        window.draw(centerline,2,Lines);
        window.display();
        }
}*/
void plottingellipse(float h,float k,float a,float b)
{
        CircleShape ellipse;int r=50;
        ellipse.scale(a,b);
        ellipse.setRadius(r);
        intptr=calculations::realxy(h,k);
        ellipse.move(Vector2f(intptr[0]-r*a,intptr[1]-r*b));
        ellipse.setFillColor(Color::Transparent);
    ellipse.setOutlineColor(Color::White);
    ellipse.setOutlineThickness(1);sprintf(co,"C(%.f,%.f)",h,k);
    //Vertex  line6[]={Vertex(Vector2f(intptr[0]+100,intptr[1])),Vertex(Vector2f(intptr[0]+100,intptr[1]+yh)) };
    Vertex line5[]={Vertex(Vector2f(intptr[0]-r*a,intptr[1])),Vertex(Vector2f(intptr[0]+r*a,intptr[1])) };
    Vertex line4[] ={Vertex(Vector2f(intptr[0],intptr[1]-r*b)),Vertex(Vector2f(intptr[0], intptr[1]+r*b))};
line4[0].color=Color::Red;line4[1].color=Color::Red;
      line5[0].color=Color::Cyan;
    line5[1].color=Color::Cyan;
    Font f1,f2;f2.loadFromFile("KBSticktoIt.ttf");
  f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));
 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
 Text t5(co,f1,12);
 t5.move(Vector2f(intptr[0]+3,intptr[1]+3));
 Text t6("Ellipse Created!!",f2,15);
 t6.move(Vector2f(10,10));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      Vertex line1[] ={Vertex(Vector2f(xh,0)),Vertex(Vector2f(xh, ymax))};
      window.draw(line1, 2, Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       window.draw(ellipse);
       window.draw(t5);
      window.draw(t6);
       window.draw(line4,2,Lines);window.draw(line5,2,Lines);
        window.display();
        getch();
    }
void quadlit(int value)//lits up the quadrant in which point lies
{
	Vertex line2[2];Font f1;
  f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed | event.type==Event::KeyPressed)
                window.close();
        }
        window.clear();
        switch(value)
	{
		case(1):

		    for(a=yh;a>=0;a--)
		    {
             line2[0]=Vertex(Vector2f(xh,a),Color::Yellow);
             line2[1]=Vertex(Vector2f(xmax, a),Color::Red);
             window.draw(line2, 2, Lines);
		    }
		    break;
		case(2):
			for(a=yh;a>=0;a--)
			 {
             line2[0]=Vertex(Vector2f(0,a));
             line2[1]=Vertex(Vector2f(xh, a));
             line2[0].color=Color::Red;
             line2[1].color=Color::Yellow;
             window.draw(line2, 2, Lines);

              }
			break;
		case(3):
			for(a=yh;a<=ymax;a++)
			 {
             line2[0]=Vertex(Vector2f(0,a),Color::Red);
             line2[1]=Vertex(Vector2f(xh, a),Color::Red);
             window.draw(line2, 2, Lines);
		     }
			break;
		case(4):
		    for(a=yh;a<=ymax;a++)
			 {
             line2[0]=Vertex(Vector2f(xh,a),Color::Red);
             line2[1]=Vertex(Vector2f(xmax, a),Color::Red);
             window.draw(line2, 2, Lines);
		    }
			break;
	}
	 Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      Vertex line1[] ={Vertex(Vector2f(xh,0)),Vertex(Vector2f(xh, ymax))};
      window.draw(line1, 2, Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
	  window.display();
      getch();
}
void midplot(float x1,float y1,float x2,float y2,float *ptr)
{
 Font f1;
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));

 intptr=realxy(ptr[0],ptr[1]);
 sprintf(co,"(%0.1f,%0.1f)",ptr[0],ptr[1]);
 Text t5(co,f1,15);
 t5.move(Vector2f(intptr[0]+20,intptr[1]+20));
    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        Event event;
        while (window.pollEvent(event))
        {
          if (event.type == Event::Closed | event.type==Event::KeyPressed)
          window.close();
        }
        window.clear();
        Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
        window.draw(line, 2, Lines);
        line[0]=Vertex(Vector2f(xh,0));
        line[1]=Vertex(Vector2f(xh,ymax));
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.draw(t4);
        window.draw(t5);
        window.draw(line,2,Lines);
        intptr=calculations::realxy(x1,y1);
        line[0]=Vertex(Vector2f(intptr[0],intptr[1]));
        intptr=calculations::realxy(x2,y2);
        line[1]=Vertex(Vector2f(intptr[0],intptr[1]));
        window.draw(line,2,Lines);
	    window.display();
	    getch();
}
void displot(float x1,float y1,float x2,float y2,float dist)
{
    Font f1;
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));

 sprintf(co,"%0.2f units",dist);
 float *fptr=calculations::midpointc(x1,y1,x2,y2);
 ptr=calculations::realxy(fptr[0],fptr[1]);
 Text t5(co,f1,15);
 t5.move(Vector2f(ptr[0]+10,ptr[1]+10));

    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed | event.type==Event::KeyPressed)
                window.close();
        }
        window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       ptr=calculations::realxy(x1,y1);
      line[0]=Vertex(Vector2f(ptr[0],ptr[1]));
       ptr=calculations::realxy(x2,y2);
      line[1]=Vertex(Vector2f(ptr[0],ptr[1]));
      line[0].color=Color::Red;
      line[1].color=Color::Yellow;
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       window.draw(t5);
	  window.display();
       getch();
}
void twoeqplot(float cx1,float cy1,float const1,float cx2,float cy2,float const2)// bugsss fix it use pixel array
{
    Font f1;
    f1.loadFromFile("calibri.ttf");
    int fil=0,f2=0,f3=0,f4=0;
    Vertex line1[2],line2[2];int **coordptr1,**coordptr2,**coordptr3,**coordptr4,counter=0,counterhold1=0,counterhold2=0,counterhold3=0,counterhold4=0;
	x=0;
	if(cy1!=0)
	{
	    fi1++;
    while(1)
    {
	ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	if(ptr[0]<=0)
	break;
	counter++;
	x--;
    }
    counterhold1=counter;
    coordptr1=new int*[counter+5];
    for(int a=0;a<counter+5;a++)
    coordptr1[a]=new int[2];
    counter=0;
    x=0;
    while(1)
    {
	ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	if(ptr[0]<=0)
	break;
	coordptr1[counter][0]=ptr[0];
	coordptr1[counter][1]=ptr[1];
	counter++;
	x--;
    }
    counter=0;
    x=0;
    while(1)
    {
    ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	if(ptr[0]>=xmax)
	break;
	counter++;
	x++;
    }
    counterhold2=counter;
    coordptr2=new int*[counter+5];
    for(int a=0;a<counter+5;a++)
    coordptr2[a]=new int[2];
    counter=0;
    x=0;
    while(1)
    {
    ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	if(ptr[0]>=xmax)
	break;
	coordptr2[counter][0]=ptr[0];
	coordptr2[counter][1]=ptr[1];
	counter++;
	x++;
    }
    }
    else
    {
    f2++;
    x=-const1/cx1;                                          //y12=(-1*(const1)+(-1*(cx1*(x2))))/cy1;
    ptr=realxy(x,0);
    line1[0]=Vertex(Vector2f(ptr[0],0));
    line1[0]=Vertex(Vector2f(ptr[0],ymax));   //line(ptr[0],0,ptr[0],ymax);
	}
//****************************************//
    x=0;
    counter=0;
    if(cy2!=0)
	{
	    f3++;
    while(1)
    {
    ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	if(ptr[0]<=0)
	break;
	counter++;
	x--;
    }
    counterhold3=counter;
    coordptr3=new int*[counter+5];
    for(int a=0;a<counter+5;a++)
    coordptr3[a]=new int[2];
    counter=0;
    x=0;
    while(1)
    {
    ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	if(ptr[0]<=0)
	break;
	coordptr3[counter][0]=ptr[0];
	coordptr3[counter][1]=ptr[1];
	counter++;
	x--;
    }
    counter=0;
    x=0;
    while(1)
    {
    ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	if(ptr[0]>=xmax)
	break;
	counter++;
	x++;
    }
    counterhold4=counter;
    coordptr4=new int*[counter+5];
    for(int a=0;a<counter+5;a++)
    coordptr4[a]=new int[2];
    counter=0;
    x=0;
    while(1)
    {
    ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	if(ptr[0]>=xmax)
	break;
	coordptr4[counter][0]=ptr[0];
	coordptr4[counter][1]=ptr[1];
	counter++;
	x++;
    }
    counter=0;
    x=0;
    }
    else
    {
    f4++;
    x=-const2/cx2;                                          //y12=(-1*(const1)+(-1*(cx1*(x2))))/cy1;
    ptr=realxy(x,0);
    line2[0]=Vertex(Vector2f(ptr[0],0));
    line2[1]=Vertex(Vector2f(ptr[0],ymax));                //line(ptr[0],0,ptr[0],ymax);
	}
	getch();

CircleShape c1(1,30),c2(1,30),c3(1,30),c4(1,30);
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));

 Text t5("LINES PLOTTED",f1,20);
t5.move(Vector2f(10,10));

RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed | event.type==Event::KeyPressed)
                window.close();
        }
        window.clear();
      if(fi1>0)//pixel array
      {
         for(int a=0;a<counterhold1;a++)
         {
              c1.setPosition(Vector2f(coordptr1[a][0],coordptr1[a][1]));
              window.draw(c1);
              Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
              window.display();
              a++;
          }
          for(int a=0;a<counterhold2;a++)
         {
              c2.setPosition(Vector2f(coordptr2[a][0],coordptr2[a][1]));
               window.draw(c2);
               Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
              window.display();
              a++;
          }
      }
      if(f2>0)//line
      {
          window.draw(line1,2,Lines);
          Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
          window.display();
      }
      if(f3>0)//pixel array
      {
          for(int a=0;a<counterhold3;a++)
         {
              c3.setPosition(Vector2f(coordptr3[a][0],coordptr3[a][1]));
              window.draw(c3);
              Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
              window.display();
              a++;
          }
          for(int a=0;a<counterhold4;a++)
         {
              c4.setPosition(Vector2f(coordptr4[a][0],coordptr4[a][1]));
               window.draw(c4);
               Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
              window.display();
              a++;
          }
      }
      if(f4>0)//line
      {
        window.draw(line2,2,Lines);
        Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2, Lines);
      window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
        window.display();

      }
     window.draw(t5);
     window.display();
     getch();
     window.close();
}
void slopeplot(float x1,float y1,float x2,float y2,float slop)
{
    Font f1;
 f1.loadFromFile("calibri.ttf");
 Text t1("-X",f1,15);
 t1.move(Vector2f(0,yh+2));

 Text t2("+X",f1,15);
 t2.move(Vector2f(xmax-20,yh));

 Text t3("+Y",f1,15);
 t3.move(Vector2f(xh+2,0));

 Text t4("-Y",f1,15);
 t4.move(Vector2f(xh+2,ymax-20));

 sprintf(co,"M %0.2f units",slop);
 float *fptr=calculations::midpointc(x1,y1,x2,y2);
 ptr=calculations::realxy(fptr[0],fptr[1]);
 Text t5(co,f1,15);
 t5.move(Vector2f(ptr[0]+10,ptr[1]+10));

    RenderWindow window(VideoMode(xmax, ymax), "PLOTTER");

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed | event.type==Event::KeyPressed)
                window.close();
        }
        window.clear();
         Vertex line[] ={Vertex(Vector2f(0,yh)),Vertex(Vector2f(xmax, yh))};
      window.draw(line, 2, Lines);
      line[0]=Vertex(Vector2f(xh,0));
      line[1]=Vertex(Vector2f(xh,ymax));
      window.draw(line,2,Lines);
       ptr=calculations::realxy(x1,y1);
      line[0]=Vertex(Vector2f(ptr[0],ptr[1]));
       ptr=calculations::realxy(x2,y2);
      line[1]=Vertex(Vector2f(ptr[0],ptr[1]));
      window.draw(line,2,Lines);
       window.draw(t1);
       window.draw(t2);
       window.draw(t3);
       window.draw(t4);
       window.draw(t5);
	  window.display();
      getch();
}
};
class quadrant:public graphics
{

    int quad;float x,y;string cho;
public:
      quadrant(float x,float y,string cho,ofstream& log)
      {
          this->x=x;
          this->y=y;
          this->cho=cho;
           identifyquad(log);
           disp();
      }
    void identifyquad(ofstream& log)
    {
			if((round(x))>=0 && (round(y)>=0))
                {
                    quad=1;
            log<<"\npoint lies in 1st quadrant with values:("<<x<<","<<y<<")";
                }
			else if((round(x))<=0 && (round(y)>=0))
                {
                    quad=2;
            log<<"\npoint lies in 2nd quadrant with values:("<<x<<","<<y<<")";
                }
			else if((round(x))<=0 && (round(y)<=0))
                {
                    quad=3;
            log<<"\npoint lies in 3rd quadrant with values:("<<x<<","<<y<<")";
                }
			else
                {
                    quad=4;
            log<<"\npoint lies in 4th quadrant with values:("<<x<<","<<y<<")";
                }
    }
    void disp(void)
    {
        switch(quad)
        {
        case(1):
            cout<<"\npoint lies in 1st quadrant with values:("<<x<<","<<y<<")";
            break;
        case(2):
            cout<<"\npoint lies in 2nd quadrant with values:("<<x<<","<<y<<")";
            break;
        case(3):
            cout<<"\npoint lies in 3rd quadrant with values:("<<x<<","<<y<<")";
            break;
        case(4):
            cout<<"\npoint lies in 4th quadrant with values:("<<x<<","<<y<<")";
            break;
        }
        if(cho=="yes")
        {
         graphics::quadlit(quad);
        }
    }
    ~quadrant(){}
};
class midpoint:public graphics
{
    float x1,x2,y1,y2;string cho;float *ptr;
    void disp(ofstream& log)
    {
     cout<<setprecision(2);
     cout<<"\nmid point lies at ("<<ptr[0]<<","<<ptr[1]<<")";
     log<<"\nmid point lies at ("<<ptr[0]<<","<<ptr[1]<<")";
     if(cho=="yes")
     graphics::midplot(x1,y1,x2,y2,ptr);
    }
   public:
    midpoint(float x1,float y1,float x2,float y2,string choice,ofstream& log)
    {
     this->x1=x1;
     this->x2=x2;
     this->y1=y1;
     this->y2=y2;
     cho=choice;
     ptr=calculations::midpointc(x1,y1,x2,y2);
     disp(log);
    }
};
class dist:public graphics
{
     float x1,x2,y1,y2;string cho;float *ptr;
     void disp(ofstream& log)
     {
      cout<<"\ndistance is "<<calculations::disc(x1,y1,x2,y2);
      log<<"\ndistance is "<<calculations::disc(x1,y1,x2,y2);
      if(cho=="yes")
      graphics::displot(x1,y1,x2,y2,disc(x1,y1,x2,y2));
     }
 public:
    dist(float x1,float y1,float x2,float y2,string choice,ofstream& log)
    {
     this->x1=x1;
     this->x2=x2;
     this->y1=y1;
     this->y2=y2;
     cho=choice;
     disp(log);
    }
};
class twoeq:public graphics
{
    float cons1,cons2,x1,x2,y1,y2;string cho;
    float *poixy;
    void disp(ofstream &log)
    {
     poixy=calculations::poi(x1,y1,cons1,x2,y2,cons2);
     cout<<"\npoint of intersection lies at ("<<poixy[0]<<","<<poixy[1]<<")";
     log<<"\npoint of intersection lies at ("<<poixy[0]<<","<<poixy[1]<<")";
     if(cho=="yes")
     graphics::twoeqplot(x1,y1,cons1,x2,y2,cons2);
    }
public:
    twoeq(float x1,float y1,float cons1,float x2,float y2,float cons2,string cho,ofstream &log)
    {
     this->x1=x1;
     this->x2=x2;
     this->y1=y1;
     this->y2=y2;
     this->cons1=cons1;
     this->cons2=cons2;
     this->cho=cho;
     disp(log);
    }
};
class slope:public graphics
{
    float x1,x2,y1,y2;string cho;
    void disp(ofstream &log)
    {
        cout<<"\nslope of ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is "<<calculations::slopec(x1,y1,x2,y2);
        log<<"\nslope of ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is "<<calculations::slopec(x1,y1,x2,y2);
        if(cho=="yes")
            graphics::slopeplot(x1,y1,x2,y2,calculations::slopec(x1,y1,x2,y2));
    }
public:
    slope(float x1,float y1,float x2,float y2,string choice,ofstream& log)
    {
      this->x1=x1;
      this->x2=x2;
      this->y1=y1;
      this->y2=y2;
      cho=choice;
      disp(log);
    }
};
/*class plotcircle:public graphics //made by arsalan
{
private:
    float h,k,r;
public:
    plotcircle(float h1=0,float k1=0,float r1=0)
    {
        h=h1;k=k1;r=r1;
    }
    bool check()
    {
        if(r==0||r<0)
        {
            return true;
        }
        return false;

    }
    void display()
    {

        graphics::plottingcircle(h,k,r);
    }
};*/
class circle:public graphics  //made by uzair
{
    int H,K,R;
    void disp(ofstream &log)
    {
        graphics::plotcircle(H,K,R);
        log<<"\ncircle plotted using vlaues h="<<H<<" k="<<K<<" r="<<R;
    }
public:
    circle(int h,int k,int r,ofstream &log)
    {
      H=h;
      K=k;
      R=r;
      disp(log);
    }
};
class ellipse:public graphics
{
private:
    float h,k,a,b;
public:
    ellipse(float h,float k,float a,float b)
    {
        this->h=h;this->a=a;
        this->k=k;this->b=b;
    }
    void display()
    {
        graphics::plottingellipse(h,k,a,b);
    }
};
class hyperbola:public graphics
{
private:
    float h,k,a,b;
    void display(int cho,ofstream &log)
    {
        graphics::plothyperbola(h,k,a,b,cho);
        log<<"\nhyperbola plotted using values h="<<h<<" k="<<k<<" a="<<a<<" and b="<<b;
    }
public:
    hyperbola(float h,float k,float a,float b,int cho,ofstream &log)
    {
        this->h=h;this->k=k;this->a=a;this->b=b;
        display(cho,log);
    }
};
class graphingpoly:public graphics
{
private:
    void display(int cho,ofstream &log)
    {
    graphics::plotpolynomial(cho,log);
    }
public:
    graphingpoly(int ch,ofstream &log)
    {
    display(ch,log);
    }

};
class parabola:public graphics
{
    float A;int CHO,H,K;
    void disp(ofstream &log)
    {
        graphics::plotparabola(H,K,A,CHO);
        log<<"\nparabola plotted using values h="<<H<<" k="<<K<<" and a="<<A;
    }
public:
    parabola(int h,int k,float a,int cho,ofstream &log)
    {
        A=a;
        K=k;
        H=h;
        CHO=cho;
        disp(log);
    }
};
int main()
{
    string choice;float x,y,x1,x2,y1,y2;
    scientificcalculator calcusimple;calculations graphicscalcu;
    time_t crrtm;ofstream log;cursor cursor1;
    log.open("calculator_log.txt",ios::app);
    crrtm=time(NULL);
    char *time=ctime(&crrtm);
    log<<"\n\n************************************************************";
    log<<"\n\t\t\tSESSION START";
    log<<"\n\t\t "<<time<<"\nLOG:";
    char bar=219;char barr=177;
    cout<<"\n\n\n\t\t\t\t\tLOADING...PLEASE WAIT\n\n\n\t\t\t\t\t";
    int percent=0;
    for(int i=1;i<=25;i++)
    {

        cout<<barr;

    }
    cursor1.gotoxy(67,6);
    cout<<percent<<" %";

    cursor1.gotoxy(40,6);
int cursor=41;
    for(int i=1;i<=25;i++)
    {

        cout<<bar;
        if(i>18&&i!=25)
        {
           cursor1.gotoxy(67,6);
        percent+=1;
        cout<<percent<<" %";



        }
        else if(i%2==0&&i<=18)
        {
        cursor1.gotoxy(67,6);
        percent+=10;
        cout<<percent<<" %";

        }
        else if(i==25)
        {
            cursor1.gotoxy(67,6);
        percent=100;
        cout<<percent<<" %";
        }
        cursor1.gotoxy(cursor,6);
        cursor++;
        Sleep(200);
    }

    projectstart:
    system("cls");
    cout<<"\t\t"<<time<<"\t\t\tWelcome\nPlease Select From Following:";
	cout<<"\n\tlocation on the plane"<<"\n\tfind distance "<<"\n\tfind midpoint "<<"\n\tverify 2 points when distace is given "<<"\n\tfind point of intersection of the two lines ";
    cout<<"\n\tfind slope of two points ";
    cout<<"\n\tfind angle between two lines ";
    cout<<"\n\tdraw circle ";
    cout<<"\n\tdraw parabola ";
    cout<<"\n\tdraw ellipse ";
    cout<<"\n\tdraw hyperbola ";
    cout<<"\n\tdraw a graph from polynomial ";
    cout<<"\n\tenter into scientific calculator module ";
    cout<<"\n\texit from program ";
	int X=3;cursor1.gotoxy(0,X,"->");char a;char enter='\r';
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
    	    if(X==16)
			{
				continue;
				}
				else
				{
            cursor1.gotoxy(0,X,"  ");
    		cursor1.gotoxy(0,X+1,"->");
    		X++;
    	}
}
		else if(a==72)
		{
			if(X==3)
			{
				continue;
			}
			else{
          cursor1.gotoxy(0,X,"  ");
			cursor1.gotoxy(0,X-1,"->");
			X--;
		}
		}
		else if(a==75||a==77)
		{
			continue;
		}

	}
	int cho;
    cho=X-2;
	cursor1.gotoxy(0,18);
	cursor1.ShowConsoleCursor(true);
    log<<"\nchoice selected:"<<cho;
	switch(cho)
	{
	    case 1:
	        {
            cout<<"enter value of x & y:";
			cin>>x>>y;
			cout<<"\ndo you want pictorial representation ";
			cin>>choice;
			quadrant q(x,y,choice,log);
			cout<<"Press Any key to continue!!!!"<<endl;
            getch();
            goto projectstart;
            }
		    break;
        case 2:
            {
			cout<<"enter value of x1 y1 x2 y2:";
			cin>>x1>>y1>>x2>>y2;
			cout<<"\ndo you want a pictorial representation ";
			cin>>choice;
			dist d(x1,y1,x2,y2,choice,log);
            }
			break;
        case 3:
            {
			cout<<"enter value of x1 y1 x2 y2 ";
			cin>>x1>>y1>>x2>>y2;
			cout<<"\ndo you want a pictorial representation ";
			cin>>choice;
			midpoint m(x1,y1,x2,y2,choice,log);
            }
			break;
        case 4:
            {
              float distan;calculations dc;
		      cout<<"enter value of distance and coordinates x1: y1: x2: y2:";
		      cin>>distan>>x1>>y1>>x2>>y2;
		      if (distan==dc.disc(x1,y1,x2,y2))
		          {
		      cout<<"\nthese points A("<<x1<<","<<y1<<") and B("<<x2<<","<<y2<<") verify the distance of "<<distan<<" units";
		      log<<"\nthese points A("<<x1<<","<<y1<<") and B("<<x2<<","<<y2<<") verify the distance of "<<distan<<" units";
	              }
		      else

		          {
		      cout<<"\nthese points A("<<x1<<","<<y1<<") and B("<<x2<<","<<y2<<") do not verify the distance of "<<distan<<" units";
		      log<<"\nthese points A("<<x1<<","<<y1<<") and B("<<x2<<","<<y2<<") do not verify the distance of "<<distan<<" units";
		          }
		          cout<<"\nPress Any key to continue!!!!"<<endl;
               getch();
            }
            break;
        case 5:
            {
              float cons1,cons2;
              cout<<"enter values of equation 1 only numbers (co-eff of x then co-eff of y then constant):";
		      cin>>x1>>y1>>cons1;
              cout<<"\nenter values of equation 2 only numbers (co-eff of x then co-eff of y then constant):";
              cin>>x2>>y2>>cons2;
		      cout<<"\ndo you want a pictorial representation ";
			  cin>>choice;
		      twoeq t(x1,y1,cons1,x2,y2,cons2,choice,log);
	        }
	        break;
        case 6:
	          {
               cout<<"\n enter value of x1 y1 x2 y2 ";
               cin>>x1>>y1>>x2>>y2;
               cout<<"\ndo you want a pictorial representation ";
               cin>>choice;
               slope s(x1,y1,x2,y2,choice,log);
	          }
            break;
        case 7:
            {
                system("cls");
                float x1,x2,x3,x4,y1,y2,y3,y4;
                cout<<"Enter The values of following:\nX1: ";cin>>x1;cout<<"X2: ";cin>>x2;cout<<"X3: ";cin>>x3;
                cout<<"X4: ";cin>>x4;cout<<"Y1: ";cin>>y1;cout<<"Y2: ";cin>>y2;cout<<"Y3: ";cin>>y3;
                cout<<"Y4: ";cin>>y4;
                float result=graphicscalcu.angle(x1,x2,x3,x4,y1,y2,y3,y4);
                cout<<"The Angle is: "<<result<<endl;
                 log<<"\nThe Angle is: "<<result;
                 cout<<"Press Any key to continue!!!!"<<endl;
               getch();
            }
             break;
        case 8://ploting circle
            {
                circlestart:
                system("cls");float h,k,r;
                cout<<"Enter the values of h,k,r where h and k are center points and r stands for radius: "<<endl;
                cout<<"H= :";
                cin>>h;
                cout<<"K= :";
                cin>>k;
                cout<<"R= :";
                cin>>r;
                circle c(h,k,r,log);
               // plotcircle circle(h,k,r);
                /*if(circle.check())
                {
                    cout<<"Invalid Radius!!!";
                    goto circlestart;
                }
                circle.display();
                log<<"\nCircle Formed with Center at: "<<h<<","<<k;*/
                cout<<"Press Any key to continue!!!!"<<endl;
               getch();
            }
            break;
            case 9://parabola
            {
                float a;int choi,h,k;
		    	cout<<"\nThere are two equations of parabola\n1 (y-k)^2=4a(x-h)\n2 (x-h)^2=4a(y-k)\nnow press respective number1 to draw parabola ";
		    	cin>>choi;
		    	cout<<"\nenter value of 'a' ";
		    	cin>>a;
		    	printf("\nenter value of 'h' (enter 0 if h is not available) ");fflush(stdin);
		    	cin>>h;
		    	printf("\nenter value of 'k' (enter 0 if k is not available) ");fflush(stdin);
		    	cin>>k;
		    	parabola p(h,k,a,choi,log);
            }
            break;
        case 10://plot elipse
            {
                system("cls");int choice;
                cout<<"There are two equations of ellipse\n\t1 (x-h)^2/a^2+(y-k)^2/b^2=1\n\t2 (x-h)^2/b^2+(y-k)^2/a^2=1"<<endl;
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
			        else
                    {
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
               choice=x;
             log<<"\nchoice "<<x<<" selected from ellipse menu";
	         cursor1.gotoxy(0,3);
            cursor1.ShowConsoleCursor(true);
	        float h,k,a2,b;
	        cout<<"Enter h: ";cin>>h;
	        cout<<"Enter K: ";cin>>k;fflush(stdin);
	        cout<<"Enter a: ";fflush(stdin);cin>>a2;
	        cout<<"Enter b: ";fflush(stdin);cin>>b;
	        if((choice==1))
            {

                if(b>a2||a2==b)
                {
                    cout<<"Ellipse Not Possible Follow condition (a>b)"<<endl;
                    cout<<"Renter a: ";cin>>a2;
	                cout<<"Renter b: ";cin>>b;

                }
            }
            else if(choice==2)
            {
                if(a2>b||a2==b)
                {
                    cout<<"Ellipse Not Possible Follow condition (b>a)"<<endl;
                    cout<<"Renter a: ";cin>>a2;
	                cout<<"Renter b: ";cin>>b;
                }

            }
	        ellipse elip(h,k,a2,b);
            elip.display();
            log<<"\nEllipse formed at h="<<h<<" k="<<k<<" a="<<a2<<" b="<<b;
   cout<<"Press Any key to continue!!!!"<<endl;
               getch();
               goto projectstart;
            }
            break;
            case 11:
            {
             system("cls");float h,k;int cho;float a,b;
             cout<<"There are two equations of hyperbola\n1 (x-h)^2/a^2-(y-k)^2/b^2=1\n2 (y-k)^2/a^2-(x-h)^2/b^2=1\nnow press respective number1 to draw hyperbola"<<endl;
                cin>>cho;
                cout<<"Enter the value of H: ";
                cin>>h;
                cout<<"Enter the value of K: ";
                cin>>k;
                cout<<"Enter the value of a: ";
                cin>>a;
                cout<<"Enter the value of b: ";
                cin>>b;
                if(a<=0||b<=0)
                {
                    cout<<"\nINvalid Inputs!!!!"<<endl;
                    cout<<"Renter the value of a: ";fflush(stdin);
                    cin>>a;
                    cout<<"Renter the value of b: ";fflush(stdin);
                    cin>>b;
                }
                hyperbola hyp(h,k,a,b,cho,log);
            }
            break;
         case 12:
            {
                system("cls");int cho;polystart:
                cout<<"Please Enter the Degree of equation:(Max=4 Min=1) "<<endl;
                cin>>cho;
                try{
                    if(cho>=1&&cho<=4)
                        throw cho;
                    else
                    {
                        cout<<"Wrong Input!!!Please Renter"<<endl;
                        goto polystart;
                    }

                }
                catch(int cho)
                {
                    graphingpoly poly(cho,log);

                }
            }
            break;



        case 13:
            {

                start2:
                system("cls");
                cout<<"\t\tWELCOME TO SCIENTIFIC CALCULATOR MODULE"<<endl;
				cout<<"\n\t 1.Addition";
				cout<<"\n\t 2.Subtraction";
				cout<<"\n\t 3.Multiplication";
				cout<<"\n\t 4.Division";
				cout<<"\n\t 5.Find factorial";
				cout<<"\n\t 6.Find log";
				cout<<"\n\t 7.Find sin(x)";
				cout<<"\n\t 8.Find cos(x)";
				cout<<"\n\t 9.Find tan(x)";
				cout<<"\n\t 10.Find cot(x)";
				cout<<"\n\t 11.Find sec(x)";
				cout<<"\n\t 12.Find cosec(x)";
				cout<<"\n\t 13.Find sin^-1(x)";
				cout<<"\n\t 14.Find cos^-1(x)";
				cout<<"\n\t 15.Find tan^-1(x)";
				cout<<"\n\t 16.Find cosec^-1(x)";
				cout<<"\n\t 17.Find sec^-1(x)";
				cout<<"\n\t 18.Find cot^-1(x)";
				cout<<"\n\t 19.Find nCr";
				cout<<"\n\t 20.Find nPr";
				cout<<"\n\t 21.Find determinant of a matrix (2x2) or (3x3)";                                   //incomplete
				cout<<"\n\t 22.Check weather given matrix is identity matrix or not ";
				cout<<"\n\t 23.Find transpose of a matrix";
				cout<<"\n\t 24.Find power of any number";
				cout<<"\n\t 25.Find root of a number (enter positive values only else there will be an error!!)";
				cout<<"\n\t 26.Go back";
				cout<<"\n\t 27.Exit";
				int cho;
				 int x=2;cursor1.gotoxy(0,x,"->");char a;char enter='\r';
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
    	    if(x==28)
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
			if(x==2)
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

    cho=x-1;
	cursor1.gotoxy(0,29);
	cursor1.ShowConsoleCursor(true);
                     log<<"\nOption "<<cho<<" Selected from the menu of scientific calculator";
	       switch(cho)
	       {
	           case 1:
           {
               system("cls");
               float x,y;
               cout<<"Enter  Value of X: "<<endl;
               cin>>x;
               cout<<"Enter Value of Y: "<<endl;
               cin>>y;
               float result=calcusimple.add(x,y);
               cout<<fixed;
               cout<<"\nSum of X= "<<x<<" Y="<<y<<" is : "<<result<<endl;
               log<<"\nSum of X= "<<x<<" Y="<<y<<" is : "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
           break;
          case 2:
           {
               system("cls");
               float x,y;
               cout<<"Enter  Value of X: "<<endl;
               cin>>x;
               cout<<"Enter Value of Y: "<<endl;
               cin>>y;
               float result=calcusimple.subtract(x,y);
               cout<<fixed;
               cout<<"\nDifference of X= "<<x<<" Y="<<y<<" is : "<<result<<endl;
               log<<"\nDifference of X= "<<x<<" Y="<<y<<" is : "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 3:
           {
               system("cls");
               float x,y;
               cout<<"Enter  Value of X: "<<endl;
               cin>>x;
               cout<<"Enter Value of Y: "<<endl;
               cin>>y;
               float result=calcusimple.multiply(x,y);
               cout<<fixed;
               cout<<"\nMultiplication of X= "<<x<<" Y="<<y<<" is : "<<result<<endl;
               log<<"\nMultiplication of X= "<<x<<" Y="<<y<<" is : "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 4:
           {
               system("cls");
               float x,y;
               cout<<"Enter  Value of X: "<<endl;
               cin>>x;
               cout<<"Enter Value of Y: "<<endl;
               cin>>y;
               float result=calcusimple.divide(x,y);
               cout<<fixed;
               cout<<"\nDivision of X= "<<x<<" Y="<<y<<" is : "<<result<<endl;
               log<<"\nDivision of X= "<<x<<" Y="<<y<<" is : "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 5:
           {
               system("cls");
               long int num;
               cout<<"Enter the number of which you want to calculate factorial of: "<<endl;
               cin>>num;
               long long int result=calcusimple.factorial(num);
               cout<<"Factorial is: "<<result<<endl;
               log<<"\nFactorial of Number "<<num<<" is :"<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 6:
           {
               system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.logarithm(x);
               cout<<"Logarithm = "<<result<<endl;
               log<<"\nLogarithm of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 7:
           {
               system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.sine(x);
               cout<<"Sine() = "<<result<<endl;
               log<<"\nSine of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 8:
           {
               system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cosine(x);
               cout<<"Cosine() = "<<result<<endl;
               log<<"\nCosine of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 9:
           {
               system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.tangent(x);
               cout<<"Tangent() = "<<result<<endl;
               log<<"\nTangent of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 10:
           {
               system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cotangent(x);
               cout<<"Cotangent() = "<<result<<endl;
               log<<"\nCotangent of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 11:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.sec(x);
               cout<<"Secant() = "<<result<<endl;
               log<<"\nSecant of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 12:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cosec(x);
               cout<<"Cosec() = "<<result<<endl;
               log<<"\nCosec of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 13:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.sininverse(x);
               cout<<"Sine^-1() = "<<result<<endl;
               log<<"\nInverse of sine of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 14:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cosinverse(x);
               cout<<"Cosine^-1() = "<<result<<endl;
               log<<"\nInverse of Cosine of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 15:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.taninverse(x);
               cout<<"tan^-1() = "<<result<<endl;
               log<<"\nInverse of Tangent of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 16:
           {
                 system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cosecinverse(x);
               cout<<"cosec^-1() = "<<result<<endl;
               log<<"\nInverse of cosec of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 17:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.secinverse(x);
               cout<<"Sec^-1() = "<<result<<endl;
               log<<"\nInverse of Secant of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 18:
           {
                    system("cls");
               float x;
               cout<<"Enter the number: "<<endl;
               cin>>x;
               double result=calcusimple.cotinverse(x);
               cout<<"Cot^-1() = "<<result<<endl;
               log<<"\nInverse of Cotangent of number "<<x<<" is: "<<result;
               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 19:
           {
               system("cls");int n,r;ncr:
               cout<<"Enter Value of N: "<<endl;
               cin>>n;
               cout<<"Enter Value of R: "<<endl;
               cin>>r;
               if(n<r)
               {
                   system("cls");
                   cout<<"Math Error!!!!Follow this condition(n>r)\n";
                   goto ncr;
               }
               double result=calcusimple.nCr(n,r);
               cout<<"nCr: "<<result<<endl;
               log<<"\nnCr is equal to: "<<result;
                  cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 20:
           {
               system("cls");int n,r;npr:
               cout<<"Enter Value of N: "<<endl;
               cin>>n;
               cout<<"Enter Value of R: "<<endl;
               cin>>r;
               if(n<r)
               {
                   system("cls");
                   cout<<"Math Error!!!!Follow this condition(n>r)\n";
                   goto npr;
               }
               double result=calcusimple.nPr(n,r);
               cout<<"nPr: "<<result<<endl;
               log<<"\nnPr is equal to: "<<result;
                  cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
        case 21:
           {
               system("cls");int cho;
               cout<<"Please Select From Following:\n\t1.2X2\n\t2.3X3"<<endl;
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
	float result=calcusimple.matrixdeter(cho);
cout<<"\nThe Determinant of the matrix is: "<<result<<endl;
        log<< "\nThe Determinant of the matrix is: "<<result;
        cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
           break;
           case 22:
           {
               system("cls");
               if(calcusimple.identitycheck())
               {
                   cout<<"Yes"<<endl;
                   log<<"\nThe Entered Matrix Is an Identity Matrix";
               }
               else
               {
                   cout<<"No"<<endl;
                   log<<"\nThe Entered Matrix Is Not An Identity Matrix";
               }

               cout<<"Press Any key to continue!!!!"<<endl;
               getch();
            }
            break;
            case 23:
            {
                system("cls");
                calcusimple.transpose(log);
                cout<<"Press Any key to continue!!!!"<<endl;
               getch();


            }
            break;
           case 24:
           {
             system("cls");int exponent,base;
             cout<<"Enter the value of Base: "<<endl;
             cin>>base;
             cout<<"Enter the value of Exponent: "<<endl;
             cin>>exponent;
             long long int result=calcusimple.power(base,exponent);
             cout<<base<<"^"<<exponent<<": "<<result<<endl;
             log<<endl<<base<<"^"<<exponent<<": "<<result;
              cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
           case 25:
           {
               system("cls");int exponent,base;root:
             cout<<"Enter the value of Base: "<<endl;fflush(stdin);
             cin>>base;
             cout<<"Enter the value of Exponent: "<<endl;fflush(stdin);
             cin>>exponent;
             if(base<0)
             {
                 system("cls");
                 cout<<"Math Error!!!!(Base>=0)"<<endl;
                 goto root;
             }
             double result=calcusimple.rootofanynumber(base,exponent);
              cout<<base<<"^"<<"1/"<<exponent<<": "<<result<<endl;
             log<<endl<<base<<"^"<<"1/"<<exponent<<": "<<result;
              cout<<"Press Any key to continue!!!!"<<endl;
               getch();
           }
            break;
          case 26:
           {
               goto projectstart;
           }
            break;
           case 27:
           {
               log<<"\n\t\t\tSESSION END\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	           log.close();
	           Font f1;f1.loadFromFile("KBSticktoIt.ttf");
	          Text t1("THANKS FOR USING \nOUR CALCULATOR",f1,13);t1.setColor(Color::Red);
	        t1.setStyle(Text::Bold|Text::Underlined);
                    int start=1;
    sf::CircleShape shape(100);int num1=0,num2=0;int temp1,temp2;int a;
    shape.setFillColor(sf::Color::Transparent);int i=1;shape.setOutlineColor(Color::Green);shape.setOutlineThickness(1);
    shape.setPosition( Vector2f(0,0));t1.setRotation(-10);

	          RenderWindow window(VideoMode(xmax,ymax),"EndGame",Style::None);
              while(window.isOpen())
              {
                    Event event;
                    while(window.pollEvent(event))
                    {
                        if(event.type==Event::MouseButtonPressed)
                        {
                            window.close();

                        }

                    }
                    window.clear();
              Vector2f temp=shape.getPosition();
        num1=temp.x;
        num2=temp.y;
        if(num2>=ymax-200)
        {

            again3:
            a=1+rand()%4;
            if(a==2||a==3)
            {
                if(num1-1<0)
                {
                    i=2;
                }
                else
                {
                    i=a;
                }
            }
            else
            {
                goto again3;
            }
        }
        else if(num2==0&&i==2)
        {
            again:
            a=1+rand()%4;
            if(a==1||a==4)
            {
                i=a;
            }
            else
            {
                goto again;
            }
        }

       else if(num1>=xmax-200)
      {
          again2:
            a=1+rand()%4;
            if(a==3||a==4)
            {
                i=a;
            }
            else
            {
                goto again2;
            }
      }
      else if(num2==0||num1==0)
      {
          if(num1==0&&num2==0)
          {
              i=1;
          }
          else if(num2==0)
          {
            if(start==1)
          {
              i=1;
              start=0;
          }
          else


          {again6:
            a=1+rand()%4;
            if(a==1||a==4)
            {
                i=a;
            }
            else
            {
                goto again6;
            }
          }
          }
          else if(num1==0)
          {
             again7:
            a=1+rand()%4;
            if(a==1||a==2)
            {
                i=a;
            }
            else
            {
                goto again7;
            }
          }
      }
      else if(num1==0&&i==4)
      {
          again5:
            a=1+rand()%4;
            if(a==1||a==2)
            {
                i=a;
            }
            else
            {
                goto again5;
            }
      }

         if(i==1)
        {
            temp1=num1;temp2=num2;
        }
            if(i==1)
        {
            temp1++;temp2++;
        }
        if(i==2)
        {
           temp1++;temp2--;
        }
        if(i==3)
        {
            temp1--;temp2--;
        }
        if(i==4)
        {
            temp1--;temp2++;
        }
            shape.setPosition(Vector2f(temp1,temp2));
            t1.setPosition(Vector2f(temp1+7,temp2+68));

        window.draw(shape);window.draw(t1);
        window.display();
        this_thread::sleep_for(0.001s);


               }



               exit(0);
           }
            break;

        }//SCIENTIFIC CALCULATOR switch ends here
        goto start2;
      }//SCIENTIFIC CALCULATOR CASE ENDS HERE
           case 14:
            {
              log<<"\n\t\t\tSESSION END\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	          log.close();
	          Font f1;f1.loadFromFile("KBSticktoIt.ttf");
	          Text t1("  THANKS FOR USING \n  OUR CALCULATOR\n\n         MADE BY\n      Arsalan , Uzair\n     Sheryar , Hassan",f1,13);t1.setColor(Color::Red);
	        t1.setStyle(Text::Bold|Text::Underlined);
                    int start=1;
    sf::CircleShape shape(100);int num1=0,num2=0;int temp1,temp2;int a;
    shape.setFillColor(sf::Color::Transparent);int i=1;shape.setOutlineColor(Color::Green);shape.setOutlineThickness(2);
    shape.setPosition( Vector2f(0,0));t1.setRotation(-10);

	          RenderWindow window(VideoMode(xmax,ymax),"EndGame",Style::None);
              while(window.isOpen())
              {
                    Event event;
                    while(window.pollEvent(event))
                    {
                        if(event.type==Event::MouseButtonPressed)
                        {
                            window.close();

                        }

                    }
                    window.clear();
         Vector2f temp=shape.getPosition();
        num1=temp.x;
        num2=temp.y;
        if(num2>=ymax-200)
        {

            again3part2:
            a=1+rand()%4;
            if(a==2||a==3)
            {
                if(num1-1<0)
                {
                    i=2;
                }
                else
                {
                    i=a;
                }
            }
            else
            {
                goto again3part2;
            }
        }
        else if(num2==0&&i==2)
        {
            againpart2:
            a=1+rand()%4;
            if(a==1||a==4)
            {
                i=a;
            }
            else
            {
                goto againpart2;
            }
        }

       else if(num1>=xmax-200)
      {
          again2part2:
            a=1+rand()%4;
            if(a==3||a==4)
            {
                i=a;
            }
            else
            {
                goto again2part2;
            }
      }
      else if(num2==0||num1==0)
      {
          if(num1==0&&num2==0)
          {
              i=1;
          }
          else if(num2==0)
          {
            if(start==1)
          {
              i=1;
              start=0;
          }
          else


          {again6part2:
            a=1+rand()%4;
            if(a==1||a==4)
            {
                i=a;
            }
            else
            {
                goto again6part2;
            }
          }
          }
          else if(num1==0)
          {
             again7part2:
            a=1+rand()%4;
            if(a==1||a==2)
            {
                i=a;
            }
            else
            {
                goto again7part2;
            }
          }
      }
      else if(num1==0&&i==4)
      {
          again5part2:
            a=1+rand()%4;
            if(a==1||a==2)
            {
                i=a;
            }
            else
            {
                goto again5part2;
            }
      }

         if(i==1)
        {
            temp1=num1;temp2=num2;
        }
            if(i==1)
        {
            temp1++;temp2++;
        }
        if(i==2)
        {
           temp1++;temp2--;
        }
        if(i==3)
        {
            temp1--;temp2--;
        }
        if(i==4)
        {
            temp1--;temp2++;
        }
            shape.setPosition(Vector2f(temp1,temp2));
            t1.setPosition(Vector2f(temp1+7,temp2+68));

        window.draw(shape);window.draw(t1);
        window.display();
        this_thread::sleep_for(0.01s);
                    }
	          exit(0);
            }

    }//MAIN SWITCH ENDS HERE
    goto projectstart;
}//MAIN ENDS HERE
