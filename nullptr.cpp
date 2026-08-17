#include<iostream>
using namespace std;
void nullp(int* p){
   if (p != nullptr){
       cout<<"This pointer is not null :"<<p<<'\n';
   }else{
       cout<<"This pointer is null:"<<p<<'\n';
   }
}
int main(){
   int o=778;
   int *p=&o;
   nullp(p);
}
