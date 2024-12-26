#include <iostream>
#include <string>
#include <string_view>

using namespace std;


string untilFive(string str) {
    return str.substr(0,5);
}

char* gets(char* strb) {
    cin >> strb;
    return strb;
}

int main() {
    string stra, outstr;
    cout << "Enter a string: ";
    getline(cin, stra);

    outstr = untilFive(stra);
    cout << " -> " << outstr;

    char strb[50];
    cout << "\nEnter a string: ";
    gets(strb);
    outstr = untilFive(strb);
    cout << " -> " << outstr;

    return 0;
}