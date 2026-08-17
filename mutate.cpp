#include<iostream>
using namespace std;
/*int incrementVal(int x)
{
   x=89;
   return x;
}
int main(){
   int q=78;
   cout<<q<<"<--Original "<<incrementVal(q)<<"<--Function"<<'\n';
}
int incrementRef(int& x)
{
   x=89;
   return x;
}
int main(){
   int q=78;
   int* p=&q;
   cout<<q<<"<--Original "<<incrementRef(p)<<"<--Function"<<'\n';
}
*/
int incrementPtr(auto p){
   *p=78;
   return 5;
}
int main(){
   int s=77;
   int* q=&s;
   cout<<s<<"<--Original "<<incrementPtr(q)<<s<<"<--Function"<<'\n';
}
