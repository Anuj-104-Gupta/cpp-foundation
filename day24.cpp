#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main(){
    vector tokens = {"apple","banana","apple","cherry","banana","date","apple"};
    map<string,int> wordMap;
    for(const auto& i:tokens){wordMap[i]++;}
    for (const auto& [word, count] : wordMap) {cout << word << ": " << count << '\n';}
    unordered_map<string,int> wordMap2;
    for (const auto& i:tokens){wordMap2[i]++;}
    for (const auto& [word, count] : wordMap2) {cout << word << ": " << count << '\n';}
}
