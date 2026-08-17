#include<iostream>
#include<limits>
void demonstrate_overflow(){
   int max_signed_int=std::numeric_limits<int>::max();
   std::cout<<"The max int: "<<max_signed_int<<"\n";
   int max=max_signed_int+1;
   std::cout<<"The upper limit +1: "<<max<<"\n";
   unsigned int max_unsigned=std::numeric_limits<unsigned int>::max();
   std::cout<<"The max int"<<max_unsigned<<"\n";
   unsigned int max2=max_unsigned+1;
   std::cout<<"The upper limit: "<<max2<<"\n";
}
int main(){
    demonstrate_overflow();
    return 0;
}
