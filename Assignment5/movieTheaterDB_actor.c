#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_actor.h"

// Function to check if a actor with the given code exists in the database
struct actor *actorCheck(struct actor *list, int code){
    struct actor *p;
    // Loops through the entire list to check
    for(p = list; p != NULL; p = p->next){
        if(p != NULL && code == p->actorCode){
            return p;
        }
    }
    // Returns null if it's not in the list
    return NULL;
}

// Function to insert a new actor into the database
struct actor *actorInsert(struct actor *list){
    int temp;
    char tempc;
    struct actor *cur, *prev, *newNode;
    newNode = malloc(sizeof(struct actor));

    // Checks if the database is full
    if (newNode == NULL) {
        printf("Database is full; can't add more actors.\n");
        return list;
    }

    printf("Enter the actor's code: ");
    scanf("%d", &newNode->actorCode);
    // Loops through the database to check if the code exists
    for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next);
    if (cur != NULL && newNode->actorCode == cur->actorCode) {
        printf("Actor already exists.\n");
        free(newNode);
        return list;
    }

    printf("Enter actor name: ");
    scanf("%s", &tempc);
    fgets(newNode->actorName, MAX_ACTOR_LENGTH, stdin);
    size_t len = strlen(newNode->actorName);
        if (len > 0 && newNode->actorName[len - 1] == '\n')
            newNode->actorName[len - 1] = '\0';

    printf("Enter actor age (0 - 120): ");
    scanf("%d%*c", &temp);
    // If age is not within the valid range, return without adding the actor
    if(temp < 0 || temp > 120){
        printf("Invalid actor age\n");
        free(newNode);
        return list;
    } else {
        newNode->actorAge = temp;
    }

    printf("Enter the actor's IMDB profile page: ");
    scanf(" %s", newNode->IMDB);

    newNode->next = cur;
    if (prev == NULL) {
        list = newNode;
    }else {
        prev->next = newNode;
    }
    return list;
}

// Function to search for an actor in the database
void actorSearch(struct actor *list){
    struct actor *node;
    int code;
    printf("Enter actor number: ");
    scanf("%d", &code);

    // Loops through the database to find the actor code
    for (node = list; node != NULL; node = node->next) {
        if (node->actorCode == code) {
            printf("Actor Code   Actor Name                 Actor Age               IMDB Profile Page\n");
            printf("%-12d %-26s %-25d %s\n", node->actorCode, node->actorName, node->actorAge, node->IMDB);
            break;
        }
    }
    printf("Invalid actor code\n");
}

// Function to print all actors in the database
void actorPrint(struct actor *list) {
    struct actor *p;
    printf("Actor Code   Actor Name                 Actor Age               IMDB Profile Page\n");
    for (p = list; p != NULL; p = p->next) {
        printf("%-12d %-26s %-25d %s\n", p->actorCode, p->actorName, p->actorAge, p->IMDB);
    }
}

// Function to update information for an actor in the database
void actorUpdate(struct actor *list){
    char tempc;
    int code, temp;
    struct actor *p;
    printf("Enter the actor code: ");
    scanf("%d", &code);
    p = actorCheck(list,code);
    if (p != NULL) {
        printf("Enter actor name: ");
        scanf("%s", &tempc);
        fgets(p->actorName, MAX_ACTOR_LENGTH, stdin);
    size_t len = strlen(p->actorName);
            if (len > 0 && p->actorName[len - 1] == '\n')
                p->actorName[len - 1] = '\0';

        printf("Enter actor age (0 - 120): ");
        scanf(" %d", &temp);
        if(temp < 0 || temp > 120){
            printf("Invalid actor age, please try again");
        } else {
            p->actorAge = temp;
        }

        printf("Enter the actor's IMDB profile page: ");
        scanf(" %s", p->IMDB);

    } else {
        printf("Actor code not found.\n");
    }
}

// Function to erase an actor from the database
struct actor *actorErase(struct actor *list){
    struct actor *cur, *prev;
    int code;
    printf("Enter the actor code for the actor to be deleted: ");
    scanf("%d", &code);
    for (cur = list, prev = NULL; cur != NULL && cur->actorCode != code; prev = cur, cur = cur->next);

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

struct actor *actorMenu(struct actor *list){
    char input;

    while (input != 'q') {
        // Display menu
        printf("Please enter 1 of the 5 commands listed:\n"
               "[1] Press 'i' to insert a new actor\n"
               "[2] Press 'u' to update an actor's info within the database\n"
               "[3] Press 's' to search for an actor within the database\n"
               "[4] Press 'p' to list all of the recorded actors within the database\n"
               "[5] Press 'e' to erase an actor out of the actor database\n"
               "[6] Press 'q' to exit out of the actor database\n");

        // Get user input for operation code
        printf("Enter operation code: ");
        scanf(" %c", &input);
        input = tolower(input);
        // Perform the selected operation based on the input
        switch (input) {
            case 'q':
                printf("Exiting the actor database.\n");
                break;
            case 'i':
                list = actorInsert(list);
                break;
            case 'p':
                actorPrint(list);
                break;
            case 'u':
                actorUpdate(list);
                break;
            case 's':
                actorSearch(list);
                break;
            case 'e':
                list = actorErase(list);
                break;
            default:
                printf("Invalid operation code\n");
                break;
        }
    }
    return list;
}



