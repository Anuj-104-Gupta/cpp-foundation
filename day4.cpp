#include<iostream>
using namespace std;
/*
//To Check the feasibilty of accessing value in case of Struct and Secret
struct Point{int x; int y;};
int main(){
   Point p;
   p.x=78;
   p.y=78;
   cout<<p.x<<"<--This is X "<<p.y<<"<--This is Y "<<'\n';
}

class Secret{int x;};
int main(){
   Secret s;
   s.x=78;
   cout<<s.x<<'\n';
}
*/
class Vector{
private:
   double* elem;
   int sz;
public:
   Vector(int s) {
       if (s >= 0) {
           elem = new double[s];
           sz = s;
       }
       else {
           elem = nullptr;
           sz = 0;
       }
   }
   int size() const{
       return sz;}
   double get(int i) const{
       if (i>=0){
           return elem[i];}
       else{
           return 15.0;}
   }
   ~Vector(){
       delete[] elem;
   }
   void set(int i, double val) {
       if (i >= 0 && i < sz && elem != nullptr) {
           elem[i] = val;
       }
   }
};
int main(){
   Vector v(3);
   v.set(0, 42.0);
   cout << "Vector size: " << v.size() << '\n';
   cout << "Element 0: " << v.get(0) << '\n';
    // Test invalid size handling
   Vector bad_v(-5);
   cout << "Bad vector size: " << bad_v.size() << '\n';
}
