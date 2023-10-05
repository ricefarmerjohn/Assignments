#include <stdio.h>
// I have this one lab because of one reason, the formatting sucks ass
int main(){
    int n, i;
    printf("Enter number of days in month: ");
    scanf("%d", &n);
    printf("Enter starting day of the week (1 = Sun, 7 = Sat): ");
    scanf("%d", &i);

    for(int x = 0; x < i; x++){
        printf("   ");
    }
    for(int m = 1; m < n; i++, m++){
        printf("%d ", m);
        if(i % 7 == 0){
            printf("\n");
        }
    }
    return 0;
}