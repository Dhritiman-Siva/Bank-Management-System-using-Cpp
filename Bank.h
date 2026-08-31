#ifndef BANK_H
#define BANK_H

#include "BankAccount.h"
#include <vector>
#include <string>

using namespace std;

class Bank
{
private:
    vector<BankAccount> accounts;
    string filename;

public:
    void createAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void displayAccount();
    void displayAllAccounts();
    void loadAccounts();
    void saveAccounts();
};

#endif
