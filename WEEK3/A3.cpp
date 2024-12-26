#include <iostream>

using namespace std;

int main() {
    double num;

    cout << "실수를 입력하세요: ";
    cin >> num;

    int num_int=num;
    double num_und=num-num_int;

    cout << "정수 part: " << num_int << endl;
    cout << "소수 part: " << num_und << endl;

    return 0;
}