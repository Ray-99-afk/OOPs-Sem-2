#include <iostream>   
#include <fstream>    
#include <string>     
#include <iomanip>    
using namespace std;  
class BankAccount {
private:
    int accountNumber;      
    string holderName;      
    double balance;         
public:
    BankAccount() {
        accountNumber = 0;      
        holderName = "";        
        balance = 0.0;          
    }
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;  
        holderName = name;      
        balance = bal;          
    }
    int getAccountNumber() {
        return accountNumber;   
    }
    string getHolderName() {
        return holderName;      
    }
    double getBalance() {
        return balance;         
    }
    void setAccountNumber(int accNo) {
        accountNumber = accNo;  
    }
    void setHolderName(string name) {
        holderName = name;      
    }
    void setBalance(double bal) {
        balance = bal;          
    }
    void deposit(double amount) {
        if (amount > 0) {                       
            balance = balance + amount;         
            cout << "Deposited successfully! ";
            cout << "New Balance: Rs." << fixed << setprecision(2) << balance << endl;
        }
        else {
            cout << "Invalid amount. Deposit must be greater than 0." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {  
            balance = balance - amount;         
            cout << "Withdrawn successfully! ";
            cout << "Remaining Balance: Rs." << fixed << setprecision(2) << balance << endl;
        }
        else if (amount > balance) {            
            cout << "Insufficient funds! Your balance is only Rs."
                 << fixed << setprecision(2) << balance << endl;
        }
        else {                                  
            cout << "Invalid amount. Please enter a positive number." << endl;
        }
    }
    void displayAccount() {
        cout << "------------------------------------" << endl;
        cout << " Account No : " << accountNumber << endl;
        cout << " Holder Name: " << holderName << endl;
        cout << " Balance    : Rs." << fixed << setprecision(2) << balance << endl;
        cout << "------------------------------------" << endl;
    }
};
int getNextAccountNumber(string filename) {
    ifstream file(filename);        
    int maxAcc = 1000;              
    string line;                    
    if (file.is_open()) {           
        while (getline(file, line)) {   
            if (line.substr(0, 4) == "ACC:") {
                int accNo = stoi(line.substr(4));
                if (accNo > maxAcc) {
                    maxAcc = accNo;
                }
            }
        }
        file.close();               
    }
    return maxAcc + 1;              
}
void saveAccount(string filename, BankAccount acc) {
    ofstream file(filename, ios::app);  
    if (!file) {    
        cout << "Error: Could not open file for writing." << endl;
        return;     
    }
    file << "ACC:" << acc.getAccountNumber() << endl;   
    file << "NAME:" << acc.getHolderName() << endl;     
    file << "BAL:" << acc.getBalance() << endl;         
    file << endl;                                        
    file.close();   
}
bool loadAccount(string filename, int accNo, BankAccount &acc) {
    ifstream file(filename);        
    string line;                    
    bool found = false;             
    if (!file) {    
        return false;               
    }
    while (getline(file, line)) {   
        if (line == "ACC:" + to_string(accNo)) {
            acc.setAccountNumber(accNo);    
            if (getline(file, line)) {
                acc.setHolderName(line.substr(5));
            }
            if (getline(file, line)) {
                acc.setBalance(stod(line.substr(4)));
            }
            found = true;  
            break;          
        }
    }
    file.close();           
    return found;           
}
void updateFile(string filename, BankAccount acc) {
    ifstream inFile(filename);          
    string lines[500];                  
    int lineCount = 0;                  
    string line;
    while (getline(inFile, line)) {
        lines[lineCount] = line;        
        lineCount++;                    
    }
    inFile.close();                     
    for (int i = 0; i < lineCount; i++) {
        if (lines[i] == "ACC:" + to_string(acc.getAccountNumber())) {
            if (i + 2 < lineCount) {    
                lines[i + 2] = "BAL:" + to_string(acc.getBalance());
            }
            break;  
        }
    }
    ofstream outFile(filename);         
    for (int i = 0; i < lineCount; i++) {
        outFile << lines[i] << endl;    
    }
    outFile.close();                    
}
void listAllAccounts(string filename) {
    ifstream file(filename);        
    string line;                    
    if (!file) {    
        cout << "\nNo accounts found. Create one first!" << endl;
        return;
    }
    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "\nNo accounts recorded yet." << endl;
        file.close();
        return;
    }
    cout << "\n=====================================" << endl;
    cout << "       ALL BANK ACCOUNTS" << endl;
    cout << "=====================================" << endl;
    int accNo;
    string name;
    double bal;
    while (getline(file, line)) {           
        if (line.substr(0, 4) == "ACC:") {  
            accNo = stoi(line.substr(4));   
            if (getline(file, line)) {      
                name = line.substr(5);      
            }
            if (getline(file, line)) {      
                bal = stod(line.substr(4)); 
            }
            cout << "------------------------------------" << endl;
            cout << " Account No : " << accNo << endl;
            cout << " Holder     : " << name << endl;
            cout << " Balance    : Rs." << fixed << setprecision(2) << bal << endl;
        }
    }
    cout << "=====================================" << endl;
    file.close();       
}
void searchAccount(string filename) {
    ifstream file(filename);        
    if (!file) {                    
        cout << "No accounts exist yet." << endl;
        return;
    }
    string target;
    cout << "Enter name to search: ";
    getline(cin >> ws, target);     
    string line;
    bool found = false;             
    cout << "\n--- Search Results ---" << endl;
    while (getline(file, line)) {
        if (line.substr(0, 5) == "NAME:") {     
            string name = line.substr(5);       
            if (name.find(target) != string::npos) {
                cout << " -> Match: " << name << endl;
                found = true;                   
            }
        }
    }
    if (!found) {                   
        cout << " No matching accounts found." << endl;
    }
    file.close();                   
}
int main() {
    string filename = "accounts.txt";   
    int choice;                         
    cout << "=====================================" << endl;
    cout << "   WELCOME TO BANK MANAGEMENT SYSTEM" << endl;
    cout << "=====================================" << endl;
    while (true) {
        cout << "\n----------- MAIN MENU -----------" << endl;
        cout << " 1. Create New Account" << endl;
        cout << " 2. Deposit Money" << endl;
        cout << " 3. Withdraw Money" << endl;
        cout << " 4. Check Balance" << endl;
        cout << " 5. List All Accounts" << endl;
        cout << " 6. Search Account by Name" << endl;
        cout << " 7. Exit" << endl;
        cout << "---------------------------------" << endl;
        cout << " Enter your choice: ";
        if (!(cin >> choice)) {
            cout << " Please enter a valid number!" << endl;
            cin.clear();                
            cin.ignore(1000, '\n');     
            continue;                   
        }
        if (choice == 1) {
            string name;
            double initialDeposit;
            cout << "\n--- Create New Account ---" << endl;
            cout << " Enter account holder name: ";
            getline(cin >> ws, name);       
            cout << " Enter initial deposit amount: Rs.";
            cin >> initialDeposit;          
            if (initialDeposit < 0) {
                cout << " Initial deposit cannot be negative!" << endl;
                continue;   
            }
            int newAccNo = getNextAccountNumber(filename);
            BankAccount newAcc(newAccNo, name, initialDeposit);
            saveAccount(filename, newAcc);
            cout << "\n Account created successfully!" << endl;
            newAcc.displayAccount();        
        }
        else if (choice == 2) {
            int accNo;
            double amount;
            cout << "\n--- Deposit Money ---" << endl;
            cout << " Enter account number: ";
            cin >> accNo;           
            BankAccount acc;        
            if (loadAccount(filename, accNo, acc)) {
                cout << " Enter deposit amount: Rs.";
                cin >> amount;      
                acc.deposit(amount);        
                updateFile(filename, acc);  
            }
            else {
                cout << " Account not found!" << endl;
            }
        }
        else if (choice == 3) {
            int accNo;
            double amount;
            cout << "\n--- Withdraw Money ---" << endl;
            cout << " Enter account number: ";
            cin >> accNo;           
            BankAccount acc;        
            if (loadAccount(filename, accNo, acc)) {
                cout << " Enter withdrawal amount: Rs.";
                cin >> amount;      
                acc.withdraw(amount);       
                updateFile(filename, acc);  
            }
            else {
                cout << " Account not found!" << endl;
            }
        }
        else if (choice == 4) {
            int accNo;
            cout << "\n--- Check Balance ---" << endl;
            cout << " Enter account number: ";
            cin >> accNo;           
            BankAccount acc;        
            if (loadAccount(filename, accNo, acc)) {
                acc.displayAccount();   
            }
            else {
                cout << " Account not found!" << endl;
            }
        }
        else if (choice == 5) {
            listAllAccounts(filename);  
        }
        else if (choice == 6) {
            searchAccount(filename);    
        }
        else if (choice == 7) {
            cout << "\n Thank you for using Bank Management System!" << endl;
            cout << " Goodbye!" << endl;
            break;      
        }
        else {
            cout << " Invalid choice! Please select 1-7." << endl;
        }
    }   
    return 0;   
}
