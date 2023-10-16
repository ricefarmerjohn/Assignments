#include <stdio.h>

int main() {
    int n1,n2,n3,n4, small1, small2, large1, large2, largest, smallest;
    printf("Enter four integers:  ");
    scanf(" %d %d %d %d", &n1,&n2,&n3,&n4);

    // This is to test out which of these are the smaller one
    if(n1 < n2){
        small1 = n1;
        large1 = n2;
    } else {
        // Simple else statement in case n1 is greater than n2
        large1 = n1;
        small1 = n2;
    }
    // Same thing over here, we're just seeing which one is the smaller and larger one
    if(n3 < n4){
        small2 = n3;
        large2 = n4;
    } else {
        large2 = n3;
        small2 = n4;
    }
    // Now we compare which one is the smallest
    if(small1 < small2){
        smallest = small1;
    } else {
        smallest = small2;
    }
    // We do the same over here to see which one is the largest one
    if(large1 < large2){
        largest = large2;
    } else {
        largest = large1;
    }
    // We use \n to make the line count a bit less
    printf("Largest: %d \n Smallest: %d", largest, smallest);
}
