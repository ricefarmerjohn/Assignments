#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

// Function to check if a movie with the given code exists in the database
struct movie *movieCheck(struct movie *list, int code) {
    struct movie *p;
    // Loops through the entire list to check
    for (p = list; p != NULL; p = p->next) {
        if (p != NULL && code == p->movieCode) {
            return p;
        }
    }
    // Returns null if it's not in the list
    return NULL;
}

// Function to insert a new movie into the database
struct movie *movieInsert(struct movie *list) {
    float temp;
    struct movie *cur, *prev, *newNode;
    newNode = malloc(sizeof(struct movie));

    // Checks if the database is full
    if (newNode == NULL) {
        printf("Database is full; can't add more movies.\n");
        return list;
    }

    printf("Enter movie number: ");
    scanf("%d", &newNode->movieCode);
    // Loops through the database to check if the code exists
    for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next);
    if (cur != NULL && newNode->movieCode == cur->movieCode) {
        printf("Code already exists.\n");
        free(newNode);
        return list;
    }

    printf("Enter movie name: ");
    scanf(" %s", newNode->movieName);

    printf("Enter movie genre: ");
    scanf(" %s", newNode->movieGenre);

    printf("Enter movie rating [0.0 - 10.0]: ");
    scanf("%f", &temp);
    if (temp < 0.0 || temp > 10.0) {
        // If rating is not within the valid range, return without adding the movie
        printf("Invalid rating\n");
        return list;
    } else {
        newNode->movieRating = temp;
    }

    newNode->next = cur;
    if (prev == NULL) {
        list = newNode;
    } else {
        prev->next = newNode;
    }
    return list;
}

// Function to search for a movie in the database
void movieSearch(struct movie *list) {
    struct movie *node;
    int code;
    printf("Enter movie number: ");
    scanf("%d", &code);
    // Loops through the database to find the movie code
    for (node = list; node != NULL; node = node->next) {
        if (node->movieCode == code) {
            printf("Movie Code   Movie Name                 Movie Genre               Movie Rating\n");
            printf("%-12d %-26s %-25s %.1f\n", node->movieCode, node->movieName, node->movieGenre, node->movieRating);
            break;
        }
    }
    printf("Invalid movie code\n");
}

// Function to print all movies in the database
void moviePrint(struct movie *list) {
    struct movie *p;
    printf("Movie Code   Movie Name                 Movie Genre               Movie Rating\n");
    for (p = list; p != NULL; p = p->next) {
        // Prints out information in specific format
        printf("%-12d %-26s %-25s %.1f\n", p->movieCode, p->movieName, p->movieGenre, p->movieRating);
    }
}

// Function to update information for a movie in the database
void movieUpdate(struct movie *list) {
    float temp;
    int code;
    struct movie *p;
    printf("Enter the movie code: ");
    scanf("%d", &code);
    p = movieCheck(list, code);
    if (p != NULL) {
        printf("Enter the new movie name: ");
        scanf(" %s", p->movieName);

        printf("Enter the new movie genre: ");
        scanf(" %s", p->movieGenre);

        printf("Enter the new movie rating [0.0 - 10.0]: ");
        scanf("%f", &temp);
        if (temp < 0.0 || temp > 10.0) {
            // If rating is not within the valid range, return without updating the movie
            return;
        } else {
            p->movieRating = temp;
        }

    } else {
        printf("Movie code not found.\n");
    }
}

// Function to erase a movie from the database
struct movie *movieErase(struct movie *list) {
    struct movie *cur, *prev;
    int code;
    printf("Enter the movie code for the movie to be deleted: ");
    scanf("%d", &code);
    for (cur = list, prev = NULL; cur != NULL && cur->movieCode != code; prev = cur, cur = cur->next);

    if (cur == NULL) {
        return list;
    }
    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = cur->next;
        free(cur);
    }

    return list;
}

// Function to handle the movie database menu and operations
struct movie *movieMenu(struct movie *list) {
    char input;

    while (input != 'q') {
        // Display menu
        printf("Please enter 1 of the 5 commands listed:\n"
               "[1] Press 'i' to insert a new movie\n"
               "[2] Press 'u' to update a movie within the database\n"
               "[3] Press 's' to search for a movie within the database\n"
               "[4] Press 'p' to list all of the recorded movies within the database\n"
               "[5] Press 'e' to erase a movie out of the movie database\n"
               "[6] Press 'q' to exit out of the movie database\n");

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
                list = movieInsert(list);
                break;
            case 'p':
                moviePrint(list);
                break;
            case 'u':
                movieUpdate(list);
                break;
            case 's':
                movieSearch(list);
                break;
            case 'e':
                list = movieErase(list);
                break;
            default:
                printf("Invalid operation code\n");
                break;
        }
    }
    return list;
}
