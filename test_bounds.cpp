#include<iostream>
#include"day6.h"
#include<stdexcept>
using namespace std;
using namespace MyLib;
int main(){
   try{
       Vector v(3);
       v[0]=10.5;
       v[1]=20;
       v[2]=30.5;
       cout<<v[1]<<'\n';
       cout<<v[10]<<'\n';
       cout<<"Hello\n";
  }
  catch(const out_of_range& e){
       cout<<e.what()<<'\n';
  }
}
