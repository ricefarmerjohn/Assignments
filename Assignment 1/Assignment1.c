#include <stdio.h>

int main() {
    int i, n = 0;
    printf("Welcome to the converter, enter an integer listed below to enter the action associated with that integer\n");
    printf("1 for conversion between Kilograms and Pounds\n2 for conversion between Hectares and Acres\n3 for conversion between Litres and Gallons\n");
    printf("4 for conversion between Kilometre and Mile\n5 to quit\n");
    while(n != 1) {
        printf("Enter the integer here: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                printf("1 works\n");
                break;
            case 2:
                printf("2 works\n");
                break;
            case 3:
                printf("3 works\n");
                break;
            case 4:
                printf("4 works\n");
                break;
            case 5:
                printf("5 works\n");
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
