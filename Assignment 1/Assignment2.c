#include <stdio.h>

int main(){
    int number;
    while(1) {
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &number);
        if (number == 0) {
            printf("You have quit the program");
            break;
        }
        printf("You entered the number ");
        if (number >= 1 && number <= 999) {
            // Checks if it's greater than 100
            if (number >= 100) {
                // Divide by 100 to get the single digit number
                switch (number / 100) {
                    case 1:
                        printf("one hundred");
                        break;
                    case 2:
                        printf("two hundred");
                        break;
                    case 3:
                        printf("three hundred");
                        break;
                    case 4:
                        printf("four hundred");
                        break;
                    case 5:
                        printf("five hundred");
                        break;
                    case 6:
                        printf("six hundred");
                        break;
                    case 7:
                        printf("seven hundred");
                        break;
                    case 8:
                        printf("eight hundred");
                        break;
                    case 9:
                        printf("nine hundred");
                        break;
                    default:
                        break;
                }
                if (number % 100 != 0) {
                    printf(" and ");
                }
                // This will make it so that the remaining numbers are not 3 digits but instead smaller ones that can be found in smaller switch statements
                number = number % 100;
            }
            if (number >= 20) {
                switch (number / 10) {
                    case 2:
                        printf("twenty");
                        break;
                    case 3:
                        printf("thirty");
                        break;
                    case 4:
                        printf("forty");
                        break;
                    case 5:
                        printf("fifty");
                        break;
                    case 6:
                        printf("sixty");
                        break;
                    case 7:
                        printf("seventy");
                        break;
                    case 8:
                        printf("eighty");
                        break;
                    case 9:
                        printf("ninety");
                        break;
                    default:
                        break;
                }
                if (number % 10 != 0) {
                    printf("-");
                }
                number = number % 10;
            }
            if (number > 0) {
                switch (number) {
                    case 1:
                        printf("one");
                        break;
                    case 2:
                        printf("two");
                        break;
                    case 3:
                        printf("three");
                        break;
                    case 4:
                        printf("four");
                        break;
                    case 5:
                        printf("five");
                        break;
                    case 6:
                        printf("six");
                        break;
                    case 7:
                        printf("seven");
                        break;
                    case 8:
                        printf("eight");
                        break;
                    case 9:
                        printf("nine");
                        break;
                    case 10:
                        printf("ten");
                        break;
                    case 11:
                        printf("eleven");
                        break;
                    case 12:
                        printf("twelve");
                        break;
                    case 13:
                        printf("thirteen");
                        break;
                    case 14:
                        printf("fourteen");
                        break;
                    case 15:
                        printf("fifteen");
                        break;
                    case 16:
                        printf("sixteen");
                        break;
                    case 17:
                        printf("seventeen");
                        break;
                    case 18:
                        printf("eighteen");
                        break;
                    case 19:
                        printf("nineteen");
                    default:
                        break;
                }
            }
            printf("\n");
        } else {
            printf("Invalid input, try again!\n");
        }
    }
}