#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
};

void displayMenu() {
    cout << "\n----- Bank Account Management -----\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. View Account Details\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    string name;
    int accountNumber;
    bool accountCreated = false;
    BankAccount* myAccount = nullptr;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (accountCreated) {
                cout << "Account already created.\n";
            } else {
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter account number: ";
                cin >> accountNumber;

                myAccount = new BankAccount(name, accountNumber);
                accountCreated = true;
                cout << "Account created successfully!\n";
            }
        }
        else if (choice == 2) {
            if (accountCreated) {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myAccount->deposit(amount);
            } else {
                cout << "No account found! Please create an account first.\n";
            }
        }
        else if (choice == 3) {
            if (accountCreated) {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myAccount->withdraw(amount);
            } else {
                cout << "No account found! Please create an account first.\n";
            }
        }
        else if (choice == 4) {
            if (accountCreated) {
                cout << "Your current balance is: $" << myAccount->getBalance() << endl;
            } else {
                cout << "No account found! Please create an account first.\n";
            }
        }
        else if (choice == 5) {
            if (accountCreated) {
                myAccount->displayAccountDetails();
            } else {
                cout << "No account found! Please create an account first.\n";
            }
        }
        else if (choice == 6) {
            cout << "Exiting program. Thank you!\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    if (myAccount != nullptr) {
        delete myAccount;
    }

    return 0;
}
