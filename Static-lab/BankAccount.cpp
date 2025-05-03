#include "BankAccount.h"
#include <iomanip>

int BankAccount::account_counter = 1;
std::string BankAccount::bank_name = "Best Bank";

BankAccount::BankAccount() : balance(0.0f) {
    account_number = "ACC" + std::to_string(account_counter++);
}

void BankAccount::set_starting_balance(float amount) {
    balance = amount;
}

void BankAccount::deposit(float amount) {
    balance += amount;
}

void BankAccount::withdraw(float amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds for withdrawal.\n";
    }
}

float BankAccount::get_balance() const {
    return balance;
}

std::string BankAccount::get_account_id() const {
    return account_number;
}

void BankAccount::display_welcome_screen() {
    std::cout << "Welcome to " << bank_name << ". Serving " << (account_counter - 1) << " customers all over the world.\n";
}
