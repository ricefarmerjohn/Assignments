#ifndef MOVIETHEATERDB_H
#define MOVIETHEATERDB_H

// Maximum lengths for movie name, genre, and actor name
#define MOVNAME_LENGTH 100
#define MOVGENRE_LENGTH 25
#define MAX_ACTOR_LENGTH 50

// Structure representing a movie in the database
struct movie {
    int movieCode;                  // Unique identifier for the movie
    char movieName[MOVNAME_LENGTH + 1];    // Name of the movie
    char movieGenre[MOVGENRE_LENGTH + 1];  // Genre of the movie
    float movieRating;              // Rating of the movie
    struct movie *next;             // Pointer to the next movie in the linked list
};

// Structure representing an actor in the database
struct actor {
    int actorCode;                  // Unique identifier for the actor
    char actorName[MAX_ACTOR_LENGTH + 1];  // Name of the actor
    int actorAge;                   // Age of the actor
    char IMDB[MAX_ACTOR_LENGTH + 1];       // IMDB profile or similar information
    struct actor *next;             // Pointer to the next actor in the linked list
};

#endif
