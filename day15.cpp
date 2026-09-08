#include<iostream>
#include <stdexcept>
#include<algorithm>
using namespace std;
template<typename T>
class Vector{
private:
   T* elem;
   int sz;
public:
   explicit Vector(int s){
       if (s<0){
           throw length_error{"Vector: negative_size"};
       }
       elem = new T[s];
       sz = s;
   }
   Vector(initializer_list<T> lst): elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
        copy(lst.begin(), lst.end(), elem);
    }
   int size() const { return sz; }
   T& operator[](int i) {
        if (i < 0 || i >= sz) throw out_of_range{"Vector::operator[]"};
        return elem[i];
   }
   const T& operator[](int i) const{
       if (i<0 || size()<=i){
           throw out_of_range{"Vector::operator[]"};
       }
       return elem[i];
    }
    T* begin() { return elem; }
    T* end() { return elem + sz; }
    const T* begin() const{return elem;}
    const T* end() const{return elem+sz;}
    ~Vector(){delete[] elem;}
};
int main(){
   Vector<int> v1 = {10, 20, 30, 40};
    cout << "v1 elements: ";
    for (const auto& x : v1) {
        cout << x << " ";
    }
    cout << "\nSize: " << v1.size() << "\n";
    Vector<string> v2 = {"C++", "Templates", "Generic"};
    cout << "v2 elements: ";
    for (const auto& s : v2) {
        cout << s << " ";
    }
    cout << "\n";
    //return 0;
}
