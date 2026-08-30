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
