#include<iostream>
#include<math.h>
#include<iomanip>
#include<queue>
#include<string>
#include <sstream>
#include "fparser.hh"
using namespace std;
class bisection
{
    private:
		long double ebsilon;
        double *Lbound,*Ubound;
		int fixval;
        double *p;
		long double error;
		int iteration;
	    string funstring;
        FunctionParser func;
        double templ,tempu;
       ///////////////////////////// PRIVATE FUNCTIONS //////////////////////////
        void backupbounds(void)
        {
            templ=*Lbound;
            tempu=*Ubound;
        }
        void restorebounds(void)
        {
            *Lbound=templ;
            *Ubound=tempu;
        }
       //////////////////////////////////////////////////////////////////////////

    public:
        bisection()
        {
            func.AddConstant("pi", 3.1415926535897932);
            Lbound=new double[1];
            Ubound=new double[1];
            p=new double[1];
        }
        void setparameters(void)
        {
            *p=iteration=1;
            error=999;
            system("cls");
			cout<<"\nenter value for EBSILON:";
			cin>>ebsilon;
			cout<<"\nenter value for lower bound:";
			cin>>Lbound[0];
			cout<<"\nenter value for upper bound:";
			cin>>Ubound[0];
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>funstring;
            if(cin.fail())
            continue;

            int res = func.Parse(funstring, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< func.ErrorMsg() << "\n\n";
            }
			backupbounds();
			printdetails();
        }
        void evaluate(void)
        {
            restorebounds();
            if(!((func.Eval(Lbound)>0 && func.Eval(Ubound)<0) || (func.Eval(Lbound)<0 && func.Eval(Ubound)>0)))
					{
						cout<<"\nsigns are not opposite";
						system("pause");
						return;
					}
					else
					{
					    double temp=(*Lbound+*Ubound)/2;
						cout<<"\n    ITERATIONS N	|	 A     |  	  B	    |    	P   	 |		   F(P)         |       ERROR"<<endl;
						do
						{
							*p=(*Lbound+*Ubound)/2;
							 error=fabsf(*p-temp);
							cout<<setprecision(fixval)<<"	  "<<iteration<<"	        	"<<Lbound[0]<<"		"<<Ubound[0]<<"	        	"<<*p<<"		"<<func.Eval(p)<<"              "<<error<<endl;
							if(func.Eval(p)>=0)
						    *Ubound=*p;
						    else
						    *Lbound=*p;
                            temp=*p;
                            iteration++;
                            if(iteration==2)
                                error++;
						}
						while(error>=ebsilon);
					}
					system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is f(x) = "<<funstring<<"    with BOUNDS=["<<Lbound[0]<<","<<Ubound[0]<<"]";
			cout<<"\nEBSILON = "<<ebsilon;
			cout<<"\nFIX VALUE="<<fixval<<endl;
			cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		}
};

class falseposition
{
        private:
		long double ebsilon;
        double *Lbound,*Ubound;
		int fixval;
        double *p;
		long double error;
		int iteration;
	    string funstring;
        FunctionParser func;
        double templ,tempu;
       ///////////////////////////// PRIVATE FUNCTIONS //////////////////////////
        void backupbounds(void)
        {
            templ=*Lbound;
            tempu=*Ubound;
        }
        void restorebounds(void)
        {
            *Lbound=templ;
            *Ubound=tempu;
        }
       //////////////////////////////////////////////////////////////////////////

    public:
        falseposition()
        {
            func.AddConstant("pi", 3.1415926535897932);
            Lbound=new double[1];
            Ubound=new double[1];
            p=new double[1];
        }
        void setparameters(void)
        {
            *p=iteration=0;
            error=999;
            system("cls");
			cout<<"\nenter value for EBSILON:";
			cin>>ebsilon;
			cout<<"\nenter value for lower bound:";
			cin>>Lbound[0];
			cout<<"\nenter value for upper bound:";
			cin>>Ubound[0];
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>funstring;
            if(cin.fail())
            continue;

            int res = func.Parse(funstring, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< func.ErrorMsg() << "\n\n";
            }
			backupbounds();
        }
        void evaluate(void)
        {
            restorebounds();
            cout<<"\nFALSE POSITION///////"<<endl;
           if(!((func.Eval(Lbound)>0 && func.Eval(Ubound)<0) || (func.Eval(Lbound)<0 && func.Eval(Ubound)>0)))
					{
						cout<<"\nsigns are not opposite";
						return;
					}
					else
					{
						queue <long double> pq;
						cout<<"\nITERATIONS N|	  f(a)    |  	  f(b)	    |    	P   	 |		f(p)	|  	   ERROR"<<endl;
						while(error>=ebsilon)
						{
							*p=(*Lbound*func.Eval(Ubound)-*Ubound*func.Eval(Lbound))/(func.Eval(Ubound)-func.Eval(Lbound));
							pq.push(*p);
							if(func.Eval(p)>=0)
						    *Ubound=*p;
						    else
						    *Lbound=*p;
						    if(iteration==0)
							{
						    iteration++;
						    continue;
							}
						    error=fabsf(*p-pq.front());
						    cout<<setprecision(fixval+1)<<" "<<iteration<<"	    	"<<func.Eval(Lbound)<<"		"<<func.Eval(Ubound)<<"	"<<*p<<"		"<<func.Eval(p)<<"		"<<*p<<"-"<<pq.front()<<" = "<<error<<endl;
					          pq.pop();
							 iteration++;
						}
					}
					system("pause");
					printdetails();
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is f(x) = "<<funstring<<"    with BOUNDS=["<<Lbound[0]<<","<<Ubound[0]<<"]";
			cout<<"\nEBSILON = "<<ebsilon;
			cout<<"\nFIX VALUE="<<fixval<<endl;
			cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		}
};

class newton_method
{
     private:
		long double ebsilon;
        double *Lbound,*Ubound;
		int fixval;
        double *p,*p0;
		long double error;
		int iteration;
	    string funstring,FuncDerivativeString;
        FunctionParser func,derivative;
        double templ,tempu;
       ///////////////////////////// PRIVATE FUNCTIONS //////////////////////////
        void backupbounds(void)
        {
            templ=*Lbound;
            tempu=*Ubound;
        }
        void restorebounds(void)
        {
            *Lbound=templ;
            *Ubound=tempu;
        }
       //////////////////////////////////////////////////////////////////////////

