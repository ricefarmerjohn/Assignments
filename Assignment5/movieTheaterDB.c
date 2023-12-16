#include <stdio.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"

/**
 * Name of Program: Movie Theatre Database
 * Purpose: This program allows the user to manage both a movie and actor database by inserting, updating, searching, erasing, and listing movies.
 * Author: Keefe Feng [kfeng62]
 * Student ID: 251300600
 * Date: Nov 30th, 2023
 */

int main() {
    // Initialize movie and actor lists
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
        
        // Switch based on user input
        switch (input) {
            case 'q':
                printf("Exiting the cinema, hope you enjoyed your stay.\n");
                break;
            case 'h':
                // Display help message
                printf("Is this your first time in the 2211 movie cinema? Worry no more" 
                       " because using this program is as easy as breathing air!\n"
                       " [1] Press 'h' is the command you currently used and it will help you understand how to use the program\n"
                       " [2] Press 'm' to look into the movie database, this will allow you to insert, search, update, and erase the movies within that database.\n"
                       " [3] Press 'a' to look into the actor database, this will allow you to insert, search, update, and erase the actors within that database.\n"
                       " [4] Press 'q' to exit out of the cinema (which will erase all your data)\n");
                break;
            case 'a':
                // Call actorMenu function to handle actor database operations
                actorList = actorMenu(actorList);
                break;
            case 'm':
                // Call movieMenu function to handle movie database operations
                movieList = movieMenu(movieList); 
                break;
            default:
                // Display error for invalid input
                printf("Invalid operation code, please try again!\n");
                break;
        }
    }
    return 0;
}
