#include <stdio.h>
#include <string.h>
#include "atm.h"

/**
 * log_transaction - stores a transaction string
 * @u: pointer to User
 * @msg: transaction message
 */
void log_transaction(User *u, const char *msg)
{
    if (u->transaction_count < MAX_TRANSACTIONS)
    {
        strncpy(u->transactions[u->transaction_count], msg, 50);
        u->transactions[u->transaction_count][49] = '\0';
        u->transaction_count++;
    }
    else
    {
        /* shift transactions left when full */
        int i;
        for (i = 1; i < MAX_TRANSACTIONS; i++)
        {
            strcpy(u->transactions[i - 1], u->transactions[i]);
        }
        strncpy(u->transactions[MAX_TRANSACTIONS - 1], msg, 50);
        u->transactions[MAX_TRANSACTIONS - 1][49] = '\0';
    }
}

/**
 * show_transactions - prints transaction history
 * @u: pointer to User
 */
void show_transactions(User *u)
{
    int i;

    if (u->transaction_count == 0)
    {
        printf("No transactions yet.\n");
        return;
    }

    printf("Transaction History:\n");
    for (i = 0; i < u->transaction_count; i++)
    {
        printf("%d. %s\n", i + 1, u->transactions[i]);
    }
}