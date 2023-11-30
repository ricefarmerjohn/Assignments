#ifndef ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
#define ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H

struct movie *movieMenu(struct movie *list);
struct movie *search(struct movie *list, int code);
void insert(struct movie *list, int code);
void update(struct movie *list, int code);
void print(struct movie *list);
struct movie *delete(struct movie *list, int code);

#endif //ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
