#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Account
{
    int accNo;
    char name[50];
    char type[15];
    float balance;
};

struct Account accounts[100];
int totalAccounts;

void createAccount();
void viewAllAccounts();
void depositMoney();
void withdrawMoney();
void checkBalance();
void searchByAccNo();
void searchByName();
void updateAccount();
void deleteAccount();

void createAccount()
{
    int i;
    int duplicate;

    duplicate=0;

    if(totalAccounts >= 100)
    {
        printf("\nBank is full! Cannot add more accounts.");
        return;
    }

    printf("\n=== Create New Account ===");
    printf("\nEnter Account Number");
    scanf("%d", &accounts[totalAccounts].accNo);

    for(i=0; i < totalAccounts; i++)
    {
        if(accounts[i].accNo == accounts[totalAccounts].accNo)
        {
            duplicate = 1;
            break;
        }
    }

    if(duplicate == 1)
    {
        printf("\nAccount number already exists! Try a different nuber.");
        return;
    }

    printf("\nEnter Name: ");
    fflush(stdin);
    gets(accounts[totalAccounts].name);

    printf("\nAccount Type (Savings/Current): ");
    scanf("%s", accounts[totalAccounts].type);

    printf("\nInitial Deposit Amount: Rs.");
    scanf("%f", &accounts[totalAccounts].balance);

    if(accounts[totalAccounts].balance < 500)
    {
        printf("\nMinimum initial deposit is Rs.500!");
        printf("\nAccount NOT created.");
        return;
    }

    totalAccounts++;

    printf("\nAccount Created Successfully!");
    printf("\nTotal accounts in bank: %d", totalAccounts);
}

void viewAllAccounts()
{
    int i;

    if(totalAccounts == 0)
    {
        printf("\nNo accounts found! Bank is empty");
        return;
    }

    printf("\n%s %s %s %.2f", "Acc No", "Name", "Type", "Balance");
    printf("\n---------------------------------------");

    for(i=0; i<totalAccounts; i++)
    {
        printf("\n%d %s %s %.2f", accounts[i].accNo, accounts[i].name, accounts[i].type, accounts[i].balance);
    }

    printf("\n---------------------------------------");
    printf("\nTotal Accounts: %d", totalAccounts);
}

int main()
{
    int choice;

    totalAccounts = 0;

    do {
        printf("\n+==============================+");
        printf("\n|    BANK MANAGEMENT SYSTEM    |");
        printf("\n|==============================|");
        printf("\n| 1. Create Account            |");
        printf("\n| 2. Deposit Money             |");
        printf("\n| 3. Withdraw Money            |");
        printf("\n| 4. Check Balance             |");
        printf("\n|5. View All Accounts          |");
        printf("\n| 6. Search by Account Number  |");
        printf("\n| 7. Search by Name            |");
        printf("\n| 8. Update Account            |");
        printf("\n| 9. Delete Account            |");
        printf("\n| 0. Exit                      |");
        printf("\n+==============================+");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createAccount();
                    break;
            case 2: depositMoney();
                    break;
            case 3: withdrawMoney();
                    break;
            case 4: checkBalance();
                    break;
            case 5: viewAllAccounts();
                    break;
            case 6: searchByAccNo();
                    break;
            case 7: searchByName();
                    break;
            case 8: updateAccount();
                    break;
            case 9: deleteAccount();
                    break;
            case 0: printf("\nTank You for using Bank Management System!");
                    printf("\nExiting.....");
                    break;
            default: printf("\nInvalid Choice!");
        }
    }while(choice != 0);

    return 0;
}