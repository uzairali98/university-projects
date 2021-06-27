#include <iostream>
#include <errno.h>
//#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <conio.h>
#include<windows.h>
#include <math.h>
#include <string.h>
#include<complex.h>
#include <graphics.h>
#define pie 3.14159265
#define true 1
#define false 0
#define xmax 639
#define ymax 479
#define xh 319
#define yh 239
using namespace std;
void plotpoly(int,FILE *logf);
//void clean(void);
//void makeborder(void);
void hyperbola(int h,int k,float a,float b,int choice);
void plotelip(int h,int k,float a,float b,int choice);
void plotparabola(int h,int k,float a,int choice);
void plotcircle(int,int,int);
void twoeqplot(float,float,float,float,float,float);
//int *realxy(float,float);
void plot(float,float,float,float,char *text);
bool coordcheck(float,float);
int *midpoint(float,float,float,float);
//void makeplane(void);
float round(float);
float fabsf(float);
float dis(float x1,float y1,float x2,float y2);
float add(float, float); //as it is a scientific calculator we can expect float values
float multiply(float,float);
float devide(float,float);
float subtract(float,float);
float fact(float);
float nCr(float,float);
float nPr(float,float);
float slope(float x1,float y1,float x2,float y2);
float angle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);
void quadrant(int value);
int main ()
{
	FILE *logf;float x1,y1,x2,y2,x3,y3,x4,y4,yf,xf,cons1,cons2,cons3,tempx,tempy,tempcons,a,b;int **intptr,*intptr2;float **floatptr;
    int cho,cast,dist,size,row,col,x,y,quad,r,h,k,det;
    char *charptr;
	int gd=DETECT,gm;
	char choice[50];
    time_t t;
    char *tm;
    t=time(NULL);
    tm=ctime(&t);
	initgraph(&gd,&gm,"");
	srand(time(NULL));
	logf=fopen("log.txt","a+");
   	fprintf(logf,"\n=====================================================================================\nsession start\ncurrent time %s",tm);
	start:
	system("cls");makeborder();
	cout<<"\t\t         \n\t\t\t\t welcome\n"<<tm;
	cout<<"\npress 1 for loction on the plane"<<xmax<<"\npress 2 to find distance "<<"\npress 3 to find midpoint "<<"\npress 4 to verify 2 points when distace is given "<<"\npress 5 to find point of intersection of the two lines ";
    cout<<"\npress 6 to find slope of two points ";
   cout<<"\npress 7 to find angle between two lines ";
   cout<<"\npress 8 to draw circle ";
    cout<<"\npress 9 to draw parabola ";
    cout<<"\npress 10 to draw ellipse ";
    cout<<"\npress 11 to draw hyperbola ";
    cout<<"\npress 12 to draw a graph from polynomial ";
    cout<<"\npress 13 to enter into scientific calculator module ";
    cout<<"\npress 14 to exit from program ";
	cout<<"\nenter your choice now ";
	cin>>cho;fprintf(logf,"\nchoice selected %d\t",cho);
	system("cls");makeborder();
	switch (cho)
	{
		case(1):
			cout<<"enter value of x & y:"; fflush(stdin);
			cin>>x1>>y1;
			if((round(x1))>=0 && (round(y1)>=0)){quad=1;cout<<"point lies in 1st quadrant";fprintf(logf,"point lies in 1st quadrant",x1,y1);}
			else if((round(x1))<=0 && (round(y1)>=0)){quad=2;cout<<"point lies in 2nd quadrant";fprintf(logf,"point lies in 2nd quadrant",x1,y1);}
			else if((round(x1))<=0 && (round(y1)<=0)){quad=3;cout<<"point lies in 3rd quadrant";fprintf(logf,"point lies in 3rd quadrant",x1,y1);}
			else {quad=4;cout<<"point lies in 4th quadrant";fprintf(logf,"point lies in 4th quadrant",x1,y1);}
			fprintf(logf,"\nx=%0.2f y=%0.2f",x1,y1);
			cout<<"\ndo you want a pictorial representation ";fflush(stdin);
			cin>>choice;
			if (strcmp(choice,"yes")==0)
			quadrant(quad);
		    break;
		case(2):
			charptr=(char *)malloc(15*sizeof(char));
			cout<<"enter value of x1 y1 x2 y2:";cin>>x1>>y1>>x2>>y2;
			cout<<"distance is %0.2f"<<dis(x1,y1,x2,y2);
			fprintf(logf,"distance is %0.2f with vlues x1=%0.2f y1=%0.2f x2=%0.2f y2=%0.2f ",dis(x1,y1,x2,y2),x1,y1,x2,y2);
			cout<<"\ndo you want a pictorial representation ";fflush(stdin);
			cin>>choice;
			if (strcmp(choice,"yes")==0)
			{
			sprintf(charptr,"Distance is %0.1f units",dis(x1,y1,x2,y2));
			plot(x1,y1,x2,y2,charptr);
		    }
			break;
		case(3):
			cout<<"enter value of x1 y1 x2 y2 ";cin>>x1>>y1>>x2>>y2;intptr2=midpoint(x1,y1,x2,y2);
			cout<<"midpoint is (%d,%d)"<<intptr2[0]<<intptr2[1];
			fprintf(logf,"answer recorded (%d,%d) with x1=%0.2f y1=%0.2f x2=%0.2f y2=%0.2f vlues",intptr2[0],intptr2[1],x1,y1,x2,y2);
			cout<<"\ndo you want a pictorial representation ";fflush(stdin);
			cin>>choice;
			if (strcmp(choice,"yes")==0)
		    {
			sprintf(charptr,"*Midpoint lies here (%d,%d)",intptr2[0],intptr2[1]);
			plot(x1,y1,x2,y2,charptr);
		    }
			break;
		case(4):
		cout<<"enter value of distance and coordinates x1: y1: x2: y2:";cin>>dist>>x1>>y1>>x2>>y2;
		if (dist==(round(dis(x1,y1,x2,y2))))
		{
		cout<<"these points A(%0.2f,%0.2f) and B(%0.2f,%0.2f) verify this distance of %d units"<<x1<<y1<<x2<<y2<<dist;
		fprintf(logf,"these points A(%0.2f,%0.2f) and B(%0.2f,%0.2f) verify this distance of %d units",x1,y1,x2,y2,dist);
	}
		else
		    {
		cout<<"these points do not verify the given distance of %d units "<<dist;
		fprintf(logf,"these points do not verify the given distance of %d units with  A(%0.2f,%0.2f) and B(%0.2f,%0.2f)",dist,x1,y1,x2,y2);
		    }
		break;
	    case(5):
		printf("enter values of equation 1 only numbers (co-eff of x then co-eff of y then constant):");
		scanf("%f%f%f",&x1,&y1,&cons1);
		printf("\nenter values of equation 2 only numbers (co-eff of x then co-eff of y then constant):");
		scanf("%f%f%f",&x2,&y2,&cons2);
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
			printf("\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
			fprintf(logf,"\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
			twoeqplot(x1,y1,cons1,x2,y2,cons2);
			break;
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
				printf("\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
				fprintf(logf,"\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
			   	twoeqplot(x1,y1,cons1,x2,y2,cons2);
				break;
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
				   printf("\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
				fprintf(logf,"\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
				twoeqplot(x1,y1,cons1,x2,y2,cons2);
				break;
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
					printf("\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
				fprintf(logf,"\npoint of intersection of equation %0.0fx %0.0fy %0.0f and %0.0fx %0.0fy %0.0f is (%0.2f,%0.2f)",x1,y1,cons1,x2,y2,cons2,xf,yf);
				twoeqplot(x1,y1,cons1,x2,y2,cons2);
				break;
				}
			}
			case(6):
				printf("\n enter value of x1 x2 y1 y2 ");fflush(stdin);
				scanf("%f%f%f%f",&x1,&x2,&y1,&y2);
				printf("\nslope of (%0.0f,%0.0f) and (%0.0f,%0.0f) is %0.2f",x1,y1,x2,y2,slope(x1,y1,x2,y2));
				fprintf(logf,"\nslope of (%0.0f,%0.0f) and (%0.0f,%0.0f) is %0.2f",x1,y1,x2,y2,slope(x1,y1,x2,y2));
				printf("\ndo you want a pictorial representation ");fflush(stdin);
			    scanf("%s",&choice);
			     if (strcmp(choice,"yes")==0)
			     {
			     sprintf(charptr,"slope is %0.1f",slope(x1,y1,x2,y2));
			      plot(x1,y1,x2,y2,charptr);
		         }
				break;
			case(7):
			    printf("\n enter value of x1 x2 x3 x4 y1 y2 y3 y4");fflush(stdin);
				scanf("%f%f%f%f%f%f%f%f",&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
				printf("\nangle is %0.2f degree",angle(x1,y1,x2,y2,x3,y3,x4,y4));
				fprintf(logf,"\nangle is %0.2f degree",angle(x1,y1,x2,y2,x3,y3,x4,y4));
				break;
		   case(8):
		   	//equation of circle (x - h)^2 + (y - k)^2 = r^2
		   	printf("\n equation of circle is (x – h)^2 + (y – k)^2 = r^2 \n!!HUGE H , K or R VALUES CAN CAUSE CIRCLE TO BLEED OUT OF THE SCREEN!!\n");
		   	printf("enter value of 'h' ");
		   	scanf("%d",&x);
		   	printf("enter value of 'k' ");
		   	scanf("%d",&y);
		   	printf("enter value of 'r' !!!negative values can crash the circle!!!");
		   	scanf("%d",&r);
		   	plotcircle(x,y,r);
		   	fprintf(logf,"\ncircle plotted using vlaues h=%d k=%d r=%d",x,y,r);
		   	break;
		    case(9)://parabola 
		    	printf("\nThere are two equations of parabola\n1 (y-k)^2=4a(x-h)\n2 (x-h)^2=4a(y-k)\nnow press respective number1 to draw parabola ");
		    	scanf("%d",&cho);
		    	printf("\nenter value of 'a' ");fflush(stdin);
		    	scanf("%f",&a);
		    	printf("\nenter value of 'h' (enter 0 if h is not available) ");fflush(stdin);
		    	scanf("%d",&h);
		    	printf("\nenter value of 'k' (enter 0 if k is not available) ");fflush(stdin);
		    	scanf("%d",&k);
		    	makeplane();
		    	plotparabola(h,k,a,cho);
		    	fprintf(logf,"\nparabola plotted using values h=%d k=%d and a=%d",h,k,a);
		    	break;
		    case(10):
		    	printf("\nThere are two equations of ellipse\n1 (y-k)^2/a^2+(x-h)^2/b^2=1\n2 (x-h)^2/a^2+(y-k)^2/b^2=1\nnow press respective number1 to draw parabola ");
		    	scanf("%d",&cho);
		    	printf("\nenter value of 'a' ");fflush(stdin);
		    	scanf("%f",&a);
		    	printf("\nenter value of 'b' ");fflush(stdin);
		    	scanf("%f",&b);
		    	printf("\nenter value of 'h' (enter 0 if h is not available) ");fflush(stdin);
		    	scanf("%d",&h);
		    	printf("\nenter value of 'k' (enter 0 if k is not available) ");fflush(stdin);
		    	scanf("%d",&k);
		    	plotelip(h,k,a,b,cho);
		    	fprintf(logf,"\nellipse plotted using values h=%d k=%d a=%0.1f and b=%0.1f",h,k,a,b);
		    	break;
		    case(11):
		    	printf("\nThere are two equations of hyperbola\n1 (x-h)^2/a^2+(y-k)^2/b^2=1\n2 (y-k)^2/a^2+(x-h)^2/b^2=1\nnow press respective number1 to draw parabola ");
		    	scanf("%d",&cho);
		    	printf("\nenter value of 'a' ");fflush(stdin);
		    	scanf("%f",&a);
		    	printf("\nenter value of 'b' ");fflush(stdin);
		    	scanf("%f",&b);
		    	printf("\nenter value of 'h' (enter 0 if h is not available) ");fflush(stdin);
		    	scanf("%d",&h);
		    	printf("\nenter value of 'k' (enter 0 if k is not available) ");fflush(stdin);
		    	scanf("%d",&k);
		    	hyperbola(h,k,a,b,cho);
		    	fprintf(logf,"\nhyperbola plotted using values h=%d k=%d a=%0.1f and b=%0.1f",h,k,a,b);
		    	break;
		    case(12):
		    	printf("\n!!GRAPH MAY LOOK DIFFERENT DUE TO FIX SCREEN RESOLUTION OF %dX%d!!\n\nenter degree of polynomial equation maximum 4 and minimum 1 ",xmax,ymax);
		    	scanf("%d",&x);
		    	plotpoly(x,logf);
		    	break;
			case(13):
				printf("\t\tWELCOME TO SCIENTIFIC CALCULATOR MODULE");
				printf("\n\tpress 1 for addition");
				printf("\n\tpress 2 for subtraction");
				printf("\n\tpress 3 for multiplication");
				printf("\n\tpress 4 for division");
				printf("\n\tpress 5 to find factorial");
				printf("\n\tpress 6 to find log");
				printf("\n\tpress 7 to find sin(x)");
				printf("\n\tpress 8 to find cos(x)");
				printf("\n\tpress 9 to find tan(x)");
				printf("\n\tpress 10 to find cot(x)");
				printf("\n\tpress 11 to find sec(x)");
				printf("\n\tpress 12 to find cosec(x)");
				printf("\n\tpress 13 to find sin^-1(x)");
				printf("\n\tpress 14 to find cos^-1(x)");
				printf("\n\tpress 15 to find tan^-1(x)");
				printf("\n\tpress 16 to find nCr");
				printf("\n\tpress 17 to find nPr");
				printf("\n\tpress 18 to find determinant of a matrix (2x2) or (3x3)");                                   //incomplete
				printf("\n\tpress 19 to check weather given matrix is identity matrix or not ");
				printf("\n\tpress 20 to find transpose of a matrix");
				printf("\n\tpress 21 to find power of any number");
				printf("\n\tpress 22 to find root of a number (enter positive values only else there will be an error!!)");
				printf("\n\tpress 23 to go back");
				printf("\n\tpress 24 to exit");
				printf("\n\tenter your choice ");
				makeborder();
				scanf("%d",&cho);fprintf(logf,"\nchoice %d selected from scientific calculator module ",cho);system("cls");
				switch(cho)//switch for scientific calculator
				{
					case(1)://addition
					    printf("\nenter values two values to add ");
					    scanf("%f%f",&x1,&y1);
					    printf("\n%0.2f + %0.2f = %0.2f",x1,y1,add(x1,y1));
					    fprintf(logf,"\n%0.2f + %0.2f = %0.2f",x1,y1,add(x1,y1));
				    break;
				case(2)://subtraction
					printf("\nenter values two values to subtract ");
					    scanf("%f%f",&x1,&y1);
					    printf("\n%0.2f - %0.2f = %0.2f",x1,y1,subtract(x1,y1));
					    fprintf(logf,"\n\n%0.2f - %0.2f = %0.2f",x1,y1,subtract(x1,y1));
			            break;
					case(3)://multiplication
					    printf("\nenter values two values to multiply ");
					    scanf("%f%f",&x1,&y1);
					    printf("\n%0.2f x %0.2f = %0.2f",x1,y1,multiply(x1,y1));
					    fprintf(logf,"\n\n%0.2f x %0.2f = %0.2f",x1,y1,multiply(x1,y1));
			            break;
			        case(4)://division
			            printf("\nenter values two values to devide ");
					    scanf("%f%f",&x1,&y1);
					    printf("\n%0.2f / %0.2f = %0.2f",x1,y1,devide(x1,y1));
					    fprintf(logf,"\n\n%0.2f / %0.2f = %0.2f",x1,y1,devide(x1,y1));
			            break;
			        case(5)://factorial
					    printf("\nenter a number to find its factorial ");
					    scanf("%f",&x1);
					    printf("\nfactorial of %0.0f is %0.0f",x1,fact(x1));
					    fprintf(logf,"\nfactorial of %0.0f is %0.0f",x1,fact(x1));
			            break;
					case(6)://log
					    printf("\nenter the value ");
					    scanf("%f",&x1);
					    printf("\nwhat do you want to find (log10,log) ");fflush(stdin);
					    gets(choice);fprintf(logf,"\nentered choice %s",choice);
					    if((strcmp(choice,"log10"))==0)
					    {
					    	printf("\nlog10(%0.1f) is %f",x1,log10(x1));
							fprintf(logf,"\nlog10(%0.1f) is %f",x1,log10(x1));
						}
						else if((strcmp(choice,"log"))==0)
						{
							printf("\nlog(%0.1f) is %f",x1,log(x1));
							fprintf(logf,"\nlog(%0.1f) is %f",x1,log(x1));
						}
						else
						{
							printf("\nwrong in put !!");
						}
					    break;
					case(7)://sin
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\nsin(%0.1f)=%0.4f",x1,sin(x1));
						  fprintf(logf,"\nsin(%0.1f)=%0.4f",x1,sin(x1));
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\nsin(%0.1f)=%f",x1*pie/180,sin(x1*pie/180));
						  fprintf(logf,"\nsin(%0.1f)=%f",x1*pie/180,sin(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(8)://cos
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\ncos(%0.1f)=%0.4f",x1,cos(x1));
						  fprintf(logf,"\ncos(%0.1f)=%0.4f",x1,cos(x1));
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\ncos(%0.1f)=%f",x1*pie/180,cos(x1*pie/180));
						  fprintf(logf,"\ncos(%0.1f)=%f",x1*pie/180,cos(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(9)://tan
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\ntan(%0.1f)=%0.4f",x1,tan(x1));
						  fprintf(logf,"\ntan(%0.1f)=%0.4f",x1,tan(x1));
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\ntan(%0.1f)=%f",x1*pie/180,tan(x1*pie/180));
						  fprintf(logf,"\ntan(%0.1f)=%f",x1*pie/180,tan(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(10)://cot
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\ncot(%0.1f)=%0.4f",x1,cos(x1)/sin(x1));
						  fprintf(logf,"\ncot(%0.1f)=%0.4f",x1,cos(x1)/sin(x1));
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\ncot(%0.1f)=%f",x1*pie/180,cos(x1*pie/180)/sin(x1*pie/180));
						  fprintf(logf,"\ncot(%0.1f)=%f",x1*pie/180,cos(x1*pie/180)/sin(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(11)://sec
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\nsec(%0.1f)=%0.4f",x1,1/cos(x1));
						  fprintf(logf,"\nsec(%0.1f)=%0.4f",x1,1/cos(x1));
						  
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\nsec(%0.1f)=%f",x1*pie/180,1/cos(x1*pie/180));
						  fprintf(logf,"\nsec(%0.1f)=%f",x1*pie/180,1/cos(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(12)://cosec
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\ncosec(%0.1f)=%0.4f",x1,1/sin(x1));
						  fprintf(logf,"\ncosec(%0.1f)=%0.4f",x1,1/sin(x1));
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\ncosec(%0.1f)=%f",x1*pie/180,1/sin(x1*pie/180));
						  fprintf(logf,"\ncosec(%0.1f)=%f",x1*pie/180,1/sin(x1*pie/180));
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
					    break;
					case(13)://sin inverse
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\narcsin(%0.1f)=%0.4f",x1,asin(x1)*180/pie);
						  fprintf(logf,"\narcsin(%0.1f)=%0.4f",x1,asin(x1)*180/pie);
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\narcsin(%0.1f)=%f",x1*pie/180,asin(x1*pie/180)*180/pie);
						  fprintf(logf,"\narcsin(%0.1f)=%f",x1*pie/180,asin(x1*pie/180)*180/pie);
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
						break;
					case(14)://cos inverse
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\narccos(%0.1f)=%0.4f",x1,acos(x1)*180/pie);
						  fprintf(logf,"\narccos(%0.1f)=%0.4f",x1,acos(x1)*180/pie);
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\narccos(%0.1f)=%f",x1*pie/180,acos(x1*pie/180)*180/pie);
						  fprintf(logf,"\narccos(%0.1f)=%f",x1*pie/180,acos(x1*pie/180)*180/pie);
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
						break;
					case(15)://tan inverse
						 printf("\nenter the value ");
					    scanf("%f",&x1);
						 printf("\nis value in 'radians' or 'degrees' ? ");fflush(stdin);
					     gets(choice);
						 if((strcmp(choice,"radians"))==0)
						 {
						  printf("\narctan(%0.1f)=%0.4f",x1,atan(x1)*180/pie);
						  fprintf(logf,"\narctan(%0.1f)=%0.4f",x1,atan(x1)*180/pie);
						 }
						 else if((strcmp(choice,"degrees"))==0)
						 {
						  printf("\narctan(%0.1f)=%f",x1*pie/180,atan(x1*pie/180)*180/pie);
						  fprintf(logf,"\narctan(%0.1f)=%f",x1*pie/180,atan(x1*pie/180)*180/pie);
						 }
						 else
						 {
							printf("\nwrong in put !!");
						}
						break;
					case(16)://nCr
						printf("\nenter valued of N and R ");
						scanf("%f%f",&x1,&y1);
						printf("\nnCr is %0.1f ",nCr(x1,y1));
						fprintf(logf,"\nnCr is %0.1f ",nCr(x1,y1));
						break;
				    case(17)://nPr
				        printf("\nenter valued of N and R ");
						scanf("%f%f",&x1,&y1);
						printf("\nnPr is %0.1f ",nPr(x1,y1));
						fprintf(logf,"\nnPr is %0.1f with N=%0.0f and R=%0.0f",nPr(x1,y1),x1,y1);
						break;
					case(18)://determinant of a matrix (2x2) or (3x3)
						printf("\nenter size of matrix ");
						scanf("%d",&size);
		                intptr=(int **)calloc(size,sizeof(int));
		                  for(x=0;x<size;x++)
		                  intptr[x]=(int *)calloc(size,sizeof(int));
		                  for(x=0;x<size;x++)
		                      {
		    	               for(y=0;y<size;y++)
				                {
		    	                 printf("\nintptr[%d][%d]-> ",x,y);
		    	                 scanf("%d",&intptr[x][y]);
		                        }
		                        printf("\n**new row**");
			                  }
			                  if(size==2)
			                  {
			                  	det=((intptr[0][0]*intptr[1][1])-(intptr[0][1]*intptr[1][0]));
			                    printf("\ndeterminant of 2x2 is %d",det);fprintf(logf,"\ndeterminant of 2x2 is %d",det);
							  }
							  else
							  {
							  	det=intptr[0][0]*((intptr[1][1]*intptr[2][2]) - (intptr[2][1]*intptr[1][2])) -intptr[0][1]*(intptr[1][0]*intptr[2][2] - intptr[2][0]*intptr[1][2]) + intptr[0][2]*(intptr[1][0]*intptr[2][1] - intptr[2][0]*intptr[1][1]);
							  	printf("\ndeterminant of 3x3 is %d",det);fprintf(logf,"\ndeterminant of 3x3 is %d",det);
							  }
							  break;
					    case(19):
						printf("\nenter size of matrix max size NxN ");
		                scanf("%d",&size);
		                intptr=(int **)calloc(size,sizeof(int));
		                  for(x=0;x<size;x++)
		                  intptr[x]=(int *)calloc(size,sizeof(int));
		                     for(x=0;x<size;x++)
		                      {
		    	               for(y=0;y<size;y++)
				                {
		    	                 printf("\nintptr[%d][%d]-> ",x,y);
		    	                 scanf("%d",&intptr[x][y]);
		                        }
		                        printf("\n**new row**");
			                  }
		                     for(x=0;x<size;x++)
		                      {
			                   for(y=0;y<size;y++)
			                    {
				                  if(y==x)
				                   {
					                if(intptr[x][y]!=1)
				                     {
				                      printf("\nnot a identity matrix");fprintf(logf,"\nenterd matrix is not a identity matrix");
				                      goto end;
				                    }
				                    else
				                    continue;
			                       }
				                   if(intptr[x][y]!=0)
				                     {
					                  printf("\nmatrix is not a identity matrix");fprintf(logf,"\nenterd matrix is not a identity matrix");
					                  goto end;
				                     }
			                    }
		                      }  
		                 printf("\n\n");fprintf(logf,"\n\n");
		                 for(x=0;x<size;x++)
		                 {
			              for(y=0;y<size;y++)
			               {
				             printf("%d ",intptr[x][y]);fprintf(logf,"%d ",intptr[x][y]);
			               }
			                 printf("\n");fprintf(logf,"\n");
		                 }
		             printf("\n\n enterd matrix is an identity matrix");
			         fprintf(logf,"\nenterd matrix is an identity matrix");
		            break;
					case(20):
						printf("\nenter matrix row size ");
						scanf("%d",&row);
						printf("\nenter matrix column size ");
						scanf("%d",&col);
						fprintf(logf,"\ngiven matrix\n");
		                intptr=(int **)calloc(row,sizeof(int));
		                  for(x=0;x<row;x++)
		                  intptr[x]=(int *)calloc(col,sizeof(int));
		                  for(x=0;x<row;x++)
		                      {
		    	               for(y=0;y<col;y++)
				                {
		    	                 printf("\nintptr[%d][%d]-> ",x,y);
		    	                 scanf("%d",&intptr[x][y]);fprintf(logf,"%d ",intptr[x][y]);
		                        }
		                        printf("\n**new row**");fprintf(logf,"\n");
			                  }
			                  makeborder();
			                  printf("\nmatrix that is input\n");
			                  for(x=0;x<row;x++)
		                      {
		    	               for(y=0;y<col;y++)
		    	                 printf("%d ",intptr[x][y]);
		                        printf("\n");
			                  }
			                  fprintf(logf,"\ntranspose is\n");printf("\ntranspose is\n");
			                  for(x=0;x<col;x++)
		                      {
		    	               for(y=0;y<row;y++)
				                {
		    	                 printf("%d ",intptr[y][x]);
		    	                 
								 fprintf(logf,"%d ",intptr[y][x]);
		                        }
		                        printf("\n");fprintf(logf,"\n");
			                  }
			                  break;
			                  case(21):
			                  	printf("\nenter base value ");
			                  	scanf("%f",&x1);
			                  	printf("\nenter value of exponent ");
			                  	scanf("%f",&y1);
			                  	printf("\n%0.0f to the power %0.0f is %0.0f",x1,y1,pow(x1,y1));
			                  	fprintf(logf,"\n%0.0f to the power %0.0f is %0.0f",x1,y1,pow(x1,y1));
			                  	break;
			                case(22):
			                	printf("\nenter base value ");
			                  	scanf("%f",&x);
			                  	printf("\nenter value of exponent (enter float value)");
			                  	scanf("%f",&y);
			                  	printf("\n%0.0f to the root of %0.0f is %0.0f",x,y,pow(x,y));
			                  	fprintf(logf,"\n%0.0f to the root of %0.0f is %0.0f",x,y,pow(x,y));
			                  	break;
			                  case(23):
							  goto start;
			                  case(24):
			                   exit(0);
			                
			    }//scientific calculator switch ends here
			    break;
			    case(14):
				exit(0);
		}//main switch ends here
		end:
		printf("\ndo you want to restart:");
		scanf("%s",&choice);
		if (strcmp(choice,"yes")==0)
		goto start;
		closegraph();
	fprintf(logf,"\nsession end\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	fclose(logf);
	exit(0);
}//main ends here
void plotpoly(int degree,FILE *logf)
{
	float y=0,x=0;float cofx1,cofx2,cofx3,cofx4,power1,power2,power3,power4,con;int *ptr;
	system("cls");
	switch(degree)
	{
		case(1):
			printf("\nMonomial:\nIt is an algebraic expression that contains only one term and is called as\nMonomial.\nIn a simplistic form, it can be called as an expression that contains any count of like terms.\nFor example: 2x, x^1/2,3x ...");
			printf("\nenter value of coefficient of X");
			scanf("%f",&cofx1);
			printf("\nenter power/degree of X ");
			scanf("%f",&power1);
			printf("\nenter value of constant ");
			scanf("%f",&con);
			clean();makeborder();makeplane();
			moveto(xh,yh);
			while(1)
			{
			y=cofx1*pow(x,power1)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x+=0.1;	
			}
	     	moveto(xh,yh);
			 x=0;
			while(1)                                         //y=cofx1*pow(x,power);|| ptr[1]<=0 || ptr[1]>=ymax
			{
			if(abs(fmod(power1,1))!=0)
			y=cofx1*pow(abs(x),power1)+con;
			y=cofx1*pow(x,power1)+con;
			ptr=realxy(x,y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x-=0.1;	
			}
			fprintf(logf,"\ngraph is plotted using equation %0.1fX^%0.1f and constant %f",cofx1,power1,con);
			break;
			case(2):
			printf("\nBinomial:\nIt is an algebraic expression which comprises of two, unlike terms.\nFor example,\n3x + 4x^2 is binomial since it contains two unlike terms, that is, 3x and 4x^2");
			printf("\nenter value of coefficient of 1st X");
			scanf("%f",&cofx1);
			printf("\nenter value of coefficient of 2nd X");
			scanf("%f",&cofx2);
			printf("\nenter power/degree of 1st X ");
			scanf("%f",&power1);
			printf("\nenter power/degree of 2nd X ");
			scanf("%f",&power2);
			printf("\nenter value of constant ");
			scanf("%f",&con);
			clean();makeborder();makeplane();
			moveto(xh,yh);
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x+=0.1;	
			}
	     	moveto(xh,yh);
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
			putpixel(ptr[0],ptr[1],WHITE);
			x-=0.1;	
			}
			fprintf(logf,"\ngraph is plotted using equation %0.1fX^%0.1f and %0.1fX^%0.1f and constant %f",cofx1,power1,cofx2,power2,con);
			break;
			case(3):
			printf("\nTrinomial:\nIt is an algebraic expression that comprises three, unlike terms.\nFor example- 3x + 5x^2 – 6x^3");
			printf("\nenter value of coefficient of 1st X");
			scanf("%f",&cofx1);
			printf("\nenter value of coefficient of 2nd X");
			scanf("%f",&cofx2);
			printf("\nenter value of coefficient of 3rd X");
			scanf("%f",&cofx3);
			printf("\nenter power/degree of 1st X ");
			scanf("%f",&power1);
			printf("\nenter power/degree of 2nd X ");
			scanf("%f",&power2);
			printf("\nenter power/degree of 3rd X ");
			scanf("%f",&power3);
			printf("\nenter value of constant ");
			scanf("%f",&con);
			clean();makeborder();makeplane();
			moveto(xh,yh);
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x+=0.1;		
			}
	     	moveto(xh,yh);
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
			ptr=realxy(x,-y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x-=0.1;	
			}
			fprintf(logf,"\ngraph is plotted using equation %0.1fX^%0.1f and %0.1fX^%0.1f %0.1fX%0.1f and constant %0.1f",cofx1,power1,cofx2,power2,cofx3,power3,con);
			break;
			case(4):
			printf("\nPolynomial Of Degree 4:\nIt is an algebraic expression that comprises four, unlike terms.\nFor example- 3x + 5x^2 – 6x^3 + 7x^(1/2)");
			printf("\nenter value of coefficient of 1st X");
			scanf("%f",&cofx1);
			printf("\nenter value of coefficient of 2nd X");
			scanf("%f",&cofx2);
			printf("\nenter value of coefficient of 3rd X");
			scanf("%f",&cofx3);
			printf("\nenter value of coefficient of 4th X");
			scanf("%f",&cofx4);
			printf("\nenter power/degree of 1st X ");
			scanf("%f",&power1);
			printf("\nenter power/degree of 2nd X ");
			scanf("%f",&power2);
			printf("\nenter power/degree of 3rd X ");
			scanf("%f",&power3);
			printf("\nenter power/degree of 4th X ");
			scanf("%f",&power4);
			printf("\nenter value of constant ");
			scanf("%f",&con);
			clean();makeborder();makeplane();
			moveto(xh,yh);
			while(1)
			{
			y=cofx1*pow(x,power1)+cofx2*pow(x,power2)+cofx3*pow(x,power3)+cofx4*pow(x,power4)+con;
			ptr=realxy(x,y);
			if(x>=xmax || ptr[0]>=xmax)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x+=0.1;		
			}
	     	moveto(xh,yh);
			 x=0;
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
			ptr=realxy(x,-y);
			if(ptr[0]<0 || ptr[1]>=ymax || ptr[1]<=0)
			break;
			putpixel(ptr[0],ptr[1],WHITE);
			x-=0.1;	
			}
			fprintf(logf,"\ngraph is plotted using equation %0.1fX^%0.1f, %0.1fX^%0.1f, %0.1fX%0.1f, %0.1fX%0.1f constant %0.1f",cofx1,power1,cofx2,power2,cofx3,power3,cofx4,power4,con);
			break;
	}
	
}
void clean(void)
{
	int x,y;
	setcolor(BLACK);
	for(y=0;y<=ymax;y++)
	{
	line(0,y,xmax,y);
	delay(1);
    }
	setcolor(WHITE);
}
void makeborder(void)
{
	line(0,0,xmax,0);
	line(0,0,0,ymax);
	line(xmax,0,xmax,ymax);
	line(0,ymax,xmax,ymax);
}
void hyperbola(int h,int k,float a,float b,int choice)//graphics make shifted axis if time available
{
	float c=sqrt(pow(b,2)+pow(a,2));//int x=h
	makeplane();
	switch(choice)  
	{
		case(1)://(x-h)^2/a^2+(y-k)^2/b^2=1
		 plotparabola((a*15)+h,k,c,1);
		 plotparabola(-(a*15)+h,k,-c,1);
		 break;
		case(2):
		 plotparabola(h,(a*15)+k,c,2);
		 plotparabola(h,-(a*15)+k,-c,2);
	}
}
void plotelip(int h,int k,float a,float b,int choice)//graphics make shifted axis if time available
{
	int *ptr;
	makeplane();
	switch(choice)
	{
		case(1):
	     ptr=realxy(h,k);
	     ellipse(ptr[0],ptr[1],0,360,a,b);
	     break;
	    case(2):
	      ptr=realxy(h,k);
	     ellipse(ptr[0],ptr[1],0,360,b,a);
	     break;
	 }
}
void plotparabola(int h,int k,float a,int choice)//graphics
{
	int x=h,y=k;int *ptr;
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
				putpixel(ptr[0],ptr[1],WHITE);
				x++;
				delay(5);
			}
			x=h;
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(x,-1*sqrt(abs(4*a*(x-h)))+k);
				putpixel(ptr[0],ptr[1],WHITE);
				x++;
				delay(5);
			}
		}
		else
		{
			if(h<0)
			x=abs(h);
			else
			x=-abs(h);
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(-x,sqrt(4*a*(-x-h))+k);
				putpixel(ptr[0],ptr[1],WHITE);
				x++;
				delay(5);
			}
			if(h<0)
			x=abs(h);
			else
			x=-abs(h);
			while(1)
			{
				if(x>xh)
				break;
				ptr=realxy(-x,-1*sqrt(4*a*(-x-h))+k);
				putpixel(ptr[0],ptr[1],WHITE);
				x++;
				delay(5);
			}
		}
			break;
		 case(2)://(x-h)^2=4a(y-k)	
		 if(a>0)
		 {
		 	while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(sqrt(abs(4*a*(y-k)))+h,y);
				putpixel(ptr[0],ptr[1],WHITE);
				y++;
				delay(5);
			}
			y=k;
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(-1*sqrt(abs(4*a*(y-k)))+h,y);
				putpixel(ptr[0],ptr[1],WHITE);
				y++;
				delay(5);
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
				putpixel(ptr[0],ptr[1],WHITE);
				y++;
				delay(5);
			}
	    	if(k<0)
			y=abs(k);
			else
			y=-abs(k);
			while(1)
			{
				if(y>yh)
				break;
				ptr=realxy(-1*sqrt(4*a*(-y-k))+h,-y);
				putpixel(ptr[0],ptr[1],WHITE);
				y++;
				delay(5);
			}
		}
			break;
	}
}
void plotcircle(int h,int k,int r)//graphics
{
	int *ptr,*nptr,*mptr;float x; int y=0;char coord[50];
	ptr=realxy(h,k);
	while(1)
	{
	 errno=0;
	 x=sqrt(pow(r,2)-pow(y-k,2))+h;
	 makeborder();
	 if(errno==0)
	 break;
	 y=(rand()%400)-200;
    }
    makeplane();
    printf("R is radius\n C is center");
    circle(ptr[0],ptr[1],r);
    sprintf(coord,"C (%d,%d)",h,k);
    outtextxy(ptr[0]+10,ptr[1]+10,coord);
	nptr=realxy(x,y);
	line(ptr[0],ptr[1],nptr[0],nptr[1]);
	mptr=midpoint(ptr[0],ptr[1],nptr[0],nptr[1]);
	sprintf(coord,"R %0.0f units",dis(ptr[0],ptr[1],nptr[0],nptr[1]));
	outtextxy(mptr[0]+10,mptr[1]+10,coord);
}
void twoeqplot(float cx1,float cy1,float const1,float cx2,float cy2,float const2)//graphics
{
	int *ptr;float x=0;
	clean();
	makeborder();makeplane();
	x=0;
	if(cy1!=0)
	{
    while(1)
    {
	ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	if(ptr[0]<=0)
	break;
	putpixel(ptr[0],ptr[1],WHITE);
	x--;
    }
    x=0;
    while(1)
    {
	if(ptr[0]>=xmax)
	break;
	ptr=realxy(x,(-1*(const1)+(-1*(cx1*(x))))/cy1);
	putpixel(ptr[0],ptr[1],WHITE);
	x++;
    }
    }
    else
    {
    x=-const1/cx1;                                          //y12=(-1*(const1)+(-1*(cx1*(x2))))/cy1;
    ptr=realxy(x,0);
    line(ptr[0],0,ptr[0],ymax);
	}
	x=0;
//****************************************//	
    if(cy2!=0)
	{
    while(1)
    {
	if(ptr[0]<=0)
	break;
	ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	putpixel(ptr[0],ptr[1],WHITE);
	x--;
    }
    x=0;
    while(1)
    {
	if(ptr[0]>=xmax)
	break;
	ptr=realxy(x,(-1*(const2)+(-1*(cx2*(x))))/cy2);
	putpixel(ptr[0],ptr[1],WHITE);
	x++;
    }
    }
    else
    {
    x=-const2/cx2;                                          //y12=(-1*(const1)+(-1*(cx1*(x2))))/cy1;
    ptr=realxy(x,0);
    line(ptr[0],0,ptr[0],ymax);
	}
}
void plot(float x1,float y1,float x2,float y2,char *text)//graphics
{
	int *xyptr1,*xyptr2,*midptr;
	makeplane();
	xyptr1=realxy(x1,y1);
	xyptr2=realxy(x2,y2);
	midptr=midpoint(xyptr1[0],xyptr1[1],xyptr2[0],xyptr2[1]);
	outtextxy(midptr[0],midptr[1],text);
	line(xyptr1[0],xyptr1[1],xyptr2[0],xyptr2[1]);
}
int *midpoint(float x1,float y1,float x2,float y2)
{
	int *coordptr;
	coordptr=(int *)calloc(2,sizeof(int));
	coordptr[0]=(x1+x2)/2;
	coordptr[1]=(y1+y2)/2;
	return(coordptr);
}
int *realxy(float x,float y)
{
	int *xyptr;float tempx,tempy;
	xyptr=(int *)calloc(2,sizeof(int));

		if(x<0)
	{
		tempx=xh+x;
		if(tempx<0)
		xyptr[0]=0;
		else
		xyptr[0]=tempx;
	}
	else
	{
		tempx=xh+x;
		if(tempx>xmax)
		xyptr[0]=xmax;
		else
		xyptr[0]=tempx;
	}

	if(y<0)
	{
		tempy=fabsf(y-yh);
		if(tempy>ymax)
		xyptr[1]=ymax;
		else
		xyptr[1]=tempy;
	}
	else
	{
		tempy=yh-y;
	    if(tempy<0)
		xyptr[1]=0;
		else
		xyptr[1]=tempy;
	}
	return(xyptr);
}
bool coordcheck(float x,float y)
{
	float tempx,tempy;
	if(x<0)
	{
		tempx=319+x;
		if(tempx<0)
		return false;
	}
	else
	{
			tempx=319+x;
		if(tempx>xmax)
		return false;
	}
	if(y<0)
	{
		tempy=fabsf(y-239);
		if(tempy>ymax)
		return false;
	}
	else
	{
		tempy=239-y;
		if(tempy<0)
		return false;
	}
	return true;
}
void makeplane(void)//graphics
{
	clean();
	makeborder();
	line(0,ymax/2,xmax,ymax/2);
	line(xmax/2,0,xmax/2,ymax);
	outtextxy(0,yh+2,"-X");
	outtextxy(xh+2,0,"+Y");
	outtextxy(xmax-15,yh+2,"+X");
	outtextxy(xh+2,ymax-10,"-Y");
}
void quadrant(int value)//graphics
{
	int a;
    makeplane();
	switch(value)
	{
		case(1):
		    for(a=239;a>=0;a--)
		    line(xh,a,xmax,a);
		    getch();
		    break;
		case(2):
			for(a=239;a>=0;a--)
			line(0,a,xh,a);
			getch();
			break;
		case(3):
			for(a=239;a<=ymax;a++)
			line(0,a,xh,a);
			getch();
			break;
		case(4):
			for(a=239;a<=ymax;a++)
			line(xh,a,xmax,a);
			getch();
			break;
	}
	getch();
}
float angle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	float ans,m1,m2;
	m1=slope(x1,y1,x2,y2);
	m2=slope(x3,y3,x4,y4);
	ans=atan((fabs(m1-m2)/fabs(1+(m1*m2))))*180/pie;
	return(ans);
}
float slope(float x1,float y1,float x2,float y2)
{
	float ans;
	ans=(y2-y1)/(x2-x1);
	return(ans);
}
float nPr(float n,float r)
{
	float ans;
	ans=fact(n)/fact(n-r);
	return(ans);
}
float dis(float x1,float y1,float x2,float y2)
{
	float ans;
	ans=sqrt(((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1));
	return (ans);
}
float nCr(float n,float r)
{
	float ans;
	ans=(fact(n))/(fact(r)*fact(n-r));
	return(ans);
}
float add(float a, float b)
{
	return(a+b);
}
float subtract(float a,float b)
{
	return(a-b);
}
float multiply(float a,float b)
{
	return(a*b);
}
float devide(float a,float b)
{
	return(a/b);
}
float fact(float a)
{
	int ans;
	if(a==1)
	return(1);
	ans=a*fact(a-1);
	return(ans);
}
float round (float a)
{
 int x=a;
 if((a-x)>0.5)
 return(x+1);
 else
 return(x);
 }
 float fabsf(float a)
 {
 if(a<0)
 return(a-(a*2));
 else
 return(a);
 }
