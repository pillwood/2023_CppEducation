#include <iostream>
#include "account.h"
using namespace std;
Account::Account(const std::string& owner, int balance)
    : owner(owner), balance(balance) {}

const std::string& Account::getOwner() const {
    return owner;
}

int Account::check() const {
    return balance;
}

void Account::deposit(int amount) {
    if (amount > 0) {
        balance += amount;
    }
}

int Account::withdraw(int amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return amount;
    } else {
        return 0; // 출금 실패
    }
}
int main() {
    Account a("C++", 0);
    MENU choice;
    int menu, money;

    do {
        cout << "--------------------------------------------" << endl;
        cout << "menu : 1. 입금, 2. 출금  3. 조회  4. 종료 >> ";
        cin >> menu;
        choice = static_cast<MENU>(menu);

        if(choice == MENU::QUIT) 
            break;

        switch (choice) {
        case MENU::DEPOSIT:
            cout << "입금액 >> ";
            cin >> money;
            a.deposit(money);
            cout << a.getOwner() << "의 입금 액은 " << money << endl;
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
            break;
        case MENU::WITHDRAW:
            cout << "출금액 >> ";
            cin >> money;
            cout << a.getOwner() << "의 출금 액은 " << a.withdraw(money) << endl;
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
            break;
        case MENU::CHECK:
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
        }
    } while (true);
    return 0;
}