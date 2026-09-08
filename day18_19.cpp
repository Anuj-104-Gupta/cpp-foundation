#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<concepts>
using namespace std;
/*1
template <typename Container>
void printContainerInfo(const Container& c){
    using ValueType=typename Container::value_type;
    cout<<sizeof(ValueType)<<'\n';
    if (!(c.empty())){
        cout<<c.front()<<'\n';
    }
}

int main(){
   vector<int> nums={10,20,30};
   string text ="C++20";
   printContainerInfo(nums);
   printContainerInfo(text);
}
2
*/template<typename T>
concept NumericBuffer=requires(T buf){
   typename T::value_type;
   requires integral<typename T::value_type>||floating_point<typename T::value_type>;
   {buf.size()}->convertible_to<size_t>;
   { buf[0] } -> same_as<typename T::value_type&>;
   };
/*int main(){
   static_assert(NumericBuffer<std::vector<int>>);
   static_assert(NumericBuffer<std::vector<double>>);
   static_assert(!NumericBuffer<std::vector<std::string>>);
   static_assert(!NumericBuffer<int>);
}*/

template<NumericBuffer T>
void serialize(const T& buffer){
   cout<<"[Buffer]:";
   for (const auto& i:buffer){
       cout<<i<<',';
   }
   cout<<'\n';
}
template<integral T>
void serialize(T value){
     cout<<"[Scalar Hex]:";
     cout<< showbase << hex << value << dec <<'\n';
}
int main(){
   vector<int> nums={10,20,30};
   int scalar=255;
   serialize(nums);
   serialize(scalar);
}




























