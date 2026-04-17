#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes (telling the compiler these exist)
void appendRecord(string filename);
void findRecord(string filename);
void Listall(string filename);

int main() {
    string filename = "Record.txt";
    int choice;

    while (true) {
        cout << "\n--- Record Manager ---";
        // Updated the menu to include option 4
        cout << "\n1. Append | 2. Search | 3. Exit | 4. List All \nChoice: ";
        
        if (!(cin >> choice)) { // Basic check for non-integer input
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            appendRecord(filename);
        } 
        else if (choice == 2) {
            findRecord(filename);
        } 
        else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } 
        else if (choice == 4) {
            Listall(filename);
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

void appendRecord(string filename) {
    ofstream file(filename, ios::app); 
    if (!file) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    string record;
    cout << "Enter new Record: ";
    getline(cin >> ws, record); 
    
    file << record << endl;
    file.close();
    cout << "Record added successfully.\n";
}

void findRecord(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File doesn't exist yet. Add a record first!\n";
        return;
    }

    string target, line;
    bool found = false;

    cout << "Enter text to search for: ";
    getline(cin >> ws, target);

    while (getline(file, line)) {
        if (line.find(target) != string::npos) {
            cout << " -> Match Found: " << line << endl;
            found = true;
        }
    }

    if (!found) cout << "No matches found.\n";
    file.close();
}

void Listall(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File could not be opened or does not exist.\n";
        return;
    }

    string line;
    cout << "\n -------- All Records ------\n";
    
    // Check if the file is empty
    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "(The file is currently empty)\n";
    } else {
        while (getline(file, line)) {
            cout << " -> " << line << endl;
        }
    }
    
    cout << " ---------------------------\n";
    file.close();
}