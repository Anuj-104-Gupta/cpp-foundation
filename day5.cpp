#include<iostream>
using namespace std;
/*
int main(){
   cout<<"Size of double=>"<<sizeof(double)<<'\n'<<"Size of int=>"<<sizeof(int)<<"\nSize of Value=>"<<sizeof(Value)<<'\n';
}
*/
enum class Type{INT,DOUBLE};
union Value {
   int i_val;
   double d_val;
};
struct Entry{
   Type tag;
   Value val;
};
void printEntry(const Entry& e){
   switch(e.tag){
       case Type::INT:
           cout<<"Integer value=>"<<e.val.i_val<<'\n';
           break;
       case Type::DOUBLE:
           cout<<"Double value=>"<<e.val.d_val<<'\n';
           break;
   }
}
int main(){
   Entry e1;
   e1.tag=Type::INT;
   e1.val.i_val=42;
   Entry e2;
   e2.tag=Type::DOUBLE;
   e2.val.d_val=3.14159;
   printEntry(e1);
   printEntry(e2);
   return 0;
}
