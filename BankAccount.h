#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;

class BankAccount
{
private:
    long long accountNumber;
    string customerName;
    string accountType;
    double balance;

public:
    BankAccount();

    BankAccount(
        long long accNo,
        string name,
        string type,
        double initialBalance
    );

    long long getAccountNumber() const;
    string getCustomerName() const;
    string getAccountType() const;
    double getBalance() const;
};

#endif
