#include<iostream>
#include"day6.h"
#include<stdexcept>
using namespace MyLib;
using namespace std;
Vector::Vector(int s){
   if (s<0){
       throw length_error("Vector: negative size");
   }
   else{
       elem=new double[s];
       sz=s;}
}
Vector::~Vector(){
   delete[] elem;
}
double& Vector::operator[](int i){
   if (i>=sz ||i<0){
       throw out_of_range("Vector::operator[]: index out of range");
   }
   else{return elem[i];}
}
int Vector::size() const noexcept {
   return sz;
}
