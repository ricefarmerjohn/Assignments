#ifndef ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
#define ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H

struct movie *movieMenu(struct movie *list);
struct movie *check(struct movie *list, int code);
struct movie* insert(struct movie *list);
void search(struct movie *list);
void update(struct movie *list);
void print(struct movie *list);
struct movie *delete(struct movie *list, int code);

#endif //ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
