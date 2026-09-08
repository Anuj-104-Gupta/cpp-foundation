#include<iostream>
#include<vector>
#include<functional>
#include <cstddef>
using namespace std;
/* Target 1
template<typename Container, typename Value, typename BinaryOp>
Value reduce(const Container& c, Value init, BinaryOp op){
   for (const auto& x:c){
       init=op(init,x);
   }
   return init;
}
int main(){
   vector<int> s={1,2,5};
   plus<int> p;
   vector<double> q={1.0,2.5,5.7};
   cout<<reduce(s, 0, plus<int>{}) << '\n';
   cout<<reduce(q, 1.0, multiplies<double>{}) << '\n';
}
Target 2
template<typename T> struct Between{
   T low;
   T high;
   Between(T l, T h) : low{l}, high{h} {}
   bool operator()(const T& val) const{
       if (val >= low && val <= high){
           return true;
       }
       else{return false;}
   }
};
template<typename Container, typename Predicate>
int countMatching(const Container& c, Predicate pred){
   int count=0;
   for (const auto& x :c){
       if (pred(x)){count++;}
   }
   return count;
}
int main(){
   vector<int> nums = {5, 12, 25, 45, 60, 100};
   Between<int> inRange{10, 50};
   cout<<countMatching(nums,inRange)<<'\n';
}*/
template<typename T, size_t N>
struct StaticBuffer {
    T data[N]; // Raw array allocated on the stack (zero heap allocations)

    size_t size() const { return N; }

    // Subscript access
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }

    // Pointer iterators so range-for loops work
    T* begin() { return data; }
    T* end() { return data + N; }
    const T* begin() const { return data; }
    const T* end() const { return data + N; }
};
int main(){
   StaticBuffer<int, 4> buf;
   buf[0] = 10;
   buf[1] = 20;
   buf[2] = 30;
   buf[3] = 40;
   cout << "Buffer contents: ";
   for (const auto& val : buf) {
       cout << val << " ";
   }
   cout << "\nBuffer size: " << buf.size() << '\n';
}
