#include "Bank.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

Bank::Bank(string file)
{
    filename = file;

    srand(static_cast<unsigned int>(time(nullptr)));

    loadAccounts();
}

int Bank::findAccountIndex(long long accountNumber)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getAccountNumber() == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

long long Bank::generateAccountNumber()
{
    long long accountNumber;

    do
    {
        accountNumber =
            100000 + rand() % 900000;
    }
    while (findAccountIndex(accountNumber) != -1);

    return accountNumber;
}
