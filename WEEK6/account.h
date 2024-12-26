#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <String>
using namespace std;

enum class MENU { DEPOSIT = 1, WITHDRAW=2, CHECK=3, QUIT=4};

class Account {
private:
    string owner;
    int balance;

public:
    Account(const std::string& owner, int balance);

    const std::string& getOwner() const;
    int check() const;
    void deposit(int amount);
    int withdraw(int amount);
};

#endif