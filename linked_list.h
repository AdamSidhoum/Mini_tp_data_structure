#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

void ll_init(LinkedList *l);
void ll_insert_front(LinkedList *l, int value);
void ll_insert_back(LinkedList *l, int value);
int  ll_get(LinkedList *l, int index);
int  ll_find(LinkedList *l, int value);
void ll_remove_front(LinkedList *l);
void ll_free(LinkedList *l);

#endif