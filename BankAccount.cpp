#include "BankAccount.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


// Default constructor
BankAccount::BankAccount()
{
    accountNumber = 0;
    customerName = "";
    accountType = "";
    balance = 0.0;
}


// Parameterized constructor
BankAccount::BankAccount(
    long long accNo,
    string name,
    string type,
    double initialBalance)
{
    accountNumber = accNo;
    customerName = name;
    accountType = type;
    balance = initialBalance;
}


// Getters
long long BankAccount::getAccountNumber() const
{
    return accountNumber;
}

string BankAccount::getCustomerName() const
{
    return customerName;
}

string BankAccount::getAccountType() const
{
    return accountType;
}

double BankAccount::getBalance() const
{
    return balance;
}


// Deposit
bool BankAccount::deposit(double amount)
{
    if (amount <= 0)
        return false;

    balance += amount;

    return true;
}


// Withdrawal
bool BankAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
        return false;

    balance -= amount;

    return true;
}


// Display account details
void BankAccount::displayDetails() const
{
    cout << "\n-----------------------------------\n";
    cout << "        ACCOUNT DETAILS\n";
    cout << "-----------------------------------\n";

    cout << "Account Number : "
         << accountNumber << endl;

    cout << "Customer Name  : "
         << customerName << endl;

    cout << "Account Type   : "
         << accountType << endl;

    cout << fixed << setprecision(2);

    cout << "Balance        : Rs. "
         << balance << endl;

    cout << "-----------------------------------\n";
}


// Convert account information into file format
string BankAccount::toFileString() const
{
    stringstream ss;

    ss << accountNumber << "|"
       << customerName << "|"
       << accountType << "|"
       << fixed << setprecision(2)
       << balance;

    return ss.str();
}
