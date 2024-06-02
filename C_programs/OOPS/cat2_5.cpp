#include <iostream>
#include <vector>
using namespace std;
class Account {
private:
    double balance;
    int accountNumber;
    int pinCode;

    friend class BankAgent;
    friend void authenticateCustomer(const Account& account, int pinCode);

public:
    Account(int accNumber, int pin) : accountNumber(accNumber), pinCode(pin), balance(0.0) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }
};

class Customer {
private:
    string name;
    string address;
    vector<Account> accounts;

public:
    Customer(const string& customerName, const string& customerAddress) : name(customerName), address(customerAddress) {}

    void addAccount(const Account& account) {
        accounts.push_back(account);
    }

    void deposit(Account& account, double amount) {
        account.deposit(amount);
    }

    void withdraw(Account& account, double amount) {
        account.withdraw(amount);
    }
};

void authenticateCustomer(const Account& account, int pinCode) {
    if (pinCode == account.pinCode) {
        cout << "Authentication successful." << endl;
    } else {
        cout << "Authentication failed." << endl;
    }
}

class BankAgent {
public:
    static void checkBalance(const Account& account) {
        cout << "Account balance: " << account.getBalance() << endl;
    }
};

int main() {
    string customerName;
    string customerAddress;
    int accountNumber;
    int pinCode;

    cout << "Welcome to the Banking Application!" << std::endl;

    cout << "Enter your name: ";
    getline(cin, customerName);

    cout << "Enter your address: ";
    getline(cin, customerAddress);

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Set a PIN code: ";
    cin >> pinCode;

    // Create an account and a customer
    Account account(accountNumber, pinCode);
    Customer customer(customerName, customerAddress);

    // Add the account to the customer's list of accounts
    customer.addAccount(account);

    // Display the available options
    int choice;
    double amount;

    do {
        cout << "\nSelect an option:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                customer.deposit(account, amount);
                break;
            case 2:
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                customer.withdraw(account, amount);
                break;
            case 3:
                BankAgent::checkBalance(account);
                break;
            case 4:
                cout << "Thank you for using the Banking Application!" << std::endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);

  return 0;
}