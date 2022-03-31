# include<stdio.h>
# include<windows.h>
# include<time.h>

int main(){

    system("color 3F");

    int pin = 1234, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t          %s", ctime(&now));
    printf("\n\t\t\t====================*Welcome to My ATM Banking Project*====================");
    
    while (pin != enteredPin){
        printf("\n\t\tPlease Enter Your Pin: ");
        scanf("%d", &enteredPin);

        if (enteredPin != pin){
            Beep(610, 1000);
            printf("Invalid Pin!!\n");
        }
        count++;
        if (count == 3 && pin != enteredPin){
            printf("\nYou Have Exausted With Your Maximum Try!!");
            exit(0);
        }
    }

    while (continueTransaction != 0){
        printf("\n\t\t\t====================*Available Transaction*====================");
        printf("\n\n\t\t1. Withdrawl");
        printf("\n\t\t2. Deposit");
        printf("\n\t\t3. Check Balance");
        printf("\n\n\t\tPlease Select The Option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
            while (amount % 500 != 0){
                printf("\n\t\tPlease Enter The Amount : ");
                scanf("%d", &amount);

                if (amount % 500 != 0){
                    printf("\n\t\tThe Amount Should Be Muntiple Of 500");
                }
            }
            if (balance < amount){
                printf("\n\t\tSorry Insufficient Balance");
                amount = 1;
                break;
            }
            else {
                balance -= amount;
                printf("\n\t\tYou Have Withdrawn Rs. %d.\n\t\tYour New Balance Is %.2f\n", amount, balance);
                printf("\n\t\t\t====================*Thank You For Using My Banking Service*====================");
                printf("\n\t\t\t====================*Visit Again*====================");
                amount = 1;
                break;
            }

            case 2: 
                printf("\n\t\tPlease Enter The Amount : ");
                scanf("%d", &amount);
                balance += amount;
                printf("\n\t\tYou Have Deposited Rs. %d.\n\t\tYour New Blance Is %.2f\n", amount, balance);
                printf("\n\t\t\t====================*Thank You For Using My Banking Service*====================");
                printf("\n\t\t\t====================*Visit Again*====================");
                amount = 1;
                break;

            case 3:
            printf("\n\t\tYour Current Balance Is Rs. %.2f\n", balance);
            printf("\n\t\t\t====================*Thank You For Using My Banking Service*====================");
            printf("\n\t\t\t====================*Visit Again*====================");
            break;

            default:
            Beep(610, 1000);
            printf("\n\t\tInvalid Option!!");
        }

        printf("\n\t\tDo You Want To Perform Another Transaction?\n\t\tThen, Press - 1[YES] or Press - 0[NO]\n\t\tYou Choose : ");
        scanf("%d", &continueTransaction);
    }

    return 0;
}