#include<iostream>
#include<initializer_list>
#include<algorithm>
using namespace std;
class Vector{
private:
   int sz;
   double* elem;
public:
   Vector(int(s)){
       elem=new double[s];
       sz=s;
       for (auto i=0;i<s;i++){
           elem[i]=0.0;
       }
   }
   Vector(initializer_list<double> lst){
       sz=lst.size();
       elem=new double[sz];
       int i = 0;
       for (double val : lst) {
           elem[i++] = val;
       }
   }
   ~Vector(){
       delete[] elem;
   }
   int size() const{
       return sz;}
   double& operator[](int i){
       return elem[i];}
   const double& operator[](int i) const{
       return elem[i];}
};
int main(){
   Vector v1={1.2,3.4,5.3};
   Vector v2(3);
   const Vector& ref=v1;
   cout<<ref[0]<<'\n';

}
