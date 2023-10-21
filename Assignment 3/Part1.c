#include <stdio.h>

int main() {
    int num;

    printf("Please enter the number of integers to process: ");
    scanf("%d", &num);
    int arr[num];
    int size = (sizeof(arr) / sizeof(arr[0]));
    printf("The number you have given is %d", size);
}
