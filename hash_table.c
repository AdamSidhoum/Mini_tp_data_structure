#include <stdlib.h>
#include "hash_table.h"

int hash_good(int value) {
    return (int)((unsigned int)value % TABLE_SIZE);
}

int hash_bad(int value) {
    (void)value;
    return 0;
}

void hash_init(HashTable *t) {
    for (int i = 0; i < TABLE_SIZE; i++)
        t->buckets[i] = NULL;
}

void hash_insert(HashTable *t, int value) {
    int idx = hash_good(value);
    Entry *e = malloc(sizeof(Entry));
    if (e == NULL) return;
    e->value = value;
    e->next = t->buckets[idx];
    t->buckets[idx] = e;
}

int hash_contains(HashTable *t, int value) {
    int idx = hash_good(value);
    Entry *cur = t->buckets[idx];
    while (cur != NULL) {
        if (cur->value == value) return 1;
        cur = cur->next;
    }
    return 0;
}

void hash_free(HashTable *t) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *cur = t->buckets[i];
        while (cur != NULL) {
            Entry *next = cur->next;
            free(cur);
            cur = next;
        }
        t->buckets[i] = NULL;
    }
}