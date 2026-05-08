#include<stdio.h>
#include<conio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
void transfer_money();
void change_password();

char name[50];
int account_no=1000;
char password[16];
float balance=0;

int main()
{
  int choice;
  while(1)
  	{
		  clrscr();

		 printf("\nBANK MANAGEMENT SYSTEM");

		printf("\n1. create account");
	  	printf("\n2. deposit money");
	  	printf("\n3. withdraw money");
	  	printf("\n4. check balance");
        printf("\n5. transfer money");
        printf("\n6. change password");
	  	printf("\n7. exit");

	  	printf("\nEnter your choice: ");
	  	scanf("%d",&choice);

	  	switch(choice)
	  	{
	  		case 1:
	  			create_account();
	  			break;
	  		case 2:
	  			deposit_money();
		  		break;
	  		case 3:
		  		withdraw_money();
		  		break;
		  	case 4:
		  		check_balance();
		  		break;
      	    case 5:
        	    transfer_money();
        	    break;
     	    case 6:
      	 	    change_password();
      	 	    break;
        	case 7:
		  		printf("\nThank you");
		  		getch();
		  		return 0;
		  	default:
		  		printf("\nInvalid choice");
	  	}

	  	getch();
  	}
}

void create_account()
{
  int count=1;
  clrscr();
  printf("\nCREATE A ACCOUNT");

  printf("Enter name: ");
  scanf("%s", name);

  printf("Account number %d: ", account_no+count);

  printf("Set a password: ");
  scanf("%s",password);
