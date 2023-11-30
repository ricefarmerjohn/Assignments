#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"
// Works

struct movie *check(struct movie *list, int code){
    struct movie *p;

    for(p = list; p != NULL && code > p->movieCode; p = p->next){
        if(p != NULL && code == p->movieCode){
            return p;
        }
    }
    return NULL;
}

struct movie* insert(struct movie *list){
    float temp;
    struct movie *cur, *prev, *newNode;
    newNode = malloc(sizeof(struct movie));
    if (newNode == NULL) {
        printf("Database is full; can't add more movies.\n");
        return list;
    }
    printf("Enter movie number: ");
    scanf("%d", &newNode->movieCode);

    for (cur = list, prev = NULL; cur != NULL && newNode->movieCode > cur->movieCode; prev = cur, cur = cur->next);
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
        return list;
    } else {
        newNode->movieRating = temp;
    }

    newNode->next = cur;
    if (prev == NULL) {
        list = newNode;
    }else {
        prev->next = newNode;
    }
    return list;
}

// Works :3
void search(struct movie *list){
    struct movie *node;
    int code;
    printf("Enter movie number: ");
    scanf("%d", &code);
    for (node = list; node != NULL; node = node->next) {
        if (node->movieCode == code) {
            printf("%-12d %-26s %-25s %.1f\n", node->movieCode, node->movieName, node->movieGenre, node->movieRating);
        }
    }
    printf("Invalid movie code");
}

// 99% sure this is done
void print(struct movie *list) {
    struct movie *p;
    printf("Movie Code   Movie Name                 Movie Genre               Movie Rating\n");
    for (p = list; p != NULL; p = p->next) {
        printf("%-12d %-26s %-25s %.1f\n", p->movieCode, p->movieName, p->movieGenre, p->movieRating);
    }
}

void update(struct movie *list){
    float temp;
    int code;
    struct movie *p;
    printf("Enter the movie code: ");
    scanf("%d", &code);
    p = check(list,code);
    if (p != NULL) {
        printf("Enter a new movie code: ");
        scanf("d", &code);

        printf("Enter movie name: ");
        scanf(" %s", p->movieName);

        printf("Enter movie genre: ");
        scanf(" %s", p->movieGenre);

        printf("Enter movie rating [0.0 - 10.0]: ");
        scanf("%f", &temp);
        if (temp < 0.0 || temp > 10.0) {
            // If rating is not within the valid range, return without adding the movie
            return;
        } else {
            p->movieRating = temp;
        }

    } else
        printf("Movie code not found.\n");
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
                list = insert(list);
                break;
            case 'p':
                print(list);
                break;
            case 'u':
                update(list);
                break;
            case 's':
                search(list);
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


