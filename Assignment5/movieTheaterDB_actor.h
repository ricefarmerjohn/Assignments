#ifndef ASSIGNMENT5_MOVIETHEATERDB_ACTOR_H
#define ASSIGNMENT5_MOVIETHEATERDB_ACTOR_H

// Function declarations for actor database operations
struct actor *actorMenu(struct actor *list);
struct actor *actorCheck(struct actor *list, int code);
struct actor *actorInsert(struct actor *list);
struct actor *actorErase(struct actor *list);
void actorSearch(struct actor *list);
void actorUpdate(struct actor *list);
void actorPrint(struct actor *list);

#endif //ASSIGNMENT5_MOVIETHEATERDB_ACTOR_H
