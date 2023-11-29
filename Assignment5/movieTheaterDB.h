#ifndef MOVIETHEATERDB_H
#define MOVIETHEATERDB_H

#define MAX_LENGTH 101

// Creating a single node (not the list yet)
struct movie {
    int code;
    char name;

    struct movie *next;
};
#endif
