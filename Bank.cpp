#include "Bank.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

Bank::Bank(string file) {
  filename = file;

  srand(static_cast<unsigned int>(time(nullptr)));

  loadAccounts();
}

int Bank::findAccountIndex(long long accountNumber) {
  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i].getAccountNumber() == accountNumber) {
      return i;
    }
  }

  return -1;
}

long long Bank::generateAccountNumber() {
  long long accountNumber;

  do {
    accountNumber = 100000 + rand() % 900000;
  } while (findAccountIndex(accountNumber) != -1);

  return accountNumber;
}

void Bank::createAccount() {
  string name;
  string accountType;
  double initialBalance;

  cout << "\n========== CREATE ACCOUNT ==========\n";

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter customer name: ";
  getline(cin, name);

  cout << "Enter account type: ";
  getline(cin, accountType);

  cout << "Enter initial deposit: ";
  cin >> initialBalance;

  if (initialBalance < 0) {
    cout << "Initial balance cannot be negative.\n";
    return;
  }

  long long accountNumber = generateAccountNumber();

  BankAccount newAccount(accountNumber, name, accountType, initialBalance);

  accounts.push_back(newAccount);
}

void Bank::depositMoney() {
  long long accountNumber;
  double amount;

  cout << "\n========== DEPOSIT ==========\n";

  cout << "Enter account number: ";
  cin >> accountNumber;

  int index = findAccountIndex(accountNumber);

  if (index == -1) {
    cout << "Account not found.\n";
    return;
  }

  cout << "Enter deposit amount: ";
  cin >> amount;

  if (accounts[index].deposit(amount)) {
    cout << "Deposit successful!\n";
  } else {
    cout << "Invalid deposit amount.\n";
  }
}

void Bank::withdrawMoney() {
  long long accountNumber;
  double amount;

  cout << "\n========== WITHDRAW ==========\n";

  cout << "Enter account number: ";
  cin >> accountNumber;

  int index = findAccountIndex(accountNumber);

  if (index == -1) {
    cout << "Account not found.\n";
    return;
  }

  cout << "Enter withdrawal amount: ";
  cin >> amount;

  if (accounts[index].withdraw(amount)) {
    cout << "Withdrawal successful!\n";
  } else {
    cout << "Invalid withdrawal or insufficient balance.\n";
  }
}

void Bank::checkBalance()
{
    long long accountNumber;

    cout << "\n========== BALANCE CHECK ==========\n";

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index =
        findAccountIndex(accountNumber);

    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "Current Balance: Rs. "
         << accounts[index].getBalance()
         << endl;
}

void Bank::saveAccounts()
{
    ofstream file(filename);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    for (const BankAccount& account : accounts)
    {
        file << account.toFileString()
             << endl;
    }

    file.close();
}

void Bank::loadAccounts()
{
    ifstream file(filename);

    if (!file)
    {
        return;
    }

    accounts.clear();

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string accountNumberString;
        string customerName;
        string accountType;
        string balanceString;

        getline(ss, accountNumberString, '|');
        getline(ss, customerName, '|');
        getline(ss, accountType, '|');
        getline(ss, balanceString, '|');

        long long accountNumber =
            stoll(accountNumberString);

        double balance =
            stod(balanceString);

        BankAccount account(
            accountNumber,
            customerName,
            accountType,
            balance
        );

        accounts.push_back(account);
    }

    file.close();
}

void Bank::displayAccount()
{
    long long accountNumber;

    cout << "\n========== DISPLAY ACCOUNT ==========\n";

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);

    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    accounts[index].displayDetails();
}

void Bank::displayAllAccounts()
{
    cout << "\n========== ALL ACCOUNTS ==========\n";

    if (accounts.empty())
    {
        cout << "No accounts found.\n";
        return;
    }

    for (const BankAccount& account : accounts)
    {
        account.displayDetails();
    }
}

