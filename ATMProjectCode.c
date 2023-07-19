#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void askAccType() {
    
    int ch;
    printf("\n\nChoose your account =>\n");
    printf("\n 1> Savings Account");
    printf("\n 2> Current Account\n");
    scanf("%d",&ch);
}
bool askUsrPin() {
    
    char username[] = "vishu@123";
    char usr[20];
    int pin;
    
    printf("\nEnter your username : ");
    scanf("%s",usr);
    if(!strcmp(username,usr)) {
        printf("\nEnter your pin : ");
        scanf("%d",&pin);
        if(pin == 1900)
            return true;
        else
            printf("\n\t\e[1mIncorrect Pin\e[m"); 
    }
    else
        printf("\n\t\e[1mIncorrect Username\e[m");
        
    return false;
}
void menu() {
    printf("\n        \e[1mWelcome to Automated Banking Machine\e[m        ");
    printf("\n 1) Balance Enquiry");
    printf("\n 2) Money Deposit");
    printf("\n 3) Money Withdrawal");
    printf("\n 4) Exit");
}
int main()
{
    float amount = 26000.25;
    char enter[1];
    int choice;
    
    printf("\nInsert your card");
    scanf("%[^\n]s",enter);
    
    do {

        menu();
        
        printf("\nChoose your operation : ");
        scanf("%d",&choice);
        
        switch(choice) {
        
            case 1 : {
                printf("\n\t\t\e[1mBalance Inquiry\e[m");
                askAccType();
                if(askUsrPin()) {
                    int a;
                    printf("\n\t\e[1mYour bank balance : Rs.%.2f\e[m\n", amount);
                    printf("\nDo you want to make another transaction ?");
                    printf("\n1. Yes\n2. No\n");
                    scanf("%d",&a);
                    if(a == 2) {
                        printf("\n\e[1mThank You for using Automated Banking Machine\e[m");
                        exit(0);
                    }
                }
                else {
                    printf("\nRemove your card and try again!");
                    exit(0);
                }
                break;
            }
            case 2 : {
                int a;
                printf("\n\t\t\e[1mMoney Deposit\e[m");
                askAccType();
                if(askUsrPin()) {
                    printf("\nEnter amount to deposit : ");
                    scanf("%d",&a);
                    amount += a;
                    printf("\n\t\e[1mCurrent bank balance : Rs.%.2f\e[m", amount);
                    printf("\n\n\t\t    Transaction Completed");
                    printf("\n\t\t\tThank You!\n");
                    printf("\nDo you want to make another transaction ?");
                    printf("\n1. Yes\n2. No\n");
                    scanf("%d",&a);
                    if(a == 2) {
                        printf("\n\e[1mThank You for using Automated Banking Machine\e[m");
                        exit(0);
                    }
                }
                else {
                    printf("\nRemove your card and try again!");
                    exit(0);
                }
                break;
            }
            case 3 : {
                int a;
                printf("\n\t\t\e[1mMoney Withdrawal\e[m");
                askAccType();
                if(askUsrPin()) {
                    printf("\nEnter amount to withdraw : ");
                    scanf("%d",&a);
                    if(a <= amount) {
                        amount -= a;
                        printf("\n\t\e[1mCurrent bank balance : Rs.%.2f\e[m", amount);
                        printf("\n\n\t\t    Transaction Completed");
                        printf("\n\t\t\tThank You!\n");
                    }
                    else {
                        printf("\nSorry, Your account does not have enough balance\n");
                    }
                    printf("\nDo you want to make another transaction ?");
                    printf("\n1. Yes\n2. No\n");
                    scanf("%d",&a);
                    if(a == 2) {
                        printf("\n\e[1mThank You for using Automated Banking Machine\e[m");
                        exit(0);
                    }
                }
                else {
                    printf("\nRemove your card and try again!");
                    exit(0);
                }
                break;
            }
            case 4 : {
                printf("\n\e[1mThank You for using Automated Banking Machine\e[m");
                break;
            }
        }

    }while(choice != 4);

    return 0;
}
