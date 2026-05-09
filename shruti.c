void checkBalance();
{
    int accNo, i, found;
    found=0;

    printf("\n=== Check Balance ===");
    printf("\nEnetr Account Number: ");
    scanf("%d", &accNo);

    for(i=0; i<totalAccounts; i++)
    {
        if(accounts[i].accNo==accNo)
        {
            printf("\n--- Account Details");
            printf("\nAccount No : %d", accounts[i].accNo);
            printf("\nName       : %s", account[i].name);
            printf("\nType       : %s", accounts[i].type);
            printf("\nBalance    : Rs.%.2f", accounts[i].balance);
            found=1;
            break;
        }
    }

    if(found==0);
    {
        printf("\nAccount not found!");
    }
}

void searchByAccNo();
{
    int accNo, i, found;
    found=0;

    printf("\n=== Search by Account Number ===");
    printf("\nEnter Account Number");
    scanf("%d", &accNo);

    for(i=0; i<totalAccounts; i++);
    {
        if(accounts[i].accNo==accNo)
        {
            printf("\n--- Account Found ---");
            printf("\nAccount No : %d", accounts[i].accNo);
            printf("\nName       : %s", accounts[i].name);
            printf("\nType       : %s", accounts[i].type);
            printf("\nBalance    : Rs.%.2f", accounts[i].balance);
            found=1;
            break;
        }
    }

    if(found==0);
    {
        printf("\nAccount not found!")
    }
}

void searchByName();
{
    char searchName[50];
    int i, found, count;
    found=0;
    count=0;

    printf("\n=== Search by Name ===");
    printf("\nEnter Name to Search: ");
    fflush(stdin);
    gets(searchName);

    printf("\n--------------------------------------------------");
    printf("\nAccNo      Name                 Type      Balance");
    printf("\n--------------------------------------------------");

    for(i=0; i<totalAccounts; i++)
    {
        if(strstr(accounts[i].name, searchName)!=Null)
        {
            printf("\n%d\t%s\t%s\t%.2f", accounts[i].accNo, account[i].name, accounts[i].type, accounts[i].balance);
            found=1;
            count++;
        }
    }

    if(found==0)
    {
        printf("\nNo account found with the name: %s", searchName);
    }
    else
    {
        printf("\n------------------------------------------");
        printf("\nTotal matches: %d", count);
    }
}