    public:
        newton_method()
        {
            func.AddConstant("pi", 3.1415926535897932);
            Lbound=new double[1];
            Ubound=new double[1];
            p=new double[1];
            p0=new double[1];
        }
        void setparameters(void)
        {
             ebsilon=-1;
            *p=iteration=0;
            error=999;
            system("cls");
			cout<<"\nenter value for lower bound:";
			cin>>Lbound[0];
			cout<<"\nenter value for upper bound:";
			cin>>Ubound[0];
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>funstring;
            if(cin.fail())
            continue;

            int res = func.Parse(funstring, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< func.ErrorMsg() << "\n\n";
            }
            /////////////////////TAKING DERIVATIVE INPUT/////////////////////////
            while(true)
            {
            cout << "enter function's derivative f'(x) = ";
            cin>>FuncDerivativeString;
            if(cin.fail())
            continue;

            int res = derivative.Parse(FuncDerivativeString, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< derivative.ErrorMsg() << "\n\n";
            }
			backupbounds();
			*p0=((*Lbound)+(*Ubound))/2;
			printdetails();
        }
        void evaluate(int method)
        {
             restorebounds();
				switch(method)
				{
                case 1:
                    {
                        cout<<"\nEnter the value of EPSILON = ";
                        cin>>ebsilon;
                        system("cls");
                        cout<<"\n\t\t\t\t\t\tNEWTON METHOD";
                        cout<<"\n    ITERATIONS N	|	 f(pn-1)    | 	  f'(pn-1)	   |    	P   	 |		ERROR"<<endl;
                        while(error>=ebsilon)
                        {
                            /////////////////////////////////////////
                            *p=*p0-(func.Eval(p0)/derivative.Eval(p0));//EQUATION
                            /////////////////////////////////////////
                            error=fabsf(*p-*p0);
                            cout<<fixed;
                            cout<<setprecision(fixval+1)<<"	  "<<iteration+1<<"	    	"<<func.Eval(p0)<<"		"<<derivative.Eval(p0)<<"		"<<*p<<"		"<<*p<<"-"<<*p0<<" = "<<error<<endl;
                            iteration++;
                            *p0=*p;

                        }
                    }
				    break;
                case 2:
                    {
                        cout<<"\nplease enter the number of iterations : ";
                        int noit;
                        cin>>noit;
                        cout<<"\n\t\t\t\t\t\tNEWTON METHOD";
                        cout<<"\n    ITERATIONS N	|	 f(pn-1)    | 	  f'(pn-1)	   |    	P   	 |		ERROR"<<endl;
                        while(iteration<=noit)
                        {
                            /////////////////////////////////////////
                            *p=*p0-(func.Eval(p0)/derivative.Eval(p0));//EQUATION
                            /////////////////////////////////////////
                            error=fabsf(*p-*p0);
                            cout<<fixed;
                            cout<<setprecision(fixval)<<"	  "<<iteration+1<<"	    	"<<func.Eval(p0)<<"		"<<derivative.Eval(p0)<<"		"<<*p<<"		"<<*p<<"-"<<*p0<<" = "<<error<<endl;
                            iteration++;
                            *p0=*p;

                        }
                    }
                    break;
                default:
                    {
                        cout<<"\nwrong choice selected!!";
                        return;
                    }

				}
        system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is f(x) = "<<funstring<<"    with BOUNDS=["<<Lbound[0]<<","<<Ubound[0]<<"]";
		    cout<<"\nderivative of function f'(x) = "<<FuncDerivativeString;
		    if(ebsilon!=-1)
			cout<<"\nEBSILON = "<<ebsilon;
			cout<<"\nFIX VALUE="<<fixval;
			cout<<"\nAssigning Po = ("<<*Lbound<<"+"<<*Ubound<<")/2 = "<<*p0<<endl;
			cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		}
};

class secant_method
{
     private:
		long double ebsilon;
        double *Lbound,*Ubound;
		int fixval;
        double *p,*p0,*p1;
		long double error;
		int iteration;
	    string funstring;
        FunctionParser func;
        double templ,tempu;
       ///////////////////////////// PRIVATE FUNCTIONS //////////////////////////
        void backupbounds(void)
        {
            templ=*Lbound;
            tempu=*Ubound;
        }
        void restorebounds(void)
        {
            *Lbound=templ;
            *Ubound=tempu;
        }
       //////////////////////////////////////////////////////////////////////////

    public:
        secant_method()
        {
            func.AddConstant("pi", 3.1415926535897932);
            Lbound=new double;
            Ubound=new double;
            p=new double;
            p0=new double;
            p1=new double;
        }
        void setparameters(void)
        {
            *p=0;
            iteration=2;
            error=999;
             ebsilon=-1;
            system("cls");
			cout<<"\nenter value for lower bound:";
			cin>>Lbound[0];
			cout<<"\nenter value for upper bound:";
			cin>>Ubound[0];
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>funstring;
            if(cin.fail())
            continue;

            int res = func.Parse(funstring, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< func.ErrorMsg() << "\n\n";
            }
			backupbounds();
			printdetails();
        }
        void evaluate(int method)
        {
             restorebounds();
				switch(method)
				{
                case 1:
                    {
                        cout<<"\nEnter the value of EPSILON = ";
                        cin>>ebsilon;
                       *p0=*Lbound;
				       *p1=*Ubound;
                        cout<<"\n\t\t\t\t\t\tSECANT METHOD";
                        cout<<"\n    ITERATIONS N    |     f(pn-1)    |    f(pn-2)    |    	P   	 |		ERROR"<<endl;
                        while(error>=ebsilon)
                        {
                            /////////////////////////////////////////
                            *p=*p1-(func.Eval(p1)*(*p1-*p0))/(func.Eval(p1)-func.Eval(p0));//EQUATION
                            /////////////////////////////////////////
                            error=fabsf(*p-*p1);
                            cout<<fixed;
                            cout<<setprecision(fixval+1)<<" "<<iteration<<"	        	"<<func.Eval(p1)<<"        "<<func.Eval(p0)<<"        "<<*p<<"		"<<*p<<"-"<<*p1<<" = "<<error<<endl;
                            iteration++;
                            *p0=*p1;
                            *p1=*p;
                        }
                    }
				    break;
                case 2:
                    {
                        cout<<"\nplease enter the number of iterations (>=2): ";
                        int noit;
                        cin>>noit;
                        *p0=*Lbound;
				        *p1=*Ubound;
                        cout<<"\n\t\t\t\t\t\tSECANT METHOD";
                        cout<<"\n    ITERATIONS N    |     f(pn-1)    |    f(pn-2)    |    	P   	 |		ERROR"<<endl;
                        while(iteration<=noit)
                        {
                              /////////////////////////////////////////
                            *p=*p1-(func.Eval(p1)*(*p1-*p0))/(func.Eval(p1)-func.Eval(p0));//EQUATION
                            /////////////////////////////////////////
                            error=fabsf(*p-*p1);
                            cout<<fixed;
                            cout<<setprecision(fixval)<<" "<<iteration<<"	        	"<<func.Eval(p1)<<"        "<<func.Eval(p0)<<"        "<<*p<<"		"<<*p<<"-"<<*p1<<" = "<<error<<endl;
                            iteration++;
                            *p0=*p1;
                            *p1=*p;

                        }
                    }
                    break;
                default:
                    {
                        cout<<"\nwrong choice selected!!";
                        return;
                    }

				}
        system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is f(x) = "<<funstring<<"    with BOUNDS=["<<Lbound[0]<<","<<Ubound[0]<<"]";
			if(ebsilon!=-1)
			cout<<"\nEBSILON = "<<ebsilon;
			cout<<"\nFIX VALUE="<<fixval;
			cout<<"\nAssigning Po = "<<*Lbound;
			cout<<"\nAssigning P1 = "<<*Ubound<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		}
};

class fix_point
{
     private:
		long double ebsilon;
        double *Lbound,*Ubound;
		int fixval;
        double *p;
		long double error;
		int iteration;
	    string gx;
        FunctionParser func;


    public:
        fix_point()
        {
            func.AddConstant("pi", 3.1415926535897932);
            Lbound=new double[1];
            Ubound=new double[1];
            p=new double[1];
        }
        void setparameters(void)
        {
             ebsilon=-1;
            *p=iteration=1;
            error=999;
            system("cls");
			cout<<"\nenter value for lower bound:";
			cin>>Lbound[0];
			cout<<"\nenter value for upper bound:";
			cin>>Ubound[0];
            cout<<"\nEnter the value of EPSILON = ";
            cin>>ebsilon;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function g(x) (Equation in terms of x) = ";
            cin>>gx;
            if(cin.fail())
            continue;

            int res = func.Parse(gx, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< func.ErrorMsg() << "\n\n";
            }
			*p=*Lbound;
			printdetails();
        }
        void evaluate(void)
        {
            long double temp=*p;
            *p=func.Eval(p);
            error=fabs(temp-*p);
            system("cls");
            cout<<"\n\t\t\t\t\t\tFIX POINT METHOD";
            cout<<"\n    ITERATIONS N	|	    P       |		ERROR"<<endl;
            while(error>=ebsilon)
            {
             cout<<setprecision(fixval)<<"\t"<<iteration<<"\t\t\t"<<*p<<"\t\t"<<error<<endl;
             temp=*p;
             *p=func.Eval(p);
             error=fabs(temp-*p);
             iteration++;
            }
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is g(x) = "<<gx<<"    with BOUNDS=["<<Lbound[0]<<","<<Ubound[0]<<"]";
			cout<<"\nEBSILON = "<<ebsilon;
			cout<<"\nFIX VALUE="<<fixval;
			cout<<"\n Po = "<<*p<<endl;
			cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		}
};

class euler
{
  private:
		int fixval;
		long double error,upperlimit,lowerlimit;
        double *vars; //vars[0] (holds X) vars[1] (holds y) vars[2] (holds h)
		int iteration;
	    string finalfunc,Gfunc,Afunc;
        FunctionParser mainfunc,realfunc;

    public:
        euler()
        {
            upperlimit=lowerlimit=0;
            vars=new double[3];
            mainfunc.AddConstant("pi", 3.1415926535897932);
            realfunc.AddConstant("pi", 3.1415926535897932);
        }
        void setparameters(void)
        {
            iteration=0;
            error=999;
            finalfunc="y+h*(";
            system("cls");
			cout<<"\nenter value for Xo:";
			cin>>vars[0];
			cout<<"\nenter value for Yo:";
			cin>>vars[1];
			cout<<"\nenter value for H:";
			cin>>vars[2];
			cout<<"\nenter value for upper limit or the approximation value :";
			cin>>upperlimit;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function Y' or f(x,y)= ";
            cin>>Gfunc;
            if(cin.fail())
            continue;
            finalfunc=finalfunc+Gfunc+')';
            int res = mainfunc.Parse(finalfunc, "x,y,h");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< mainfunc.ErrorMsg() << "\n\n";
            }

