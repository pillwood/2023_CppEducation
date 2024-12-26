#include <iostream>
#include <string>

using namespace std;

string remove_number(string string_includes_numbers){
    string only_word;
    for(char letter : string_includes_numbers){
        int letter_int=int(letter);
        if(letter_int > 58 || letter_int < 47){
            only_word.push_back(letter);
        }
    }
    return only_word;
}

int main() {
    while (true) {
        string input_string;
        
        cout << "string input >> ";
        getline(cin, input_string);

        if (input_string == "exit") {
            cout << "finish" << endl;
            break;
        }

        string answer;
        answer=remove_number(input_string);
        cout << "숫자가 제거 된 문자열(종료 : exit) >> " << answer << endl;
    }
    return 0;
}