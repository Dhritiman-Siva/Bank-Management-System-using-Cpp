#include <iostream>

#include "Bank.h"

using namespace std;

int main()
{
    Bank bank("accounts.txt");

    int choice;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "       BANK MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.depositMoney();
                break;

            case 3:
                bank.withdrawMoney();
                break;

            case 4:
                bank.checkBalance();
                break;

            case 5:
                bank.displayAccount();
                break;

            case 6:
                bank.displayAllAccounts();
                break;

            case 7:
                cout << "Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
