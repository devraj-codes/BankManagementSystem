#include<stdio.h>
#include<stdlib.h>
#include "bank.h"

void createAccount()
{
    struct Account acc;
    FILE *fp;

    printf("\n=== Create New Account ===");

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("\nEnter Name: ");
    scanf("%[^\n], acc.name");

    printf("\nAccount Type (Saving/Current): ");
    scanf("%s", acc.type);

    printf("\nInitial Deposit Amount: ");
    scanf("%f", acc.balance);

    if(acc.balance < 500)
    {
        printf("\nMinimum initial deposit is Rs.500!");
        return;
    }
    
    fp = fopen("accounts.dat", "ab");
    if(fp == NULL)
    {
        printf("\nError Opening file!");
        return;
    }

    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully!");
}

void viewAllAccounts()
{
    struct Account acc;
    FILE *fp;
    int count=0;

    fp=fopen("accounts.dat", "rb");
    if(fp == NULL)
    {
        printf("\nNo accounts found!");
        return;
    };

    printf("\n%-10s %-25s %-12s %-10s", "ACC No", "Name", "Type", "Balance");
    printf("\n----------------------------------------------------------");

    while(fread(&acc, sizeof(struct Account), 1, fp) == 1)
    {
        printf("\n%-10d %-25s %-12s Rs.%.2f", acc.accNo, acc.name, acc.type, acc.balance);
        count++;
    }

    fclose(fp);
    printf("\n----------------------------------------------------------");
    printf("\nTotal Accounts: %d", count);
}

void checkBalance()
{
    struct Account acc;
    FILE *fp;
    int accNo, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    fp= fopen("accounts.dat", "rb");
    if(fp == NULL)
    {
        printf("\nNo Accounts found!");
        return;
    }

    while(fread(&acc, sizeof(struct Account), 1, fp) == 1)
    {
        if(acc.accNo == accNo)
        {
            printf("\n--- Account Details ---");
            printf("\nAccount No: %d", acc.accNo);
            printf("\nName      : %s", acc.name);
            printf("\nType      : %s", acc.type);
            printf("\nBalance   : Rs.%.2f", acc.balance);
            found =1;
            break;
        }
    }

    fclose(fp);
    if(!found) printf("\nAccount not found!");
}