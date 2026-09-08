#include<iostream>
#include<string>
#include<regex>
using namespace std;
/* 1
void analyzePrefix(string_view sv){
    if (sv.starts_with("SYS-")){
        sv.remove_prefix(4);
        cout<<sv<<" String length is:"<<sv.length()<<'\n';
    }
    else{cout<<"The prefix is missing\n";}
}
int main(){
    analyzePrefix("SYS-NETWORK_UP");
    analyzePrefix("Hrll");
}*/
void parseLogEntry(const string& entry){
    regex pattern(R"(ID:([A-Z]{3}-(\d{4})))");
    smatch matches;
    if (regex_search(entry,matches,pattern)){
        cout << "Full Match: "   << matches[0] << '\n';
        cout << "Department: "   << matches[1] << '\n';
        cout << "Numeric Code: " << matches[2] << '\n';
    }
    else{cout<<"Error Given Input Was Wrong ,Retry\n";}
}
int main(){
    parseLogEntry("SERVER_LOG: ID:SEC-2048 status=ACTIVE");
    parseLogEntry("SERVER_LOG: ID:sec-99 status=FAIL");
    return 0;
}
