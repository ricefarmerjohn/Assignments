#include <stdio.h>

void part1(int *arr, int arrNum){
    printf("\nPart 1: \nYour array is: ");
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] =  %d", i, arr[i]);
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}

void part2(int *arr, int arrNum){
    printf("\nPart 2:\nYour array in reverse is: ");
    for (int i = arrNum - 1; i >= 0; i--) {
        printf("[%d] = %d", i, arr[i]);
        if (i > 0) {
            printf(", ");
        }
    }
}

void part3(int *arr, int arrNum){
    printf("\nPart 3:\nThe even elements in the array is: ");
    int numEven = 0;
    int putComma = 0;
    for (int i = 0; i < arrNum; i++) {
        if (arr[i] % 2 == 0) {
            printf("[%d] = %d", i, arr[i]);
            numEven = 1;
            putComma = 1;

        }
        if (i != 0 && putComma == 1) {
            printf(",");
        }
        putComma = 0;
        // Fix commas
    }
    if(numEven != 1){
        printf("There are no even elements in the array.");
    }
}

void part4(int *arr, int arrNum){
    int total = 0;
    printf("\nPart 4:\nThe sum of all values in your array is: ");
    for (int i = 0; i < arrNum; i++)
        total += arr[i];
    printf("%d", total);
}
void part5(int *arr, int arrNum){
    printf("\nPart 5:\nYour array in sorted order is: ");
    int sortedArr[arrNum];
    for (int i = 0; i < arrNum; i++)
        sortedArr[i] = arr[i];

    for (int i = 0; i < arrNum - 1; i++) {
        for (int j = i + 1; j < arrNum; j++) {
            if (sortedArr[i] > sortedArr[j]) {
                int temp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = temp;
            }
        }
    }
    for (int i = 0; i < arrNum; i++) {
        int element = 0;
        for (int j = 0; j < arrNum; j++) {
            if (sortedArr[j] == arr[i]) {
                element = j;
                break;
            }
        }
        printf(" [%d] = %d", element, arr[i]);
        if (i != arrNum - 1) {
            printf(",");
        }
    }
}
void part6(int *arr, int arrNum){
    printf("\nPart 6: \n");
    printf("Your array with first and last element switched is: ");
    int lastElement = arr[arrNum - 1];
    arr[arrNum - 1] = arr[0];
    arr[0] = lastElement;
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] =  %d", i, arr[i]);
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}
int main() {
    int num;

    while(1) {
        printf("Please enter the number of integers to process: ");
        scanf("%d", &num);
        if(num >= 5 && num <= 12){
            break;
        } else{
            printf("The user must provide a minimum of 5 integers and a maximum of 12.\n");
        }
    }

    int arr[num];
    int size = (int) (sizeof(arr) / sizeof(arr[0]));
    printf("The number you have given is %d (%d bytes)\nPlease enter your integers separated by spaces: ", size, sizeof(arr));

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    part1(arr, num);
    part2(arr, num);
    part3(arr,num);
    part4(arr, num);
    part5(arr, num);
    part6(arr, num);
}
