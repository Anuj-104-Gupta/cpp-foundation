#include<stdexcept>
#include<iostream>
#include"buffer.h"
using namespace std;
using namespace CoreSystems;
int main(){
   Buffer buf;
   buf.data=new int[5];
   buf.capacity=5;
   buf.length=0;
   try{
       append(buf,56);
       append(buf,5);
       append(buf,57);
       append(buf,65);
       append(buf,77);
       append(buf,105);
   }
   catch(const out_of_range& e){
       cout<<e.what()<<'\n';
   }
   try{
       cout<<get(buf,4)<<'\n';
       cout<<get(buf,77)<<'\n';
   }
   catch(const out_of_range& e){
       cout<<e.what()<<'\n';
   }
   delete[] buf.data;
}
