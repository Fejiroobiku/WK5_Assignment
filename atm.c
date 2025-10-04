#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ================================
// Banking ATM Simulator
// Contributors:
// - Maxwel Okoth: PIN system & Withdrawal
// - Michael Obiku: Deposit & Balance Check
// - Both: Menu, Loop & Testing
// ================================

// Initial PIN and balance
int pin = 1234;  // 4-digit PIN
float balance = 50000;

// Function Prototypes
void login();              // Maxwel
void withdraw();           // Maxwel
void deposit();            // Michael
void checkBalance();       // Michael
void menu();               // Both

// ================================
// Function: login()
// Contributor: Maxwel Okoth
// Handles PIN authentication
// ================================
void login() {
    int enteredPin, count = 0;

    while (1) {
        printf("\n\t Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("\tLogin successful!\n");
            break;
        } else {
            printf("\tInvalid PIN!\n");
            count++;
        }

        if (count == 3) {
            printf("\n\tToo many attempts. Exiting...\n");
            exit(0);
        }
    }
}

// ================================
// Function: withdraw()
// Contributor: Maxwel Okoth
// Handles withdrawal transactions
// ================================
void withdraw() {
    int amount = 0;
    printf("\n\tEnter the amount to withdraw (multiple of 500): ");
    scanf("%d", &amount);

    if (amount % 500 != 0) {
        printf("\tAmount must be a multiple of 500!\n");
        return;
    }

    if (amount > balance) {
        printf("\tInsufficient balance!\n");
    } else {
        balance -= amount;
        printf("\tYou have withdrawn Rs. %d\n", amount);
        printf("\tNew Balance: %.2f\n", balance);
    }
}
