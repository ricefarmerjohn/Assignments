#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold both the element and its original index
struct IndexedElement {
    int element;
    int index;
};

// Comparison function for sorting the array of IndexedElement
int compareIndexedElements(const void *a, const void *b) {
    return ((struct IndexedElement *)a)->element - ((struct IndexedElement *)b)->element;
}

void printArrayWithOriginalIndex(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Original Index [%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int arr[] = {10, 99, 1, 31423, 55};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Create an array of IndexedElement to store elements and their original indices
    struct IndexedElement indexedArr[arrSize];
    for (int i = 0; i < arrSize; i++) {
        indexedArr[i].element = arr[i];
        indexedArr[i].index = i;
    }

    // Sort the indexedArr based on the element values
    qsort(indexedArr, arrSize, sizeof(struct IndexedElement), compareIndexedElements);

    printf("Sorted Array with Original Indices:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("Original Index [%d] = %d\n", indexedArr[i].index, indexedArr[i].element);
    }

    return 0;
}