            cout<<"\ndo you want to set Actual function F(x) ? (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y')
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>Afunc;
            if(cin.fail())
            continue;
            int res =realfunc.Parse(Afunc, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< realfunc.ErrorMsg() << "\n\n";
            }
            else
            Afunc="null";
            lowerlimit=vars[0];
            printdetails();
        }
        void evaluate(void)
        {
            queue <long double>temp;
         if(Afunc=="null")
         {
             cout<<"\nN	|	     X        | 	     Y	     \n"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<endl;
                 vars[1]=mainfunc.Eval(vars);
                 vars[0]+=vars[2];
                 iteration++;
             }
         }
         else
         {
             cout<<"\nN	|	     X        | 	     Y'	        |          Y(x)        |           ERROR\n"<<endl;
             double temp=realfunc.Eval(vars);
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<"\t\t\t"<<temp<<"\t\t\t"<<fabs(vars[1]-temp)<<endl;
                 vars[1]=mainfunc.Eval(vars);
                 vars[0]+=vars[2];
                 temp=realfunc.Eval(vars);
                 iteration++;
             }
         }

        system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is Y' or f(x,y)= "<<Gfunc<<"    with "<<lowerlimit<<"<=X<="<<upperlimit;
		    if(Afunc!="null")
            cout<<"\nActual function is f(x) : "<<Afunc;
		    cout<<"\nfinal Euler function is : "<<finalfunc;
			cout<<"\n H = "<<vars[2];
			cout<<"\n Xo = "<<vars[0];
			cout<<"\n Yo = "<<vars[1];
			cout<<"\nFIX VALUE="<<fixval<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class Meuler
{
    private:
		int fixval;
		long double error,upperlimit,lowerlimit;
        double *vars; //vars[0] (holds X) vars[1] (holds y) vars[2] (holds h)
		int iteration;
	    string finalfunc,Gfunc,Afunc,modeulerfunc;
        FunctionParser mainfunc,realfunc,modeuler,givenfunction;

    public:
        Meuler()
        {
            upperlimit=lowerlimit=0;
            vars=new double[3];
            mainfunc.AddConstant("pi", 3.1415926535897932);
            realfunc.AddConstant("pi", 3.1415926535897932);
        }
        void setparameters(void)
        {
            iteration=0;
            error=999;
            modeulerfunc="y+(h/2)*(A+B)";
            modeuler.Parse(modeulerfunc,"y,h,A,B");
            finalfunc="y+h*(";
            system("cls");
			cout<<"\nenter value for Xo:";
			cin>>vars[0];
			cout<<"\nenter value for Yo:";
			cin>>vars[1];
			cout<<"\nenter value for H:";
			cin>>vars[2];
			cout<<"\nenter value for upper limit or the approximation value :";
			cin>>upperlimit;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function Y' or f(X,Y) = ";
            cin>>Gfunc;
            if(cin.fail())
            continue;
            finalfunc=finalfunc+Gfunc+')';
            int res = mainfunc.Parse(finalfunc, "x,y,h");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< mainfunc.ErrorMsg() << "\n\n";
            }
            givenfunction.Parse(Gfunc,"x,y");
            cout<<"\ndo you want to set Actual function F(x) ? (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y')
            while(true)
            {
            cout << "enter function f(x) = ";
            cin>>Afunc;
            if(cin.fail())
            continue;
            int res =realfunc.Parse(Afunc, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< realfunc.ErrorMsg() << "\n\n";
            }
            else
            Afunc="null";
            lowerlimit=vars[0];
            printdetails();
        }
        void evaluate(void)
        {
         if(Afunc=="null")
         {
             double arr[4]; //[0] y ,[1] h,[2] A,[3] B   y+(h/2)*(A+B)
             double B[2]; //0 x,1 y,2 h  array ka structure
             B[0]=vars[0]+vars[2];
             B[1]=mainfunc.Eval(vars);
             arr[1]=vars[2];

             cout<<"\nN	|	     X        | 	     Y	     \n"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<endl;
                 B[0]=vars[0]+vars[2];
                 B[1]=mainfunc.Eval(vars);

                 arr[3]=givenfunction.Eval(B);
                 arr[2]=givenfunction.Eval(vars);
                 arr[0]=vars[1];
                 vars[1]=modeuler.Eval(arr);
                 vars[0]+=vars[2];
                 iteration++;
             }
         }
         else
         {
            double arr[4]; //[0] y ,[1] h,[2] A,[3] B   y+(h/2)*(A+B)
            double B[2],temp; //0 x,1 y,2 h  array ka structure
             B[0]=vars[0]+vars[2];
             B[1]=mainfunc.Eval(vars);
             arr[1]=vars[2];
             temp=vars[1];
             cout<<"\nN	|	    X        | 	      Y	      |         Y(x)          |           ERROR\n"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<"\t\t\t"<<temp<<"\t\t\t"<<fabs(temp-vars[1])<<endl;
                 B[0]=vars[0]+vars[2];
                 B[1]=mainfunc.Eval(vars);

                 arr[3]=givenfunction.Eval(B);
                 arr[2]=givenfunction.Eval(vars);
                 arr[0]=vars[1];
                 vars[1]=modeuler.Eval(arr);
                 vars[0]+=vars[2];
                 temp=realfunc.Eval(vars);
                 iteration++;
             }
         }
         system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is Y' or f(x,y)= "<<Gfunc<<"    with "<<lowerlimit<<"<=X<="<<upperlimit;
		    if(Afunc!="null")
            cout<<"\nActual function is F(x) : "<<Afunc;
		    cout<<"\nfinal Euler function is : "<<finalfunc;
			cout<<"\n H = "<<vars[2];
			cout<<"\n Xo = "<<vars[0];
			cout<<"\n Yo = "<<vars[1];
			cout<<"\nFIX VALUE="<<fixval<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }

};

class Midpoint
{
    private:
		int fixval;
		long double error,upperlimit,lowerlimit;
        double *vars; //vars[0] (holds X) vars[1] (holds y) vars[2] (holds h)
		int iteration;
	    string midpointstring,givenfunctionstring,realfunctionstring;
        FunctionParser midpoint,givenfunction,realfunction;

