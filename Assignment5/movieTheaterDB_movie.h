#ifndef ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
#define ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H

// Function declarations for movie database operations
struct movie *movieMenu(struct movie *list);
struct movie *movieCheck(struct movie *list, int code);
struct movie *movieInsert(struct movie *list);
struct movie *movieErase(struct movie *list);
void movieSearch(struct movie *list);
void movieUpdate(struct movie *list);
void moviePrint(struct movie *list);

#endif //ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H

