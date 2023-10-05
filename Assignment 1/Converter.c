#include <stdio.h>

int main(){
    char input;
    printf("Is the temperature in (F) or (C): ");
    scanf("%c", &input);

    if(input == 'C'){
        printf("The input fucking worked for C");
    }
    else if(input == 'F'){
        printf("The input fucking worked for F");
    }
}
