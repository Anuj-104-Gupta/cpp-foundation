#include<iostream>
using namespace std;
void awrray()
{
   int n=1;
   int w[3]={1,2,3};
   for (auto x:w)
       cout<<x<<'\n';
   while (n<4){
       int *p=&w[n];
       *p=*p*2;
       n++;
   }
   for (auto x:w)
       cout<<x<<'\n';
}
int main(){
   awrray();
}

