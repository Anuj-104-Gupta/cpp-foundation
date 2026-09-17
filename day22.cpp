#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;
/*1
void parseConfig(const string& configLine){
    istringstream stream(configLine);
    string token;
    while (getline(stream,token,',')){
        istringstream tokenStream(token);
        string key;
        getline(tokenStream,key,'=');
        int val;
        tokenStream>>val;
        if (tokenStream.fail()) {
            cout << "[PARSE ERROR] Invalid value for key: " << key << '\n';
        }
        else {
            cout << "Key: " << key << " -> Value: " << val << '\n';
        }
    }
}
int main(){
    parseConfig("PORT=8080,TIMEOUT=30,SSL=1,DEBUG=invalid");
}
2
struct ServerEndpoint{
    string host;
    int port;
};
ostream& operator<<(ostream& os, const ServerEndpoint& endpoint) {
    os << endpoint.host << ":" << endpoint.port;
    return os;
}

istream& operator>>(istream& is, ServerEndpoint& endpoint) {
    if (!getline(is, endpoint.host, ':')) {
        return is;
    }

    if (!(is >> endpoint.port)) {
        return is;
    }

    if (endpoint.port < 1 || endpoint.port > 65535) {
        is.setstate(ios_base::failbit);
    }

    return is;
}

int main() {
    ServerEndpoint ep1;
    istringstream stream1("127.0.0.1:443");
    if (stream1 >> ep1) {
        cout << "Parsed successfully: " << ep1 << '\n';
    } else {
        cout << "Failed to parse stream1\n";
    }

    ServerEndpoint ep2;
    istringstream stream2("127.0.0.1:99999");
    if (stream2 >> ep2) {
        cout << "Parsed successfully: " << ep2 << '\n';
    } else {
        cout << "Failed to parse stream2 (invalid port correctly rejected)\n";
    }
}
*/

