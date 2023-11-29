#ifndef MOVIETHEATERDB_H
#define MOVIETHEATERDB_H

#define MOVNAME_LENGTH 100
#define MOVGENRE_LENGTH 25
#define MAX_ACTOR_LENGTH 50

// Creating a single node (not the list yet)
struct movie {
    int movieCode;
    char movieName[MOVNAME_LENGTH + 1];
    char movieGenre[MOVGENRE_LENGTH + 1];
    float movieRating;
    struct movie *next;
};

struct actor {
    int actorCode;
    char actorName[MAX_ACTOR_LENGTH + 1];
    int actorAge;
    char IMDB[MAX_ACTOR_LENGTH + 1];
    struct actor *next;
};

#endif
