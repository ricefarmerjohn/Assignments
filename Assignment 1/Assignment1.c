#include <stdio.h>

/*
 * Description: This program is called the converter which will convert one unit to another.
 */
int main() {
    int i, n = 0, k = 0;
    float amount;
    char ch;

    while(n != 1) {
        printf("Enter an integer listed below to enter the action associated with that integer\n");
        printf("1 for conversion between Kilograms and Pounds\n2 for conversion between Hectares and Acres\n3 for conversion between Litres and Gallons\n");
        printf("4 for conversion between Kilometre and Mile\n5 to quit\n");
        printf("Enter the integer here: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("K for conversion from Kilograms to Pounds\nP for conversion from Pounds to Kilograms\n");
                printf("Enter the character here: ");
                scanf(" %c", &ch);
                if(ch == 'K' || ch == 'k'){
                    printf("Enter the amount here: ");
                    scanf("%f", &amount);
                    float conversion = amount * 2.20462;
                    printf("Your conversion is: %f\n", conversion);
                } else if(ch == 'P' || ch == 'p'){
                    printf("Enter the amount here: ");
                    scanf("%f", &amount);
                    float conversion = amount / 2.20462;
                    printf("Your conversion is: %f\n", conversion);
                }
                break;
            case 2:
                printf("H for conversion from Hectares to Acres\nA for conversion from Acres to Hectares\n");
                printf("Enter the character here: ");
                scanf(" %c", &ch);
                break;
            case 3:
                printf("L for conversion from Litres to Gallons\nG for conversion from Gallons to Litres\n");
                printf("Enter the character here: ");
                scanf(" %c", &ch);
                break;
            case 4:
                printf("K for conversion from Kilometre to Mile\nM for conversion from Mile to Kilometre\n");
                printf("Enter the character here: ");
                scanf(" %c", &ch);
                break;
            default:
                break;
        }
        if(i == 5){
            n = 1;
            printf("Quiting works");
        }
    }
    return 0;
}
