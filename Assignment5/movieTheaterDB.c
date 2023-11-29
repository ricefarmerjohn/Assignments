#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

int main() {
    char input;

    // Display welcome message
    printf("*********************\n* 2211 Movie Cinema *\n*********************\nWelcome to the 2211 movie cinema\n");

    // Main loop for user interaction
    while (input != 'q') {
        // Display menu
        printf("Please enter 1 of the 4 commands listed:\n"
               "[1] Press 'h' to understand how to use the program\n"
               "[2] Press 'm' to control the movie database\n"
               "[3] Press 'a' to control the actor database\n"
               "[4] Press 'q' to exit out of the cinema\n");

        // Get user input for operation code
        printf("Enter operation code: ");
        scanf(" %c", &input);

        switch(input){

        }
    }
}