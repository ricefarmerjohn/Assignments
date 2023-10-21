#include <stdio.h>

void part1(int *arr, int arrNum){
    printf("\n Part 1: \n Your array is: ");
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] =  %d", i, arr[i]);
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}

void part2(int *arr, int arrNum){
    printf("\nPart 2:\n Your array in reverse is: ");
    for (int i = arrNum - 1; i >= 0; i--) {
        printf("[%d] = %d ", i, arr[i]);
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}

void part3(int *arr, int arrNum){
    printf("\nPart 3:\n");
    for (int i = 0; i < arrNum; i++) {
        if (arr[i] % 2 == 0) {
            printf("[%d] = %d, ", i, arr[i]);
            if (i < arrNum - 1) {
                printf(", ");
            }
        }
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
    printf("\nYour array in sorted order is: ");
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] = %d, ", i, sortedArr[i]);
        // FIX LE FUNNY ARRAY
    }
}
void part6(int *arr, int arrNum){
    printf("\nPart 6: \n");
    printf("Your array with first and last element switched is: ");
    int lastElement = arr[arrNum - 1];
    arr[arrNum - 1] = arr[0];
    arr[0] = lastElement;
    for (int i = 0; i < arrNum; i++)
        printf("[%d] =  %d, ", i, arr[i]);
}
int main() {
    int num;
    int total = 0;
    printf("Please enter the number of integers to process: ");
    scanf("%d", &num);
    int arr[num];
    int size = (int) (sizeof(arr) / sizeof(arr[0]));
    printf("The number you have given is %d \nPlease enter your integers separated by spaces: ", size);

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    part1(arr, num);
    part2(arr, num);
    part3(arr,num);
    part4(arr, num);
    part5(arr, num);
    part6(arr, num);
}
