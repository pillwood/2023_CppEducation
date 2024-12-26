#include "account.h"
#pragma once
Account::Account(const std::string& owner, int balance)
    : owner(owner), balance(balance) {}

const std::string& Account::getOwner() const {
    return owner;
}

int Account::check() const {
    return balance;
}

void Account::deposit(int amount) {
    balance += amount;
}

int Account::withdraw(int amount) {
    balance -= amount;
    return amount;
}