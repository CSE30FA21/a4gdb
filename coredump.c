/**
 * Assigment GDB
 * Name: TODO
 * PID:  TODO
 * Class: UCSD CSE30-SP20
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * This is a struct that contains two pieces of data. A struct is simply a
 * container that groups related data together. Here we define a new data type
 * called rec_t.
 */
typedef struct  rec {
  char *name;              // a name
  struct rec *fwd;         // pointer to the next record

} rec_t;

/**
 * Add a string to the list - returns a pointer to the new tail.
 * Add a string to the list. Tail is a pointer to the end of the list
 * and *something is a pointer to the string you want to add.
 * This function returns a pointer to the new record which becomes
 * the new tail.
 */
rec_t *addToList(rec_t *tail, char *something){
  rec_t *newRec;
  newRec = malloc(sizeof(rec_t));
  newRec->name = something;
  tail->fwd = newRec;
  newRec->fwd = NULL;
  return newRec;
}

/**
 * Print the list starting at curPt
 *
 * This function prints the list starting at curPt.
 * It returns nothing.
 */
void printListFwd(rec_t *curPt){
  while (curPt != NULL){
    printf("%s\n", curPt->name);
    curPt = curPt->fwd;
  }
}

/**
 * Sample program that has a bug.
 *
 * We create a linked list. The head of the list is pointed to by head. The
 * first entry in the list is a dummy entry so that an empty list always has
 * this dummy entry.
 */
int main(int argc, char **argv){
  rec_t *head;
  rec_t *tail;

  head = tail = malloc(sizeof(rec_t));
  head->fwd = NULL;
  tail = addToList(tail, "Jabba");
  tail = addToList(tail, "Vader");
  tail = addToList(tail, "Endor");

  printListFwd(head);
}
