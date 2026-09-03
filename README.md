# Bank Management System in C++

A robust, object-oriented console-based Bank Management System developed in C++. The system provides core banking operations, account record persistence via file I/O, dynamic account number generation, and input error recovery.

---

## Features

- **Create Account**: Generates a unique 6-digit account number, accepts customer details, and initializes an account with an opening balance.
- **Deposit Money**: Deposit funds into an existing account with positive-amount validation.
- **Withdraw Money**: Withdraw funds with checks against invalid amounts and insufficient balances.
- **Check Balance**: View real-time balance for any valid account number.
- **Display Account**: Query and display details of an individual account.
- **Display All Accounts**: View all active accounts in a formatted list.
- **File Persistence**: Automatically loads existing accounts on startup from `accounts.txt` and saves updates upon exiting the application.
- **Input Error Recovery**: Resilient against invalid input types (e.g. letters in numeric fields) to prevent infinite loops.

---

## File Structure

| File | Description |
| :--- | :--- |
| [`BankAccount.h`](BankAccount.h) | Header declaration for the `BankAccount` class. |
| [`BankAccount.cpp`](BankAccount.cpp) | Implementation of account details, deposits, withdrawals, and string serialization. |
| [`Bank.h`](Bank.h) | Header declaration for the `Bank` class. |
| [`Bank.cpp`](Bank.cpp) | Implementation of bank logic: account generation, lookups, transactions, file I/O. |
| [`main.cpp`](main.cpp) | Entry point containing the interactive CLI menu loop and input validation. |
| `accounts.txt` | Pipe-delimited file storing persistent account records. |

---

## Data Storage Format

Account records are stored in `accounts.txt` using a pipe-delimited (`|`) format:

```text
accountNumber|customerName|accountType|balance
```

**Example:**
```text
100001|John Doe|Savings|1500.00
100002|Jane Doe|Current|2500.50
```

---

## Prerequisites

- **C++ Compiler**: GCC / MinGW (`g++`), Clang, or MSVC supporting C++11 or higher.
- **Operating System**: Windows / Linux / macOS.

---

## Build & Execution

### 1. Compile

Open your terminal in the project directory and run:

```bash
g++ main.cpp Bank.cpp BankAccount.cpp -o BankApp.exe -std=c++11
```

### 2. Run

On Windows:
```powershell
.\BankApp.exe
```

On Linux / macOS:
```bash
./BankApp.exe
```

---

## Usage Guide

When launched, the program displays an interactive menu:

```text
====================================
       BANK MANAGEMENT SYSTEM
====================================
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display Account
6. Display All Accounts
7. Exit

Enter choice:
```

### Menu Options

1. **Create Account**: Enter customer full name, account type (e.g., `Savings`, `Current`), and an initial deposit amount (enter numbers only, e.g. `5000`).
2. **Deposit Money**: Enter your account number and the amount to deposit.
3. **Withdraw Money**: Enter your account number and the amount to withdraw.
4. **Check Balance**: Enter your account number to view current balance.
5. **Display Account**: Enter your account number to view account summary.
6. **Display All Accounts**: Prints a summary card for every loaded and newly created account.
7. **Exit**: Saves all account changes to `accounts.txt` and exits.

---

## Input Tips

- **Numeric Inputs**: When entering monetary amounts or account numbers, enter digits and decimals only (e.g., `35000` or `1500.50`), without currency symbols like `Rs.` or `$`.
