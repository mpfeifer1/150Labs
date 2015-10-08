// Program: PL7_Scoping.cpp

// Write the expected output from this program.  Then run it to check
// your understanding of the scope and lifetime aspects of variables.


#include<iostream>
using namespace std;

//---------------- Function Prototypes ----------------------
void a();
void b();
void c();
void d(int x);
void e(int &x);
int  f();
int  g(int x);

//---------------- Global Variable to illustrate scope -----
int x = 1;


//---------------------- Main Program ----------------------
int main()
{
   int x = 5;

   cout << "local x in outer scope of main is: "<< x << endl;
   {
	  int x = 7;
	  cout << "local x in inner scope of main is: "<< x << endl;
   }

   cout << "local x in outer scope of main is: "<< x << endl;
   a();
   b();
   c();
   a();
   b();
   c();
   cout << "local x in main is: "<< x << endl;

   cout << "x in the main program before calling d is : " << x << endl;
   d(x);
   cout << "x in the main program after calling d is : " << x << endl;

   cout << "x in the main program before calling e is : " << x << endl;
   e(x);
   cout << "x in the main program after calling e is : " << x << endl;

   cout << "x in the main program before calling f is : " << x << endl;
   x = f();
   cout << "x in the main program after calling f is : " << x << endl;

   cout << "x in the main program before calling g is : " << x << endl;
   x = g(x);
   cout << "x in the main program after calling g is : " << x << endl;

	return 0;
}


//--------------------- Function a -------------------------
void a()
{
   int x = 25;

   cout << "local x is: "<< x << " after entering a."<< endl;
   x++;
   cout << "local x is: "<< x << " before exiting a."<< endl;
}


//---------------------- Function b ------------------------
void b()
{
   static int x = 50;

   cout << "local static x is: " << x << " on entering b."<< endl;
   x++;
   cout << "local static x is: " << x << " on exiting b."<< endl;
}


//---------------------- Function c ------------------------
void c()
{
   cout << "global x is: "<< x << " on entering c."<< endl;
   x*=10;
   cout << "global x is: "<< x <<" on exiting c."<< endl;
}


//---------------------- Function d ------------------------
void d(int x)
{
   cout << "The parameter x on entering d is : " << x << endl;
   x++;
   cout << "The parameter x on exiting d is : " << x << endl;
}


//----------------------- Function e -----------------------
void e(int &x)
{
   cout << "The parameter x on entering e is : " << x << endl;
   x++;
   cout << "The parameter x on exiting e is : " << x << endl;
}


//----------------------- Function f -----------------------
int f()
{
   cout << "global x on entering f is : " << x << endl;
   x++;
   cout << "global x on exiting f is : " << x << endl;
   return(x);
}


//----------------------- Function g -----------------------
int g(int x)
{
   cout << "parameter x on entering g is : " << x << endl;
   x++;
   cout << "parameter x on exiting g is : " << x << endl;
   return(x);
}