    public:
        Midpoint()
        {
            upperlimit=lowerlimit=0;
            vars=new double[3];
            givenfunction.AddConstant("pi", 3.1415926535897932);
            realfunction.AddConstant("pi", 3.1415926535897932);
            midpoint.AddConstant("pi", 3.1415926535897932);
        }
        void setparameters(void)
        {
            iteration=0;
            error=999;
            midpointstring="y+h*(A)";
            midpoint.Parse(midpointstring,"y,h,A");
            system("cls");
			cout<<"\nenter value for Xo:";
			cin>>vars[0];
			cout<<"\nenter value for Yo:";
			cin>>vars[1];
			cout<<"\nenter value for H:";
			cin>>vars[2];
			cout<<"\nenter value for upper limit or the approximation value :";
			cin>>upperlimit;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function Y' or F(X,Y) = ";
            cin>>givenfunctionstring;
            if(cin.fail())
            continue;
            int res = givenfunction.Parse(givenfunctionstring, "x,y");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< givenfunction.ErrorMsg() << "\n\n";
            }
            cout<<"\ndo you want to set Actual function F(x) ? (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y')
            while(true)
            {
            cout << "enter function F(x) = ";
            cin>>realfunctionstring;
            if(cin.fail())
            continue;
            int res =realfunction.Parse(realfunctionstring, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< realfunction.ErrorMsg() << "\n\n";
            }
            else
            realfunctionstring="null";
            lowerlimit=vars[0];
            printdetails();
        }
        void evaluate(void)
        {
         if(realfunctionstring=="null")
         {
             double B[2],A[2],mainvars[3];
             mainvars[1]=vars[2];
             cout<<"\nN	|	     X        | 	    Mid point	     \n"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<endl;
                 B[0]=vars[0];B[1]=vars[1];
                 A[0]=vars[0]+(vars[2]/2);A[1]=vars[1]+(vars[2]/2)*givenfunction.Eval(B);
                 mainvars[2]=givenfunction.Eval(A);
                 mainvars[0]=vars[1];

                 vars[1]=midpoint.Eval(mainvars);
                 vars[0]+=vars[2];
                 iteration++;
             }
         }
         else
         {
            double B[2],A[2],mainvars[3],temp;
             mainvars[1]=vars[2];
             temp=vars[1];
             cout<<"\nN	|	    X        | 	     Mid point	     |           Y(x)                |          ERROR\n"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<iteration<<"\t\t"<<vars[0]<<"\t\t\t"<<vars[1]<<"\t\t\t"<<temp<<"\t\t\t"<<fabs(temp-vars[1])<<endl;
                 B[0]=vars[0];B[1]=vars[1];
                 A[0]=vars[0]+(vars[2]/2);A[1]=vars[1]+(vars[2]/2)*givenfunction.Eval(B);
                 mainvars[2]=givenfunction.Eval(A);
                 mainvars[0]=vars[1];

                 vars[1]=midpoint.Eval(mainvars);
                 vars[0]+=vars[2];
                 temp=realfunction.Eval(vars);
                 iteration++;
             }
         }
         system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is Y' or f(x,y) = "<<givenfunctionstring<<"    with "<<lowerlimit<<"<=X<="<<upperlimit;
		    if(realfunctionstring!="null")
            cout<<"\nActual/Real function is F(x) : "<<realfunctionstring;
			cout<<"\n H = "<<vars[2];
			cout<<"\n Xo = "<<vars[0];
			cout<<"\n Yo = "<<vars[1];
			cout<<"\nFIX VALUE="<<fixval<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class Huen
{
    private:
		int fixval;
		long double error,upperlimit,lowerlimit,k1,k2;
        double *vars,*vars4huen;
		int iteration;
	    string fxy,yx,huenstring;
        FunctionParser Fxy,Yx,Huenstring;

    public:
        Huen()
        {
            upperlimit=lowerlimit=0;
            vars=new double[3];
            vars4huen=new double[4];//0 y 1 k1 2 k2 3 h
            Fxy.AddConstant("pi", 3.1415926535897932);
            Yx.AddConstant("pi", 3.1415926535897932);
            Huenstring.AddConstant("pi", 3.1415926535897932);
        }
        void setparameters(void)
        {
            iteration=0;
            error=999;

            huenstring="y+((1/2*A)+(1/2*B))*h";//A == K1 and B == K2
            Huenstring.Parse(huenstring,"y,A,B,h");

            system("cls");
			cout<<"\nenter value for Xo:";
			cin>>vars[0];
			cout<<"\nenter value for Yo:";
			cin>>vars[1];
			cout<<"\nenter value for H:";
			cin>>vars[2];
			cout<<"\nenter value for upper limit or the approximation value :";
			cin>>upperlimit;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function Y' or F(X,Y) = ";
            cin>>fxy;
            if(cin.fail())
            continue;
            int res = Fxy.Parse(fxy, "x,y");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< Fxy.ErrorMsg() << "\n\n";
            }
            cout<<"\ndo you want to set Actual function F(x) or Y(x) ? (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y')
            while(true)
            {
            cout << "enter function F(x) of Y(x) = ";
            cin>>yx;
            if(cin.fail())
            continue;
            int res = Yx.Parse(yx, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< Yx.ErrorMsg() << "\n\n";
            }
            else
            yx="null";
            lowerlimit=vars[0];
            printdetails();
        }
        void evaluate(void)
        {
         if(yx=="null")
         {
             double temp[2];
             cout<<setprecision(fixval)<<"\tX      |          Y "<<endl;
             while(vars[0]<=upperlimit)
             {
             cout<<setprecision(fixval+1)<<"\t"<<vars[0]<<"\t\t"<<vars[1]<<endl;
             k1=Fxy.Eval(vars);
             temp[0]=vars[0]+vars[2];temp[1]=vars[1]+k1*vars[2];
             k2=Fxy.Eval(temp);
             vars4huen[0]=vars[1];vars4huen[1]=k1;vars4huen[2]=k2;vars4huen[3]=vars[2];
             vars[0]+=vars[2];
             vars[1]=Huenstring.Eval(vars4huen);
             }
         }
         else
         {
            double temp[2],ER=vars[1];
             cout<<"\tX      |          Y         |        ACTUAL          |          ERROR"<<endl;
             while(vars[0]<=upperlimit)
             {

             cout<<setprecision(fixval+1)<<"\t"<<vars[0]<<"\t\t"<<vars[1]<<"\t\t\t"<<ER<<"\t\t\t"<<fabs(ER-vars[1])<<endl;
             k1=Fxy.Eval(vars);
             temp[0]=vars[0]+vars[2];temp[1]=vars[1]+k1*vars[2];
             k2=Fxy.Eval(temp);
             vars4huen[0]=vars[1];vars4huen[1]=k1;vars4huen[2]=k2;vars4huen[3]=vars[2];
             vars[0]+=vars[2];
             ER=Yx.Eval(vars);
             vars[1]=Huenstring.Eval(vars4huen);
             }
         }
         system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is Y' or f(x,y) = "<<fxy<<"    with "<<lowerlimit<<"<=X<="<<upperlimit;
		    if(yx!="null")
            cout<<"\nActual/Real function is F(x) : "<<yx;
			cout<<"\n H = "<<vars[2];
			cout<<"\n Xo = "<<vars[0];
			cout<<"\n Yo = "<<vars[1];
			cout<<"\nFIX VALUE="<<fixval<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class RK4
{
     private:
		int fixval;
		long double error,upperlimit,lowerlimit,k1,k2,k3,k4;
        double *vars,*vars4RK;
		int iteration;
	    string fxy,yx,rkstring;
        FunctionParser Fxy,Yx,RKstring;

    public:
        RK4()
        {
            upperlimit=lowerlimit=0;
            vars=new double[3];
            vars4RK=new double[5];//0 y 1 k1 2 k2 3 k3 4 k4
            Fxy.AddConstant("pi", 3.1415926535897932);
            Yx.AddConstant("pi", 3.1415926535897932);
            RKstring.AddConstant("pi", 3.1415926535897932);
        }
        void setparameters(void)
        {
            iteration=0;
            error=999;

            rkstring="y+(1/6)*(A+2*B+2*C+D)";//A == K1 , B == K2 , C == K3 , D == K4
            RKstring.Parse(rkstring,"y,A,B,C,D");

            system("cls");
			cout<<"\nenter value for Xo:";
			cin>>vars[0];
			cout<<"\nenter value for Yo:";
			cin>>vars[1];
			cout<<"\nenter value for H:";
			cin>>vars[2];
			cout<<"\nenter value for upper limit or the approximation value :";
			cin>>upperlimit;
			cout<<"\nenter fix value:";
			cin>>fixval;
            while(true)
            {
            cout << "enter function Y' or F(X,Y) = ";
            cin>>fxy;
            if(cin.fail())
            continue;
            int res = Fxy.Parse(fxy, "x,y");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< Fxy.ErrorMsg() << "\n\n";
            }
            cout<<"\ndo you want to set Actual function F(x) or Y(x) ? (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y')
            while(true)
            {
            cout << "enter function F(x) of Y(x) = ";
            cin>>yx;
            if(cin.fail())
            continue;
            int res = Yx.Parse(yx, "x");
             if(res < 0)
                break;
             cout << string(res+7, ' ') << "^\n"<< Yx.ErrorMsg() << "\n\n";
            }
            else
            yx="null";
            lowerlimit=vars[0];
            printdetails();
        }
        void evaluate(void)
        {
         if(yx=="null")
         {
             double *temp;
             temp=new double[2];
             cout<<setprecision(fixval)<<"\tX      |          Y "<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<"\t"<<vars[0]<<"\t\t"<<vars[1]<<endl;
                 k1=vars[2]*Fxy.Eval(vars);
                 temp[0]=vars[0]+(vars[2]/2);temp[1]=vars[1]+(k1/2);

                 k2=vars[2]*Fxy.Eval(temp);
                 temp[0]=vars[0]+(vars[2]/2);temp[1]=vars[1]+(k2/2);

                 k3=vars[2]*Fxy.Eval(temp);
                 temp[0]=vars[0]+vars[2];temp[1]=vars[1]+k3;

                 k4=vars[2]*Fxy.Eval(temp);

                 vars4RK[0]=vars[1];vars4RK[1]=k1;vars4RK[2]=k2;vars4RK[3]=k3;vars4RK[4]=k4;
                 vars[1]=RKstring.Eval(vars4RK);
                 vars[0]+=vars[2];

             }
         }
         else
         {
             double *temp;
             temp=new double[2];
             cout<<setprecision(fixval)<<"\tX      |          Y           |         ACTUAL       |        ERROR"<<endl;
             while(vars[0]<=upperlimit)
             {
                 cout<<setprecision(fixval+1)<<"\t"<<vars[0]<<"\t\t"<<vars[1]<<"\t\t\t"<<Yx.Eval(vars)<<"\t\t "<<fabs(vars[1]-Yx.Eval(vars))<<endl;
                 k1=vars[2]*Fxy.Eval(vars);
                 temp[0]=vars[0]+(vars[2]/2);temp[1]=vars[1]+(k1/2);

                 k2=vars[2]*Fxy.Eval(temp);
                 temp[0]=vars[0]+(vars[2]/2);temp[1]=vars[1]+(k2/2);

                 k3=vars[2]*Fxy.Eval(temp);
                 temp[0]=vars[0]+vars[2];temp[1]=vars[1]+k3;

                 k4=vars[2]*Fxy.Eval(temp);

                 vars4RK[0]=vars[1];vars4RK[1]=k1;vars4RK[2]=k2;vars4RK[3]=k3;vars4RK[4]=k4;
                 vars[1]=RKstring.Eval(vars4RK);
                 vars[0]+=vars[2];

             }
         }
         system("pause");
        }
        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
		    cout<<"\nfunctions is Y' or f(x,y) = "<<fxy<<"    with "<<lowerlimit<<"<=X<="<<upperlimit;
		    if(yx!="null")
            cout<<"\nActual/Real function is F(x) : "<<yx;
			cout<<"\n H = "<<vars[2];
			cout<<"\n Xo = "<<vars[0];
			cout<<"\n Yo = "<<vars[1];
			cout<<"\nFIX VALUE="<<fixval<<endl;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }


};

