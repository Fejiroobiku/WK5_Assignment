#include <stdio.h>
#include <string.h>

/* User data (parallel arrays) */
char usernames[3][20] = {"maxwel", "michael", "fejiro"};
int pins[3] = {1234, 5678, 4321};
float balances[3] = {1000.0, 2000.0, 500.0};

/* Transaction log */
char transactions[10][100];
int transCount = 0;

/* Function Prototypes */
int login(void);
void menu(int userIndex);
void record(const char *msg);
void show_transactions(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int userIndex = login();

	if (userIndex == -1)
	{
		printf("Too many failed attempts. Exiting...\n");
		return (0);
	}
	menu(userIndex);
	return (0);
}

/**
 * login - Username + PIN login
 *
 * Return: user index or -1
 */
int login(void)
{
	char uname[20];
	int pin, attempts = 0, i;

	while (attempts < 3)
	{
		printf("\nUsername: ");
		scanf("%19s", uname);
		printf("PIN (4 digits): ");
		scanf("%d", &pin);

		for (i = 0; i < 3; i++)
		{
			if (strcmp(uname, usernames[i]) == 0 && pin == pins[i])
			{
				printf("Welcome, %s!\n", usernames[i]);
				return (i);
			}
		}
		printf("Invalid login.\n");
		attempts++;
	}
	return (-1);
}

/**
 * menu - Main ATM menu
 * @u: index of logged-in user
 */
void menu(int u)
{
	int choice;
	float amt;

	do {
		printf("\n--- ATM Menu ---\n");
		printf("1. Balance\n2. Deposit\n3. Withdraw\n");
		printf("4. Transactions\n5. Logout\nChoice: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("Balance: %.2f\n", balances[u]);
			record("Checked balance");
		}
		else if (choice == 2)
		{
			printf("Amount: ");
			scanf("%f", &amt);
			if (amt > 0)
			{
				balances[u] += amt;
				printf("Deposited %.2f\n", amt);
				sprintf(transactions[transCount++], "Deposited %.2f", amt);
			}
		}
		else if (choice == 3)
		{
			printf("Amount: ");
			scanf("%f", &amt);
			if (amt > 0 && amt <= balances[u])
			{
				balances[u] -= amt;
				printf("Withdrew %.2f\n", amt);
				sprintf(transactions[transCount++], "Withdrew %.2f", amt);
			}
			else
				printf("Invalid or insufficient.\n");
		}
		else if (choice == 4)
			show_transactions();
		else if (choice != 5)
			printf("Invalid choice.\n");

		if (transCount >= 10)
			transCount = 0;
	} while (choice != 5);

	printf("Goodbye!\n");
}

/**
 * record - Logs a message if space available
 * @msg: message to store
 */
void record(const char *msg)
{
	if (transCount < 10)
		sprintf(transactions[transCount++], "%s", msg);
}

/**
 * show_transactions - Prints recent history
 */
void show_transactions(void)
{
	int i;

	if (transCount == 0)
		printf("No transactions yet.\n");
	else
	{
		printf("\n--- Transactions ---\n");
		for (i = 0; i < transCount; i++)
			printf("%d. %s\n", i + 1, transactions[i]);
	}
}
