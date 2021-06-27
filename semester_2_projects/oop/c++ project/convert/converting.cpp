#include <iostream>
#include <errno.h>
#include <time.h>
#include <sys/timeb.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <complex.h>
#include <graphics.h>
#define pie 3.14159265
#define true 1
#define false 0
#define xmax 639
#define ymax 479
#define xh 319
#define yh 239
using namespace std;
class graphics
{
	public:
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
		
		
		int *realxy(float x,float y)
		{
			int *xyptr;float tempx,tempy;
	xyptr=new int[2];

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
		
		
		void makeplane(void)
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
};
class circle:private graphics
{
	int *ptr,*nptr,*mptr,h,k,r;float x; int y;char coord[50];
	int *midpoint(float x1,float y1,float x2,float y2)
{
	int *coordptr;
	coordptr=new int[2];
	coordptr[0]=(x1+x2)/2;
	coordptr[1]=(y1+y2)/2;
	return(coordptr);
}
float dis(float x1,float y1,float x2,float y2)
{
	float ans;
	ans=sqrt(((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1));
	return (ans);
}
	public:
		circle(int h,int k,int r)
		{
			this->h=h;
			this->k=k;
			this->r=r;
			y=0;
		}
	void plotcircle(void)//graphics
{	
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
};
int main(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	circle c1;
	c1.plotcircle();
	return(0);
}