class gauss
{
     private:
		int fixval,matsiz;
		double *vals,**matrix,*consmat;
		double initialapprox;
		int iteration;
	    string *functions,*varnames;
        FunctionParser *FUNCTIONS;
        ostringstream ststream;

        void makediagdom (void)
        {
            int sum=0;
            for(int row=0;row<matsiz;row++)
            {

                for(int col=0;col<matsiz;col++)
                {

                    for(int a=0;a<matsiz;a++)
                    {

                        if(a==col)
                            continue;

                        sum+=fabs(matrix[row][a]);
                    }

                    if(fabs(matrix[row][col])>=sum)
                    {
                        double *temp,temp2;
                        temp2=consmat[row];
                        temp=matrix[row];
                        matrix[row]=matrix[col];
                        consmat[row]=consmat[col];
                        matrix[col]=temp;
                        consmat[col]=temp2;
                        break;
                    }
                    sum=0;

                }
            }
        }

        void generatefunctions (void)
        {
            ostringstream vnam,func;
            for(int row=0;row<matsiz;row++)
            {
                vnam.str("");
                func.str("");
                vnam.clear();
                func.clear();

                func<<"(";
                for(int col=0;col<matsiz;col++)
                {
                    if(col==row)
                        continue;

                    func<<"("<<matrix[row][col]*(-1)<<")*x"<<col<<"+";
                    vnam<<"x"<<col<<",";
                }
                func<<"("<<consmat[row]<<")"<<")/"<<matrix[row][row];
                functions[row]=func.str();
                varnames[row]=vnam.str();
                varnames[row].pop_back();

                //cout<<"\nfunction looks like : "<<functions[row]<<endl;
                //cout<<"\nwith variable names : "<<varnames[row]<<endl;

                FUNCTIONS[row].Parse(functions[row],varnames[row]);
            }
        }
     public:
        gauss()
        {
            system("cls");
            cout<<"\t\t\t\t\t\tNOTES"<<endl<<endl;
            cout<<"This module (Gauss method) will take input in matrix form"<<endl<<endl;
            system("pause");
            system("cls");
            matrix=NULL;
        }
         bool chkdiagdom (void)
        {
            int sum=0;
           for(int row=0;row<matsiz;row++)
           {

               for(int col=0;col<matsiz;col++)
               {
                 for(int a=0;a<matsiz;a++)
                    {

                        if(a==col)
                            continue;

                        sum+=fabs(matrix[row][a]);
                    }
               }
               if(fabs(matrix[row][row])>=sum)
                {
                    continue;
                }
                else
                return false;
               sum=0;
           }
            return true;
        }
        void setparameters(void)
        {

            system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter number of iterations given : ";
            cin>>iteration;
            cout<<"\nenter initial approximation : ";
            cin>>initialapprox;
            cout<<"\nenter FIX value : ";
            cin>>fixval;

            cout<<"\nplease enter the size of matrix : ";
            cin>>matsiz;

            if(matrix!=NULL)
            {
            for(int i = 0; i < matsiz; ++i)
            delete[] matrix[i];
            delete[] matrix;

            delete [] vals;
            delete [] consmat;
            delete [] functions;
            delete [] varnames;
            delete [] FUNCTIONS;
            }

            consmat=new double[matsiz];
            matrix=new double*[matsiz];
            for(int a=0;a<matsiz;a++)
            matrix[a]=new double[matsiz];

             for(int row=0;row<matsiz;row++)
            {
                for(int col=0;col<matsiz;col++)
                {
                    cout<<"A["<<row<<"]["<<col<<"]->";
                    cin>>matrix[row][col];
                }
                cout<<"\n now enter constant value of equation "<<row+1<<" : ";
                cin>>consmat[row];
                cout<<endl;

            }
            functions = new string[matsiz];
            varnames = new string[matsiz];
            FUNCTIONS=new FunctionParser[matsiz];
            vals=new double[matsiz];
            makediagdom();
            generatefunctions();

            system("pause");
            system("cls");
            printdetails();
        }

