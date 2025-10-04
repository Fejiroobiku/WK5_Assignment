# WK5_Assignment - ATM Simulator in C

## 📌 Problem Statement
This project was developed as part of **Week 5 Assignment**.
The task was to implement a simple **ATM banking system** in C using only:
- Variables
- Control flow (if, switch, loops)
- Functions
- Arrays (1D, 2D)
- Strings

The ATM system simulates login with a username and a 4-digit PIN, then allows users to:
1. Check Balance
2. Deposit Money
3. Withdraw Money
4. View Transaction History
5. Logout

The goal was to apply **modular design** and practice input/output operations, loops, and string/array management.

---

## ⚙️ Assumptions
- There are **3 predefined users** in the system.
- Each user has:
  - A unique username (string)
  - A 4-digit PIN (integer)
  - A starting balance (float)
- Transaction history stores the **last 10 actions**.
- No external libraries or structs were used (only arrays & strings, as required).

---

## 🖥️ Compilation & Execution
To compile and run the program:

```bash
gcc -Wall -Werror -pedantic -std=ansi atm.c -o atm
./atm

🔑 Sample Run

=== Welcome to the ATM Simulator ===

Enter username: maxwel
Enter 4-digit PIN: 1234

Login successful! Welcome, maxwel.

--- ATM Menu ---
1. Check Balance
2. Deposit
3. Withdraw
4. View Transactions
5. Logout
Choose option: 1

Your balance: 1000.00

📂 Key Functions

    login() → Handles username and PIN authentication

    menu() → Displays the ATM menu and routes choices

    check_balance() → Prints user balance

    deposit() → Adds money and logs the transaction

    withdraw() → Deducts money (if sufficient) and logs

    view_transactions() → Shows up to 10 recent operations

👥 Contributors

    Maxwel Okoth – Implemented login system, menu flow, and deposits

    Michael Obiku – Implemented withdrawals, transaction history, and code cleanup
