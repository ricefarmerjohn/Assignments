#include <stdio.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

void insert(){

}

void search(){

}

void update(){

}

void print(){

}

void erase(){

}

struct movie *movieMenu(struct movie *list){
    char input;

    while (input != 'q') {
        // Display menu
        printf("Please enter 1 of the 5 commands listed:\n"
               "[1] Press 'i' to insert a new movie\n"
               "[2] Press 'u' to update a movie within the database\n"
               "[3] Press 's' to search for a movie within the database\n"
               "[4] Press 'p' to list all of the recorded movies within the database\n"
               "[5] Press 'q' to exit out of the movie database\n");

        // Get user input for operation code
        printf("Enter operation code: ");
        scanf(" %c", &input);
        input = tolower(input);
        // Perform the selected operation based on the input
        switch (input) {
            case 'q':
                printf("Exiting the movie database.\n");
                break;
            case 'i':
                printf("Sorry idk what I'm doing");
                break;
            case 'p':
                printf("Sorry idk what I'm doing 2");
                break;
            case 'u':
                printf("Sorry idk what I'm doing 3");
                break;
            case 's':
                printf("Sorry idk what I'm doing 4");
                break;
            default:
                printf("Invalid operation code, please try again\n");
                break;
        }
    }
    return list;
}