        void evaluate(void)
        {

                string temp;
                ststream.str("");
                ststream.clear();
                ststream<<"ITERATIONS\t\t";
                for(int a=1;a<=matsiz;a++)
                {
                    ststream<<"x"<<a;
                    ststream<<"\t\t";
                }
                temp=ststream.str();
                cout<<temp<<endl<<endl;

                double *variables;
                variables=new double[matsiz-1];

                ///////////////sari equations main initial approximation dalna
                for(int a=0;a<matsiz-1;a++)
                {
                    variables[a]=initialapprox;
                    vals[a]=initialapprox;
                }
                //////////////////////////////////////////////////////////////
                //vals ke index pe ab x1,x2,x3,x4..... ki resulting values hain after
                //substituting initial approximation value
                //////////////////////////////////////////////////////////////

                for(int loop=1;loop<=iteration;loop++)
                {
                    for(int a=0;a<matsiz;a++)//equation number iss loop se aye gaa
                    {

                        //////////////////////////////////////////////////////
                        //har equation ke liyay input variables taiyr krna hai
                        int i;
                        i=0;
                        for(int b=0;b<matsiz;b++)
                        {
                            if(a==b)
                                continue;
                            variables[i]=vals[b];
                            i++;
                        }
                        //////////////////////////////////////////////////////

                    /////////////////////////////////////////////////////////////////
                    vals[a]=FUNCTIONS[a].Eval(variables);
                    //iss mai finally hum jo current iteration pe hain uss kay liyay sari
                    //equations ke output collect krliay

                    }

                ///////////////////////////NOW PRINTING////////////////////////
                ststream.str("");
                ststream.clear();
                ststream<<"\t"<<loop<<"\t\t";
                for(int a=0;a<matsiz;a++)
                {
                    ststream<<vals[a];
                    ststream<<"\t\t";
                }
                temp=ststream.str();
                cout<<temp<<endl;
                //////////////////////////////////////////////////////////////

                }
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nnumber of iterations given : ";
            cout<<iteration;
            cout<<"\ninitial approximation : ";
            cout<<initialapprox;
            cout<<"\nFIX value : ";
            cout<<fixval;
            cout<<"\nmatrix is : "<<endl;
            for(int row=0;row<matsiz;row++)
            {
                for(int col=0;col<matsiz;col++)
                    cout<<"\t"<<matrix[row][col]<<" ";

                cout<<endl;
            }

            cout<<"\n\nEquations are : "<<endl;
            for(int a=0;a<matsiz;a++)
            {
                cout<<"x"<<a+1<<"="<<functions[a]<<endl;
            }

            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class jacob
{
     private:
		int fixval,matsiz;
		double *vals,**matrix,*consmat;
		double initialapprox;
		int iteration;
	    string *functions,*varnames;
        FunctionParser *FUNCTIONS;
        ostringstream ststream;

         void makediagdom (void)
        {
            int sum=0;
            for(int row=0;row<matsiz;row++)
            {

                for(int col=0;col<matsiz;col++)
                {

                    for(int a=0;a<matsiz;a++)
                    {

                        if(a==col)
                            continue;

                        sum+=fabs(matrix[row][a]);
                    }

                    if(fabs(matrix[row][col])>=sum)
                    {
                        double *temp,temp2;
                        temp2=consmat[row];
                        temp=matrix[row];
                        matrix[row]=matrix[col];
                        consmat[row]=consmat[col];
                        matrix[col]=temp;
                        consmat[col]=temp2;
                        break;
                    }
                    sum=0;

                }
            }
        }

        void generatefunctions (void)
        {
            ostringstream vnam,func;
            for(int row=0;row<matsiz;row++)
            {
                vnam.str("");
                func.str("");
                vnam.clear();
                func.clear();

                func<<"(";
                for(int col=0;col<matsiz;col++)
                {
                    if(col==row)
                        continue;

                    func<<"("<<matrix[row][col]*(-1)<<")*x"<<col<<"+";
                    vnam<<"x"<<col<<",";
                }
                func<<"("<<consmat[row]<<")"<<")/"<<matrix[row][row];
                functions[row]=func.str();
                varnames[row]=vnam.str();
                varnames[row].pop_back();

                //cout<<"\nfunction looks like : "<<functions[row]<<endl;
                //cout<<"\nwith variable names : "<<varnames[row]<<endl;

                FUNCTIONS[row].Parse(functions[row],varnames[row]);
            }
        }

     public:
        jacob()
        {
            system("cls");
            cout<<"\t\t\t\t\t\tNOTES"<<endl<<endl;
            cout<<" This module (Jacob's method) will take input in matrix form"<<endl<<endl;
            system("pause");
            system("cls");
        }
        bool chkdiagdom (void)
        {
            int sum=0;
           for(int row=0;row<matsiz;row++)
           {

               for(int col=0;col<matsiz;col++)
               {
                 for(int a=0;a<matsiz;a++)
                    {

                        if(a==col)
                            continue;

                        sum+=fabs(matrix[row][a]);
                    }
               }
               if(fabs(matrix[row][row])>=sum)
                {
                    continue;
                }
                else
                return false;
               sum=0;
           }
            return true;
        }
        void setparameters(void)
        {
           system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter number of iterations given : ";
            cin>>iteration;
            cout<<"\nenter initial approximation : ";
            cin>>initialapprox;
            cout<<"\nenter FIX value : ";
            cin>>fixval;

            cout<<"\nplease enter the size of matrix : ";
            cin>>matsiz;

            if(matrix!=NULL)
            {
            for(int i = 0; i < matsiz; ++i)
            delete[] matrix[i];
            delete[] matrix;

            delete [] vals;
            delete [] consmat;
            delete [] functions;
            delete [] varnames;
            delete [] FUNCTIONS;
            }

            consmat=new double[matsiz];
            matrix=new double*[matsiz];
            for(int a=0;a<matsiz;a++)
            matrix[a]=new double[matsiz];

             for(int row=0;row<matsiz;row++)
            {
                for(int col=0;col<matsiz;col++)
                {
                    cout<<"A["<<row<<"]["<<col<<"]->";
                    cin>>matrix[row][col];
                }
                cout<<"\n now enter constant value of equation "<<row+1<<" : ";
                cin>>consmat[row];
                cout<<endl;

            }
            functions = new string[matsiz];
            varnames = new string[matsiz];
            FUNCTIONS=new FunctionParser[matsiz];
            vals=new double[matsiz];
            makediagdom();
            if(chkdiagdom())
            {

            }
            else
            {
                system("cls");
                cout<<"\nmatrix is not diagonally dominant";
                return;
            }
            generatefunctions();

            system("pause");
            system("cls");
            printdetails();
        }

        void evaluate(void)
        {

                string temp;
                ststream.str("");
                ststream.clear();
                ststream<<"ITERATIONS\t\t";
                for(int a=1;a<=matsiz;a++)
                {
                    ststream<<"x"<<a;
                    ststream<<"\t\t";
                }
                temp=ststream.str();
                cout<<temp<<endl<<endl;

                double *variables;
                variables=new double[matsiz-1];

                ///////////////sari equations main initial approximation dalna
                for(int a=0;a<matsiz-1;a++)
                {
                    variables[a]=initialapprox;
                }
                 double *temp2;
                 temp2=new double[matsiz];
                 for(int a=0;a<matsiz;a++)
                {
                    vals[a]=FUNCTIONS[a].Eval(variables);
                    temp2[a]=vals[a];
                }

                ststream.str("");
                ststream.clear();
                ststream<<"\t"<<1<<"\t\t";
                for(int a=0;a<matsiz;a++)
                {
                    ststream<<vals[a];
                    ststream<<"\t\t";
                }
                temp=ststream.str();
                cout<<temp<<endl;
                //////////////////////////////////////////////////////////////
                //vals ke index pe ab x1,x2,x3,x4..... ki resulting values hain after
                //substituting initial approximation value
                //////////////////////////////////////////////////////////////

                for(int loop=2;loop<=iteration;loop++)
                {
                    for(int a=0;a<matsiz;a++)//equation number iss loop se aye gaa
                    {

                        //////////////////////////////////////////////////////
                        //har equation ke liyay input variables taiyr krna hai
                        int i;
                        i=0;
                        for(int b=0;b<matsiz;b++)
                        {
                            if(a==b)
                                continue;
                            variables[i]=temp2[b];
                            i++;
                        }
                        //////////////////////////////////////////////////////

                    /////////////////////////////////////////////////////////////////
                    vals[a]=FUNCTIONS[a].Eval(variables);
                    //iss mai finally hum jo current iteration pe hain uss kay liyay sari
                    //equations ke output collect krliay

                    }

                ///////////////////////////NOW PRINTING////////////////////////
                ststream.str("");
                ststream.clear();
                ststream<<"\t"<<loop<<"\t\t";
                for(int a=0;a<matsiz;a++)
                {
                    ststream<<vals[a];
                    temp2[a]=vals[a];
                    ststream<<"\t\t";
                }
                temp=ststream.str();
                cout<<temp<<endl;
                //////////////////////////////////////////////////////////////

                }
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nnumber of iterations given : ";
            cout<<iteration;
            cout<<"\ninitial approximation : ";
            cout<<initialapprox;
            cout<<"\nFIX value : ";
            cout<<fixval;
            cout<<"\nmatrix is : "<<endl;
            for(int row=0;row<matsiz;row++)
            {
                for(int col=0;col<matsiz;col++)
                    cout<<"\t"<<matrix[row][col]<<" ";

                cout<<endl;
            }

            cout<<"\n\nEquations are : "<<endl;
            for(int a=0;a<matsiz;a++)
            {
                cout<<"x"<<a+1<<"="<<functions[a]<<endl;
            }

            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class Trapezoidal
{
    private:
        int n,iteration;
        string fx,trap,xi;
        double *vars,*x,a,b,delX,finalans;
        FunctionParser FX,TRAP,XI;
        ostringstream ststream,vnam;

    public:
        Trapezoidal()
        {
            iteration=0;
            a=b=0;
            xi="a+(i*x)";
            XI.Parse(xi,"a,i,x");
        }

        void setparameters(void)
        {
            system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter value of N : ";//greater value of N better the accuracy
            cin>>n;
            cout<<"\nenter value of a : ";
            cin>>a;
            cout<<"\nenter value of b : ";
            cin>>b;
            while(true)
                {
                cout << "enter function F(x) = ";
                cin>>fx;
                if(cin.fail())
                continue;
                int res =FX.Parse(fx,"x");
                 if(res < 0)
                    break;
                 cout << string(res+7, ' ') << "^\n"<< FX.ErrorMsg() << "\n\n";
                }
            printdetails();
        }

        void evaluate(void)
        {
            x=new double[n+1];
            vars=new double[n+2];
            delX=(b-a)/n;
            double temp[3];//0 a 1 i 2 delx
                temp[0]=a;
                temp[2]=delX;
            //making array of Xs
            for(int loop=0;loop<=n;loop++)
            {
                temp[1]=loop;
                x[loop]=XI.Eval(temp);
            }

             string varnames;

             ststream.str("");
             ststream.clear();
             vnam.str("");
             vnam.clear();

             ststream<<"x/2*(x0";
             vnam<<"x,x0";

                for(int loop=1;loop<n;loop++)
                {
                    ststream<<"+2*x"<<loop;
                    vnam<<",x"<<loop;
                }
                ststream<<"+x"<<n<<")";
                vnam<<",x"<<n;
                trap=ststream.str();
                varnames=vnam.str();

               cout<<"\n trapizoidal formula is "<<trap<<endl;
               //cout<<"\n with variables : "<<varnames<<endl;

                TRAP.Parse(trap,varnames);
                vars[0]=delX;
                int i=1;
                for(int loop=0;loop<=n;loop++)
                {
                    temp[0]=x[loop];
                    vars[i]=FX.Eval(temp);
                    i++;
                }
                finalans=TRAP.Eval(vars);
                cout<<"\nCALCULATED VALUE IS : "<<finalans<<endl;
                system("pause");
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nvalue of N : ";
            cout<<n;
            cout<<"\nvalue of a  : ";
            cout<<a;
            cout<<"\nvalue of b  : ";
            cout<<b;
            cout<<"\n\nF(x) = ";
            cout<<fx;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }

};

class NIMidpoint
{
    private:
        int n,iteration;
        string fx,trap,xi;
        double *vars,*x,a,b,delX,finalans;
        FunctionParser FX;
        ostringstream ststream,vnam;

    public:
        NIMidpoint()
        {
            iteration=0;
            a=b=0;
        }

        void setparameters(void)
        {
            system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter value of N (if n is not given then enter -1): ";//greater the value of N better the accuracy
            cin>>n;
            cout<<"\nenter value of a : ";
            cin>>a;
            cout<<"\nenter value of b : ";
            cin>>b;
            while(true)
                {
                cout << "enter function F(x) = ";
                cin>>fx;
                if(cin.fail())
                continue;
                int res =FX.Parse(fx,"x");
                 if(res < 0)
                    break;
                 cout << string(res+7, ' ') << "^\n"<< FX.ErrorMsg() << "\n\n";
                }
            printdetails();
        }

        void evaluate(void)
        {
            x=new double[n+1];
            vars=new double[n];
            delX=((b)-(a))/n;

            x[0]=a;
            for(int loop=1;loop<=n;loop++)
            {
                x[loop]=x[loop-1]+delX;
                // cout<<"\nx["<<loop<<"] = "<<x[loop];
            }

            for(int loop=0;loop<n;loop++)
            {
                vars[loop]=(x[loop]+x[loop+1])/2;
               // cout<<"\nvars["<<loop<<"] = "<<vars[loop];
            }

            long double sum=0;

            for(int loop=0;loop<n;loop++)
            {
                double *temp=new double;
                *temp=vars[loop];
                sum+=(FX.Eval(temp))*(delX);
            }
            cout<<"\nfinal answer is : "<<sum;
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nvalue of N : ";
            cout<<n;
            cout<<"\nvalue of a  : ";
            cout<<a;
            cout<<"\nvalue of b  : ";
            cout<<b;
            cout<<"\n\nF(x) = ";
            cout<<fx;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};

class Simpson
{
   private:
        int n,iteration;
        string fx,trap,xi;
        double *vars,*x,a,b,delX,finalans;
        FunctionParser FX,TRAP,XI;
        ostringstream ststream,vnam;

    public:
        Simpson()
        {
            iteration=0;
            a=b=0;
            xi="a+(i*x)";
            XI.Parse(xi,"a,i,x");
        }

        bool setparameters(void)
        {
            system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter value of N : ";//greater value of N better the accuracy
            cin>>n;
            if((n%2)!=0)
                return false;
            cout<<"\nenter value of a : ";
            cin>>a;
            cout<<"\nenter value of b : ";
            cin>>b;
            while(true)
                {
                cout << "enter function F(x) = ";
                cin>>fx;
                if(cin.fail())
                continue;
                int res =FX.Parse(fx,"x");
                 if(res < 0)
                    break;
                 cout << string(res+7, ' ') << "^\n"<< FX.ErrorMsg() << "\n\n";
                }
            printdetails();
            return true;
        }

        void evaluate(void)
        {
            x=new double[n+1];
            vars=new double[n+2];
            delX=(b-a)/n;
            double temp[3];//0 a 1 i 2 delx
                temp[0]=a;
                temp[2]=delX;
            //making array of Xs
            for(int loop=0;loop<=n;loop++)
            {
                temp[1]=loop;
                x[loop]=XI.Eval(temp);
            }

             string varnames;

             ststream.str("");
             ststream.clear();
             vnam.str("");
             vnam.clear();

             ststream<<"3*x/8*(x0";
             vnam<<"x,x0";

                for(int loop=1;loop<n;loop++)
                {
                    if((loop%2)==0)
                    ststream<<"+2*x"<<loop;
                    else
                    ststream<<"+4*x"<<loop;

                    vnam<<",x"<<loop;
                }
                ststream<<"+x"<<n<<")";
                vnam<<",x"<<n;
                trap=ststream.str();
                varnames=vnam.str();

             //  cout<<"\n simson formula is "<<trap<<endl;
             //  cout<<"\n with variables : "<<varnames<<endl;

                TRAP.Parse(trap,varnames);
                vars[0]=delX;
                int i=1;
                for(int loop=0;loop<=n;loop++)
                {
                    temp[0]=x[loop];
                    vars[i]=FX.Eval(temp);
                    i++;
                }
                finalans=TRAP.Eval(vars);
                cout<<"\nCALCULATED VALUE IS : "<<finalans<<endl;
                system("pause");
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nvalue of N : ";
            cout<<n;
            cout<<"\nvalue of a  : ";
            cout<<a;
            cout<<"\nvalue of b  : ";
            cout<<b;
            cout<<"\n\nF(x) = ";
            cout<<fx;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }

};

class Boole
{
    private:
        int n,iteration;
        string fx,trap,xi;
        double *vars,*x,a,b,delX,finalans;
        FunctionParser FX,TRAP,XI;
        ostringstream ststream,vnam;

    public:
        Boole()
        {
            iteration=0;
            a=b=0;
            xi="a+(i*x)";
            XI.Parse(xi,"a,i,x");
        }

        bool setparameters(void)
        {
            system("cls");
            cout<<"\t\t\t\t\tSET PARAMETERS";
            cout<<"\nenter value of N : ";//greater value of N better the accuracy
            cin>>n;
            if((n%2)==0)
                return false;
            cout<<"\nenter value of a : ";
            cin>>a;
            cout<<"\nenter value of b : ";
            cin>>b;
            while(true)
                {
                cout << "enter function F(x) = ";
                cin>>fx;
                if(cin.fail())
                continue;
                int res =FX.Parse(fx,"x");
                 if(res < 0)
                    break;
                 cout << string(res+7, ' ') << "^\n"<< FX.ErrorMsg() << "\n\n";
                }
            printdetails();
            return true;
        }

        void evaluate(void)
        {
            x=new double[n+1];
            vars=new double[n+2];
            delX=(b-a)/n;
            double temp[3];//0 a 1 i 2 delx
                temp[0]=a;
                temp[2]=delX;
            //making array of Xs
            for(int loop=0;loop<=n;loop++)
            {
                temp[1]=loop;
                x[loop]=XI.Eval(temp);
            }

             string varnames;

             ststream.str("");
             ststream.clear();
             vnam.str("");
             vnam.clear();

             ststream<<"(3*x)/8*(x0";
             vnam<<"x,x0";

                for(int loop=1;loop<n;loop++)
                {
                    ststream<<"+3*x"<<loop;

                    vnam<<",x"<<loop;
                }
                ststream<<"+x"<<n<<")";
                vnam<<",x"<<n;
                trap=ststream.str();
                varnames=vnam.str();

               cout<<"\n boole's formula is "<<trap<<endl;
               cout<<"\n with variables : "<<varnames<<endl;

                TRAP.Parse(trap,varnames);
                vars[0]=delX;
                int i=1;
                for(int loop=0;loop<=n;loop++)
                {
                    temp[0]=x[loop];
                    vars[i]=FX.Eval(temp);
                    i++;
                }
                finalans=TRAP.Eval(vars);
                cout<<"\nCALCULATED VALUE IS : "<<finalans<<endl;
                system("pause");
        }

        void printdetails(void)
		{
		    system("cls");
		    cout<<"parameters set by the user are :"<<endl;
            cout<<"\nvalue of N : ";
            cout<<n;
            cout<<"\nvalue of a  : ";
            cout<<a;
            cout<<"\nvalue of b  : ";
            cout<<b;
            cout<<"\n\nF(x) = ";
            cout<<fx;
            cout<<"\n\nAre the details shown correct ? (y/n) = ";
			char cho;
			cin>>cho;
			if(cho=='n')
            setparameters();
			system("pause");
		 }
};


int main()
{
	while(1)
	{
        system("cls");
		int cho;
		char choice='y';
		cout<<"\n\t\t\t\tPROJECT CONTENTS/MODULES"<<endl<<endl;
		cout<<"\n1 for Solution of non linear equation : \n\tBisection,Fixed Point iteration ,Regula False , Newton and Secant Method."<<endl<<endl;
		cout<<"\n2 for Numerical Integration:\n\tTrapezoidal , Midpoint , Simpson's and Boole's formula."<<endl<<endl;
		cout<<"\n3 for Solution of ordinary differential equation : \n\tEuler's , Huen's , 4-RK Method."<<endl<<endl;
		cout<<"\n4 for System of linear equation: \n\t(Iterative methods)Gauss-Siedel and Jacobi's methods."<<endl<<endl;
		cout<<"\n5 to Exit the program"<<endl<<endl;
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>cho;
		system("cls");
		switch (cho)
		{
        case(1)://Solution of non linear equation (complete) (NOT TESTED)
            {
                 while(choice=='y')
                {
                    system("cls");
                    cout<<"press the number to select its corresponding module \n1 bisection \n2 false position \n3 newton \n4 secant\n5 Fix point iteration\n6 Exit to main menu : "<<endl;
                    cout<<"\nselect the method : ";
                    cin>>cho;
                    switch(cho)
                    {
                        case 1:
                        {
                          bisection *B;
                          B=new bisection;
                          B->setparameters();
                          B->evaluate();
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete B;
                        }
                        break;

                        case 2:
                        {
                          falseposition *F;
                          F=new falseposition;
                          F->setparameters();
                          F->evaluate();
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete F;
                        }
                        break;

                        case 3:
                        {
                          newton_method *N;
                          N=new newton_method;
                          N->setparameters();
                          N->printdetails();
                          cout<<"\n1 to follow Epsilon \n2 to input no of iteration \nenter your choice ";
                          int val;
                          cin>>val;
                          system("cls");
                          N->evaluate(val);
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete N;
                         }
                         break;

                        case 4:
                        {
                          secant_method *S;
                          S=new secant_method;
                          S->setparameters();
                          cout<<"\n1 to follow Epsilon \n2 to input no of iteration \nenter your choice ";
                          int val;
                          cin>>val;
                          system("cls");
                          S->evaluate(val);
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete S;
                         }
                         break;

                        case 5://fix point
                        {
                          fix_point *F;
                          F=new fix_point;
                          F->setparameters();
                          system("cls");
                          F->evaluate();
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete F;
                        }
                        break;

                        case 6:
                        {
                          choice='n';
                        }
                        break;

                        default:
                        {
                          cout<<"\nWRONG OPTION SELECTED!";
                          system("pause");
                          continue;
                        }
                    }// option 1 switch ends here
                }
            }//module 1 case ends here
            break;

        case(2)://Numerical Integration (complete) (NOT TESTED)
            {
                while(choice=='y')
                 {
                 system("cls");
                 cout<<"press the number to select its corresponding module \n1 Trapezoidal \n2 Midpoint \n3 Simpson's \n4 Boole's formuls\n5 Exit to main menu :"<<endl;
                 cout<<"\nselect the method : ";
                 cin>>cho;
                     switch(cho)
                     {
                        case (1)://Trapezoidal
                            {
                                Trapezoidal *T;
                                T=new Trapezoidal;
                                T->setparameters();
                                T->evaluate();
                                cout<<"\ndo you want to use this module again ? (y/n) ";
                                cin>>choice;
                                delete T;

                            }
                            break;

                        case (2)://Midpoint
                            {
                                NIMidpoint *N;
                                N=new NIMidpoint;
                                N->setparameters();
                                N->evaluate();
                                cout<<"\ndo you want to use this module again ? (y/n) ";
                                cin>>choice;
                                delete N;
                            }
                            break;

                        case (3)://Simpson's
                            {
                               Simpson *S;
                               S=new Simpson;
                               if(S->setparameters())
                               S->evaluate();
                               else
                               cout<<"\nvalue of N is not even so we cannot proceed with this module";
                               cout<<"\ndo you want to use this module again ? (y/n) ";
                               cin>>choice;
                               delete S;
                            }
                            break;

                        case (4)://Boole's formuls
                            {
                               Boole *B;
                               B=new Boole;
                               if(B->setparameters())
                               B->evaluate();
                               else
                               cout<<"\nvalue of N is not odd so we cannot proceed with this module";
                               cout<<"\ndo you want to use this module again ? (y/n) ";
                               cin>>choice;
                               delete B;
                            }
                            break;

                        case (5)://Exit to main menu
                            {
                              choice='n';
                                continue;
                            }
                            break;
                     }//switch ends
                 }//loop ends here
            }
            break;

        case(3)://Solution of ordinary differential equation (complete) (NOT TESTED)
            {
                while(choice=='y')
                 {
                 system("cls");
                 cout<<"press the number to select its corresponding module \n1 Euler's method \n2 Modified Euler's method \n3 Mid Point formula \n4 4 RK method\n5 Huen’s method\n6 Exit to main menu :"<<endl;
                 cout<<"\nselect the method : ";
                 cin>>cho;
                     switch(cho)
                     {
                        case (1)://Euler's method
                            {
                              euler *E;
                              E=new euler;
                              E->setparameters();
                              E->evaluate();
                              cout<<"\ndo you want to use this module again ? (y/n) ";
                              cin>>choice;
                              delete E;
                            }
                            break;

                        case (2):// Modified Euler's method
                            {
                              Meuler *ME;
                              ME=new Meuler;
                              ME->setparameters();
                              ME->evaluate();
                              cout<<"\ndo you want to use this module again ? (y/n) ";
                              cin>>choice;
                              delete ME;
                            }
                            break;

                        case (3)://midpoint
                            {
                              Midpoint *M;
                              M=new Midpoint;
                              M->setparameters();
                              M->evaluate();
                              cout<<"\ndo you want to use this module again ? (y/n) ";
                              cin>>choice;
                              delete M;
                            }
                            break;

                        case (4): //RK method
                            {
                              RK4 *R;
                              R=new RK4;
                              R->setparameters();
                              R->evaluate();
                              cout<<"\ndo you want to use this module again ? (y/n) ";
                              cin>>choice;
                              delete R;
                            }
                            break;

                        case (5)://Huen’s
                            {
                              Huen *H;
                              H=new Huen;
                              H->setparameters();
                              H->evaluate();
                              cout<<"\ndo you want to use this module again ? (y/n) ";
                              cin>>choice;
                              delete H;
                            }
                            break;

                        case (6):
                            {
                                choice='n';
                                continue;
                            }
                     }//switch ends
                 }//loop ends here
            }
            break;

        case(4)://System of linear equation Iterative methods (complete) (NOT TESTED)
            {
                 while(choice=='y')
                 {
                 system("cls");
                 cout<<"press the number to select its corresponding module \n1 Jacobi's method \n2 Gauss-Siedel method \n3 Exit to main menu :"<<endl;
                 cout<<"\nselect the method : ";
                 cin>>cho;
                     switch(cho)
                     {
                     case(1)://Jacobi’s method
                        {
                          jacob *J;
                          J=new jacob;
                          J->setparameters();
                          J->evaluate();
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete J;
                        }
                        break;

                     case(2)://Gauss-Siedel method
                        {
                          gauss *G;
                          G=new gauss;
                          G->setparameters();
                          G->evaluate();
                          cout<<"\ndo you want to use this module again ? (y/n) ";
                          cin>>choice;
                          delete G;
                        }
                        break;

                     case(3):
                        {
                           choice='n';
                        }
                        break;

                     default:
                        {
                          cout<<"\nWRONG OPTION SELECTED!"<<endl;
                          system("pause");
                          continue;
                        }
                     }//switch ends
                 }//loop ends here
            }//module 4 case ends here
            break;

        case(5)://EXIT MAIN PROGRAM
            {
                exit(0);
            }

        default:
            {
                cout<<"\nWRONG OPTION SELECTED!";
                system("pause");
                continue;
            }
		}// main switch ends here
	}
}
