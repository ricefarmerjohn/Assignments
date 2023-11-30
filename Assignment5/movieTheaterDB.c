#include <stdio.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

int main() {
    struct movie* movieList = NULL;
    struct actor* actorList = NULL;

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
        input = tolower(input);
        switch (input) {
            case 'q':
                printf("Exiting the cinema, hope you enjoyed your stay.\n");
                break;
            case 'h':
                printf("Hello");
                break;
            case 'a':
                printf("Almost");
                break;
            case 'm':
                movieList = movieMenu(movieList); // Override that bitch
                break;
            default:
                printf("Invalid operation code, please try again.\n");
                break;
        }
    }
    return 0;
}