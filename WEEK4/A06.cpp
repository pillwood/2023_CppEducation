#include <iostream>
#include <string>

using namespace std;

int FindWord(string str_input, string str_to_find) {
    int count_word = 0;
    int n = 0;
    while ((n = str_input.find(str_to_find, n)) != string::npos) {
        count_word++;
        n += str_to_find.length();
    }
    return count_word;
}

int main() {
    string str_input;
    string str_to_find;

    cout << "문자열 입력 >> ";
    getline(cin, str_input); 
    cout << "검색하고자 하는 문자 입력 >> ";
    getline(cin, str_to_find);

    int count = FindWord(str_input, str_to_find);

    cout << "문자 " << str_to_find << "는 " << count << "개 있습니다." << endl;

    return 0;
}