#include "BankAccount.h"
#include <iostream>
#include <array>

int main() {
    const int num_accounts = 10;
    std::array<BankAccount, num_accounts> accounts;

    // Initialize starting balances
    for (int i = 0; i < num_accounts; i++) {
        accounts[i].set_starting_balance(100.0f);  // Default starting balance for demonstration
    }

    // Deposit in every alternate account (1, 3, 5, 7, 9)
    for (int i = 0; i < num_accounts; i += 2) {
        accounts[i].deposit(50.0f);  // Depositing 50 for demonstration
    }

    // Display welcome screen and account details
    BankAccount::display_welcome_screen();
    for (const auto& account : accounts) {
        std::cout << "Account ID: " << account.get_account_id()
                  << " | Balance: $" << std::fixed << std::setprecision(2) << account.get_balance() << '\n';
    }

    // Withdraw from every alternate account (1, 3, 5, 7, 9)
    for (int i = 0; i < num_accounts; i += 2) {
        accounts[i].withdraw(30.0f);  // Withdrawing 30 for demonstration
    }

    // Display welcome screen and updated account details
    BankAccount::display_welcome_screen();
    for (const auto& account : accounts) {
        std::cout << "Account ID: " << account.get_account_id()
                  << " | Balance: $" << std::fixed << std::setprecision(2) << account.get_balance() << '\n';
    }

    // Create and test one more hard-coded account
    BankAccount extra_account;
    extra_account.deposit(200.0f);
    extra_account.withdraw(50.0f);

    // Display balance of extra account
    std::cout << "Extra Account ID: " << extra_account.get_account_id()
              << " | Balance: $" << std::fixed << std::setprecision(2) << extra_account.get_balance() << '\n';

    // Final welcome screen with updated customer count
    BankAccount::display_welcome_screen();

    return 0;
}
