void updateAccount()
{
    int accNo, i, found, choice;
    found=0;

    printf("\n=== Update Account ===");
    printf("\nEnter Account Number: ");
    printf("%d", &accNo);

    for(i=0; i<totalAccounts; i++);
    {
        if(accounts[i].accNo==accNo);
        {
            printf("\nAccount Found: %s", accounts[i].name);
            printf("\nWhat to update?");
            printf("\n1. Name");
            printf("\n2. Account Type");
            printf("\nEnter choice: ");
            scanf("%d", &choice);

            if(choice==1)
            {
                printf("\nEnter New Name: ");
                fflush(stdin);
                gets(accounts[i].name);
                printf("\nName updated successfully!");
            }
            else if(choice==2)
            {
                printf("\nEnter New Type (Savings/Current): ");
                scanf("%s", accounts[i].type);
                printf("\nType updated successfully!");
            }
            else
            {
                printf("Invalid choice!");
            }

            found=1;
            break;
        }
    }

    if(found==0)
    {
        printf("\nAccount not found!");
    }
}

void deleteAccount()
{
    int accNo, i, fount, position, confirm;
    found=0;
    position=-1;

    printf("\n=== Delete Account ===");
    printf("\nEnter Account Number to Delete: ");
    scanf("%d", &accNo);

    for(i=0; i<totalAccounts; i++);
    {
        if(accounts[i].accNo==acc.No
        {
            position=i;
            found=1;
            break;
        }
    }

    if(found==0)
    {
        printf("\nAccount not found!");
        return;
    }

    printf("\nAccount Holder: %s", account[position].name);
    printf("\nBalance: Rs.%.2f", accounts[positiion].balance);
    printf("\nAre you sure? (1=Yes / 0=No): ");
    scanf("%d", &confirm);

    if(confirm!=1)
    {
        printf("\nDeletion Cancelled");
        return;
    }

    for(i=position; i<totalAccounts-1; i++)
    {
        accounts[i]=accounts[i+1];
    }

    totalAccounts--;
    peintf("\nAccount deleted successfully!");
    printf("\nRemaining accounts: %d", totalAccounts);
}