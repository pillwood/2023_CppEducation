#include <iostream>
#include <string>

using namespace std;

string reverse_string(string str) {
    string Rstr;
    while(!str.empty()){
        Rstr.push_back(str.back());
        str.pop_back();
    }
    return Rstr;
}

int main() {
    string input_string;
    string reversed_string;

    cout << "String input >> ";
    getline(cin, input_string);

    reversed_string = reverse_string(input_string);
    cout << "reverse string >> " << reversed_string << endl;

    return 0;
}