#include <iostream>

using namespace std;

int main() {

    enum class RPS { 
        Rock = 1, 
        Paper = 2, 
        Scissors = 3 
    };

    int cho;
    
    cout << "정수 입력(1, 2, 3이 아닌 수는 프로그램 종료) : ";
    cin >> cho;
    RPS echo = static_cast<RPS>(cho);


    switch (echo) {
        case RPS::Rock:
            cout << "Rock" << endl;
            break;
        case RPS::Paper:
            cout << "Paper" << endl;
            break;
        case RPS::Scissors:
            cout << "Scissors" << endl;
            break;
        default:
            cout << "1,2,3 중 하나만 입력하세요" << endl;
            break;
    }

    return 0;
}