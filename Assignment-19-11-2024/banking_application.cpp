#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Class to handle personal information of account holders
class PersonalInfo {
public:
    // Setters for first name and last name
    void setFName(const string& fname) { this->fname = fname; }
    void setLName(const string& lname) { this->lname = lname; }

    // Get full name in "First Last" format
    string getFullName() const { return fname + " " + lname; }

    // Print personal information
    void print() const { cout << fname << " " << lname; }

private:
    string fname; // First name
    string lname; // Last name
};

// Base class to represent a general bank account
class Account {
public:
    // Get and set account amount
    double getAmount() const { return amount; }
    void setAmount(double amount) { this->amount = amount; }

    // Set account owner and account number
    void setAccountOwner(const PersonalInfo& owner) { account_owner = owner; }
    void setAccountNumber(const string& accNum) { account_number = accNum; }

    // Getter for account number
    string getAccountNumber() const { return account_number; }

    // Getter for account owner full name
    string getAccountOwnerName() const { return account_owner.getFullName(); }

    // Print account details
    void print() const {
        cout << account_owner.getFullName() << " "
             << account_number << " "
             << fixed << setprecision(2) << amount;
    }

protected:
    string account_number;    // Account number
    PersonalInfo account_owner; // Account owner information
    double amount;            // Current account balance
};

// Derived class for savings accounts with profit calculation
class SavingsAccount : public Account {
public:
    // Set all information for a savings account
    void setInfo(const string& fname, const string& lname, const string& accNum, double amount, float profitRate) {
        account_owner.setFName(fname);
        account_owner.setLName(lname);
        account_number = accNum;
        this->amount = amount;
        this->profit_rate = profitRate;
    }

    // Apply profit to the account balance based on the profit rate
    void applyProfit() {
        amount += amount * profit_rate;
    }

    // Getter for profit rate
    float getProfitRate() const { return profit_rate; }

    // Print account details including profit rate
    void print() const {
        account_owner.print();
        cout << " " << account_number << " "
             << fixed << setprecision(2) << amount << " "
             << profit_rate << endl;
    }

private:
    float profit_rate; // Profit rate as a fraction (e.g., 0.03 for 3%)
};

// Bank class to manage multiple savings accounts
class Bank {
public:
    Bank() : num_of_accounts(0) {} // Initialize with no accounts

    // Load account information from a file
    void getAccountsInfoFromFile(const string& filePath) {
        ifstream file(filePath);

        if (!file.is_open()) {
            cerr << "Error opening file: " << filePath << endl;
            return;
        }

        string fname, lname, accNum;
        double amount;
        float profitRate;

        // Read account data line by line
        while (file >> fname >> lname >> accNum >> amount >> profitRate) {
            accounts[num_of_accounts].setInfo(fname, lname, accNum, amount, profitRate);
            num_of_accounts++;
        }

        file.close();
    }

    // Apply profit to all accounts
    void applyYearEndProfit() {
        for (int i = 0; i < num_of_accounts; i++) {
            accounts[i].applyProfit();
        }
    }

    // Print all accounts to the console
    void printAccounts() const {
        for (int i = 0; i < num_of_accounts; i++) {
            accounts[i].print();
        }
    }

    // Write updated account information to a file
    void writeAccountsToFile(const string& filePath) const {
        ofstream file(filePath);

        if (!file.is_open()) {
            cerr << "Error writing to file: " << filePath << endl;
            return;
        }

        for (int i = 0; i < num_of_accounts; i++) {
            const SavingsAccount& acc = accounts[i];
            file << acc.getAccountOwnerName() << " "      // Use getter for account owner
                 << acc.getAccountNumber() << " "        // Use getter for account number
                 << fixed << setprecision(2) << acc.getAmount() << " "
                 << acc.getProfitRate() << endl;         // Use getter for profit rate
        }

        file.close();
    }

private:
    int num_of_accounts;         // Number of accounts in the bank
    SavingsAccount accounts[100]; // Array to store up to 100 savings accounts
};

int main() {
    Bank bank; // Create a bank object

    // File paths for input and output
    string inputFile = "accounts.txt";
    string outputFile = "updated_accounts.txt";

    // Step 1: Load account information from file
    bank.getAccountsInfoFromFile(inputFile);

    // Step 2: Apply year-end profit to all accounts
    bank.applyYearEndProfit();

    // Step 3: Print updated accounts to the console
    cout << "Updated account information:" << endl;
    bank.printAccounts();

    // Step 4: Write updated accounts to an output file
    bank.writeAccountsToFile(outputFile);

    return 0; // Program executed successfully
}
