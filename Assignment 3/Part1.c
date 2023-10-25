#include <stdio.h>
/**
 * Name of Program: Array interactions
 * Purpose: This program will ask an integer for the size of the array and a certain amount of integers to be inputted
 * depending on the size the user has given. The program will then print out 6 parts that vastly interacts with the
 * array, such as revealing the elements in each index or printing out the even elements in the array's index.
 * Author: Keefe Feng
 * Student ID: 251300600
 * Date: Oct 24, 2023
 */

/**
 * This function will loop a certain amount of times depending on your array size, and each loop will print out
 * A element with it's corresponding index number of the array.
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part1(int *arr, int arrNum){
    printf("\nPart 1: \nYour array is: ");
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] =  %d", i, arr[i]);
        // This will check if a comma is needed or not, and will not put a comma if it's at the end of the array
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}

/**
 * This function will have a loop that starts at the end of the array and loops until the beginning, it will print out
 * The element with the corresponding index number of the array
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part2(int *arr, int arrNum){
    printf("\nPart 2:\nYour array in reverse is: ");
    for (int i = arrNum - 1; i >= 0; i--) {
        printf("[%d] = %d", i, arr[i]);
        // Will print until i < 0 since the array is being printed in reverse, the end index will be 0
        if (i > 0) {
            printf(", ");
        }
    }
}

/**
 * This function will have a loop that will loop until the end of the array, each loop will check one element of the
 * array if it's even. If the element is a modulo of 2 then it will be printed out.
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part3(int *arr, int arrNum){
    printf("\nPart 3:\nThe even elements in the array is: ");
    int putComma = 0;
    for (int i = 0; i < arrNum; i++) {
        // Checks if it's even
        if (arr[i] % 2 == 0) {
            // Will check if it's the end, if not then it will print a comma
            if (i != 0 && putComma == 1) {
                printf(",");
            }
            if (putComma == 0) {
                putComma = 1;
            }
            printf(" [%d] = %d", i, arr[i]);
        }
    }
}

/**
 * This function will have a loop that will loop until the end of the array, each loop will add one element of the
 * array to an integer called "total", this integer (which is the sum of all values of the array) will be printed out
 * after the loop ends
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part4(int *arr, int arrNum){
    int total = 0;
    printf("\nPart 4:\nThe sum of all values in your array is: ");
    for (int i = 0; i < arrNum; i++)
        // Adds to the total each loop
        total += arr[i];
    printf("%d", total);
}

/**
 * This function will sort the array in terms of smallest to biggest elements, it will then print out the sorted
 * elements with their original array index's.
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part5(int *arr, int arrNum){
    printf("\nPart 5:\nYour array in sorted order is: ");
    // This will create a copy of the original array
    int sortedArr[arrNum];
    for (int i = 0; i < arrNum; i++)
        sortedArr[i] = arr[i];

    // This is a sorting algorithm that will sort out the array
    for (int i = 0; i < arrNum - 1; i++) {
        for (int j = i + 1; j < arrNum; j++) {
            // Checks if the index ahead is smaller, if true then they will swap positions
            if (sortedArr[i] > sortedArr[j]) {
                int temp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = temp;
            }
        }
    }

    // Creating another array
    int origIndex[arrNum];
    for (int i = 0; i < arrNum; i++) {
        origIndex[i] = i;
    }

    // This will track the original arrays index's in correspondence to the sorted arrays elements
    for (int i = 0; i < arrNum; i++) {
        for (int j = 0; j < arrNum; j++) {
            // Compares elements from original and sorted arrays and elements in origIndex
            if (sortedArr[i] == arr[j] && origIndex[i] > origIndex[j]) {
                int temp = origIndex[i];
                origIndex[i] = origIndex[j];
                origIndex[j] = temp;
            }
        }
    }

    // Prints out the sorted elements with original index's
    for (int i = 0; i < arrNum; i++) {
        printf(" [%d] = %d", origIndex[i], sortedArr[i]);
        // Checks if comma is placed
        if (i != arrNum - 1) {
            printf(",");
        }
    }
}

/**
 * This function will swap the beginning and end elements of the array. It will then print out the results
 * @param arr - The array the user has created
 * @param arrNum - The size of the array the user has created
 */
void part6(int *arr, int arrNum){
    printf("\nPart 6: \n");
    printf("Your array with first and last element switched is: ");
    // Put element at the end of array into temp variable
    int lastElement = arr[arrNum - 1];
    // Override last place element with first place element
    arr[arrNum - 1] = arr[0];
    // Override first place element with last place element
    arr[0] = lastElement;
    // Print out result
    for (int i = 0; i < arrNum; i++) {
        printf("[%d] =  %d", i, arr[i]);
        if (i < arrNum - 1) {
            printf(", ");
        }
    }
}

/**
 *
 */
int main() {
    int num;

    // Will continue looping until the if condition is satisfied
    while(1) {
        printf("Please enter the number of integers to process: ");
        scanf("%d", &num);
        // Input must be 5 (inclusive) and less than 12 (inclusive)
        if(num >= 5 && num <= 12){
            // If satisfied then break out of the while loop
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

    // Will go through all the functions listed above
    part1(arr, num);
    part2(arr, num);
    part3(arr,num);
    part4(arr, num);
    part5(arr, num);
    part6(arr, num);

    return 0;
}
