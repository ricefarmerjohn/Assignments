#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

void insert(struct movie *list, int n){
    float temp;
    struct movie *cur, *prev, *newNode;
    newNode = malloc(sizeof(struct movie));
    if (newNode == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter movie number: ");
    scanf("%d", &newNode->movieCode);

    for (cur = list, prev = NULL; cur != NULL && newNode->movieCode > cur->movieCode; prev = cur, cur = cur->next);
        if (cur != NULL && newNode->movieCode == cur->movieCode) {
            printf("Code already exists.\n");
            free(newNode);
            return;
    }

    printf("Enter movie name: ");
    scanf(" %s", newNode->movieName);

    printf("Enter movie genre: ");
    scanf(" %s", newNode->movieGenre);

    printf("Enter movie rating [0.0 - 10.0]: ");
    scanf("%f", &temp);
    if (temp < 0.0 || temp > 10.0) {
        // If rating is not within the valid range, return without adding the movie
        return;
    } else {
        newNode->movieRating = temp;
    }

    newNode->next = cur;
    if (prev == NULL) {
        list = newNode;
    }else {
        prev->next = newNode;
    }
}

struct movie *search_list(struct movie *list, int code){
    struct movie *p;
    for (p = list; p != NULL; p = p->next)
        if (p->movieCode == code)
            return p;
    return NULL;
}

// 99% sure this is done
void print(struct movie *list) {
    struct movie *p;
    printf("Movie Code   Movie Name                 Movie Genre               Movie Rating\n");
    for (p = list; p != NULL; p = p->next) {
        printf("%-12d %-26s %-25s %.1f\n", p->movieCode, p->movieName, p->movieGenre, p->movieRating);
    }
}

void update(struct movie *list, int code){

}

struct movie *delete(struct movie *list, int code){
    struct movie *cur, *prev;
    for (cur = list, prev = NULL;
         cur != NULL && cur->movieCode != code;
         prev = cur, cur = cur->next)
        ;
    if (cur == NULL)
        return list; /* n was not found */
    if (prev == NULL)
        list = list->next; /* n is in the first node */
    else
        prev->next = cur->next; /* n is in some other node */
    free(cur);
    return list;
}

struct movie *movieMenu(struct movie *list){
    int count = 0;
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
                insert(list,count);
                break;
            case 'p':
                print(list);
                break;
            case 'u':
                printf("Sorry idk what I'm doing 3");
                break;
            case 's':
                printf("Sorry idk what I'm doing 4");
                break;
            case 'e':
                break;
            default:
                printf("Invalid operation code, please try again\n");
                break;
        }
    }
    return list;
}


