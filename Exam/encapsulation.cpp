#include <iostream>
#include <string>

class BankAccount {
private:
    // The data is hidden. Outside code cannot directly read or change 'balance'.
    double balance; 
    std::string accountHolder;

public:
    // Constructor to initialize the account
    BankAccount(std::string name, double initial_balance) {
        accountHolder = name;
        if (initial_balance >= 0) {
            balance = initial_balance;
        } else {
            balance = 0;
            std::cout << "Initial balance cannot be negative. Set to 0.\n";
        }
    }

    // Public method to ADD to the balance (Setter-like behavior)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << "\n";
        } else {
            std::cout << "Cannot deposit a negative amount!\n";
        }
    }

    // Public method to SUBTRACT from the balance
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!\n";
        }
    }

    // Public method to READ the balance (Getter)
    double getBalance() {
        return balance;
    }
};

int main() {
    // Create an object of BankAccount
    BankAccount myAccount("Alice", 100.0);

    // Interacting with the account through public methods
    myAccount.deposit(50.0);
    myAccount.withdraw(30.0);
    
    // Safely reading the balance
    std::cout << "Current Balance: $" << myAccount.getBalance() << "\n";

    // --- ENCAPSULATION IN ACTION ---
    // The following line would cause a COMPILER ERROR because 'balance' is private:
    // myAccount.balance = 1000000.0; 
    
    // The following line would also cause an ERROR:
    // std::cout << myAccount.balance; 

    return 0;
}