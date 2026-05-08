#include<stdio.h>
#include<stdlib.h>
#include "bank.h"

int main()
{
    int choice;

    do{
        printf("\n╔══════════════════════════╗");
        printf("\n‖  BANK MANAGEMENT SYSTEM  ‖");
        printf("\n‖══════════════════════════‖");
        printf("\n‖ 1. Create Account        ‖");
        printf("\n‖ 2. Deposit Money         ‖");
        printf("\n‖ 3. Withdraw Money        ‖");
        printf("\n‖ 4. Check Balance         ‖");
        printf("\n‖ 5. View All Accounts     ‖");
        printf("\n‖ 6. Search Account        ‖");
        printf("\n‖ 7. Update Account        ‖");
        printf("\n‖ 8. Delete Accouny        ‖");
        printf("\n‖ 0. Exit                  ‖");
        printf("\n╚══════════════════════════╝");
        printf("\nEnter your choice: ");
        scanf("\n%d", &choice);

        switch(choice){
            case 1: createAccount();
                    break;
            case 2: depositeMoney();
                    break;
            case 3: withdrawMoney();
                    break;
            case 4: checkBalance();
                    break;
            case 5: viewAllAccounts();
                    break;
            case 6: searchByAccno();
                    break;
            case 7: updateAccount();
                    break;
            case 8: deleteAccount();
                    break;
            case 0: printf("\nExiting.....");
                    break;
            default: printf("\nInvalid Choice");
        }
    } while(choice!=0);

    return 0;
    
}

