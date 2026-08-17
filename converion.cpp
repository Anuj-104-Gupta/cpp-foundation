#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
   cout<< setprecision(17);
   float t=15.02;
   double x=15.05;
   double q=t;
   float e=x;
   cout<<"The starting float: "<<t<<" and double: "<<x<<"\nThe conversion of float: "<<t<<" into double: "<<q<<"\n"<<"The conversion of double: "<<x<<" into float: "<<e<<"\n";
}

