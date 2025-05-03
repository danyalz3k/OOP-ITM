#include <string>
#include <iostream>

class BankAccount {
private:
    std::string account_number;
    float balance;
    static int account_counter;
    static std::string bank_name;

public:
    BankAccount();
    void set_starting_balance(float amount);
    void deposit(float amount);
    void withdraw(float amount);
    float get_balance() const;
    std::string get_account_id() const;
    static void display_welcome_screen();
};

