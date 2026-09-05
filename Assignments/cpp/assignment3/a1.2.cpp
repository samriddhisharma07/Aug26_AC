#include <iostream>
#include <vector>
#include <map>
using namespace std;

using Header     = pair<string, string>;
using HeaderList = vector<Header>;
using Port       = unsigned int;
using IPAddress  = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
    cout << "Headers :" << endl;

    for (const Header& h : headers) {
        cout << h.first << " : " << h.second << endl;
    }
}

int main() {
    Port serverPort = 8080;
    RequestId requestId = 123456789;

    cout << "Server Port : " << serverPort << endl;
    cout << "Request ID  : " << requestId << endl;
    HeaderList headers = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    printHeaders(headers);

    return 0;
}