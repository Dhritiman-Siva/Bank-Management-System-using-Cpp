#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount()
{
    accountNumber = 0;
    customerName = "";
    accountType = "";
    balance = 0.0;
}

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

bool BankAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;

    return true;
}

bool BankAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}

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

    cout << "Balance        : Rs. "
         << balance << endl;

    cout << "-----------------------------------\n";
}
