#include <stdlib.h>
#include "linked_list.h"

void ll_init(LinkedList *l) {
    l->head = NULL;
    l->size = 0;
}

void ll_insert_front(LinkedList *l, int value) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) return;
    n->value = value;
    n->next = l->head;
    l->head = n;
    l->size++;
}

void ll_insert_back(LinkedList *l, int value) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) return;
    n->value = value;
    n->next = NULL;

    if (l->head == NULL) {
        l->head = n;
    } else {
        Node *cur = l->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = n;
    }
    l->size++;
}

int ll_get(LinkedList *l, int index) {
    if (index < 0 || index >= l->size) return -1;
    Node *cur = l->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->value;
}

int ll_find(LinkedList *l, int value) {
    Node *cur = l->head;
    int i = 0;
    while (cur != NULL) {
        if (cur->value == value) return i;
        cur = cur->next;
        i++;
    }
    return -1;
}

void ll_remove_front(LinkedList *l) {
    if (l->head == NULL) return;
    Node *old = l->head;
    l->head = old->next;
    free(old);
    l->size--;
}

void ll_free(LinkedList *l) {
    Node *cur = l->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    l->head = NULL;
    l->size = 0;
}