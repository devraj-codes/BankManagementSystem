#ifndef BANK_H
#define BANK_H

struct Account {
    int accNo;
    char name[50];
    char type[15];
    float balance;
};

void createAccount();
void viewAllAccounts();
void depositMoney();
void withdrawMoney();
void searchByAccNo();
void searchByName();
void updateAccount();
void deleteAccount();

#endif