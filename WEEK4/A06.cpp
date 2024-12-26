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

    cout << "���ڿ� �Է� >> ";
    getline(cin, str_input); 
    cout << "�˻��ϰ��� �ϴ� ���� �Է� >> ";
    getline(cin, str_to_find);

    int count = FindWord(str_input, str_to_find);

    cout << "���� " << str_to_find << "�� " << count << "�� �ֽ��ϴ�." << endl;

    return 0;
}