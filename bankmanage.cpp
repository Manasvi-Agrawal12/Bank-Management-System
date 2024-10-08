// C++ program to implement
// Bank Management System

#include <iostream>
#include <string>
using namespace std;

class Bank {
    string name, address;
    char acc_type;
    float balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

// Function to open the account
void Bank::open_account()
{
    cout << "Enter your full name: ";
    getline(cin, name);  // Get full name
    cout << "Enter your address: ";
    getline(cin, address);  // Get address
    cout << "What type of account do you want to open (Saving(S) or Current(C)): ";
    cin >> acc_type;  // Get account type
    acc_type = toupper(acc_type);  // Convert to uppercase for consistency
    cout << "Enter how much money you want to deposit: ";
    cin >> balance;  // Get initial deposit
    cout << "Account Created Successfully\n";
}

// Function to deposit money into the account
void Bank::deposit_money()
{
    float amount;
    cout << "Enter how much money you want to deposit: ";
    cin >> amount;  // Get deposit amount
    balance += amount;  // Update balance
    cout << "\nAvailable Balance: " << balance << endl;
}

// Function to display the account details
void Bank::display_account()
{
    cout << "Name: " << name << endl
         << "Address: " << address << endl
         << "Type: " << acc_type << endl
         << "Balance: " << balance << endl
         << endl;
}

// Function to withdraw money from the account
void Bank::withdraw_money()
{
    float amount;
    cout << "Enter how much money you want to withdraw: ";
    cin >> amount;  // Get withdrawal amount
    if (amount <= balance) {  // Check if sufficient balance
        balance -= amount;  // Update balance
        cout << "\nAvailable balance: " << balance << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

// Driver code
int main()
{
    int choice;

    // Creating Customer Object of Bank Class
    Bank customer;

    customer.open_account();
    cout << "\n------------------------"
         << "-------------------------\n";

    do {
        cout << "\nMenu:\n";
        cout << "1) Deposit money\n";
        cout << "2) Withdraw money\n";
        cout << "3) Display Account\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                customer.deposit_money();
                break;
            case 2:
                customer.withdraw_money();
                break;
            case 3:
                customer.display_account();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n------------------------"
             << "-------------------------\n";
    } while (choice != 4);

    return 0;
}
