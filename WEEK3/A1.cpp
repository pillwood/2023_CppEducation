#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double qz, me, fe;
    double total, average;

    cout << "퀴즈, 중간고사, 기말고사 성적을 입력하세요: ";
    cin >> qz >> me >> fe;
    
    total = qz + me + fe;
    average = total / 3;

    cout << "총합 : " << total << endl;
    cout << fixed;
    cout.precision(2);
    cout << "평균 : " << average << endl;

}