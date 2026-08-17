#include<iostream>
#include"day6.h"
#include<stdexcept>
using namespace std;
using namespace MyLib;
int main(){
   try{
       Vector v(-27);
       cout<<"Success";
   }
   catch(const length_error& e){
       cout<<e.what()<<'\n';
       cout<<"Hello\n";
   }
}
