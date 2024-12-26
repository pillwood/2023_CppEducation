#include <iostream>

class Coffee{

private:
    int Cafe;
    int H2O;
    int Danger;

public:
    Coffee(int Cafe, int H2O, int Danger);
    void drinkEspresso();
    void drinkAmericano();
    void drinkSugarCoffee();
    void show();
    void fill();
};

Coffee::Coffee(int Cafe, int H2O, int Danger)
    :Cafe(Cafe), H2O(H2O), Danger(Danger) {}

void Coffee::drinkEspresso() {
    Cafe -= 1;
    H2O -= 1;
}

void Coffee::drinkAmericano() {
    Cafe -= 1;
    H2O -= 2;
}

void Coffee::drinkSugarCoffee() {
    Cafe -= 1;
    H2O -= 2;
    Danger -= 1;
}

void Coffee::show() {
    std::cout << "커피 머신 상태, " << "커피: " << Cafe << ", 물: " << H2O << ", 설탕: " << Danger << std::endl;
}

void Coffee::fill() {
    Cafe = 10;
    H2O = 10;
    Danger = 10;
}

int main() {

    Coffee java(10, 10, 10); // 커피량: 10, 물량: 10, 설탕: 10으로 초기화
    int flag=1;
    int order;
    while(flag==1){
        std::cout << "커피 종류 선택 : Espresso = 1, Americano = 2, SugarCoffee = 3, Exit = 4, Fill = 5 >> " ;
        std::cin >> order;
        switch (order){
            case 1:
                java.drinkEspresso(); // 커피 1, 물 1 소비
                java.show(); // 현재 커피 머신의 상태 출력
                break;
            case 2:
                java.drinkAmericano(); // 커피 1, 물 2 소비
                java.show(); // 현재 커피 머신의 상태 출력
                break;
            case 3:
                java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
                java.show(); // 현재 커피 머신의 상태 출력
                break;
            case 4:
                std::cout << "커피 머신을 종료합니다";
                flag=0;
                break;
            case 5:
                java.fill(); // 커피 10, 물 10, 설탕 10으로 채우기
                java.show(); // 현재 커피 머신의 상태 출력
                break;
        }
    }
}
