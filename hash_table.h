#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10007

typedef struct Entry {
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

int  hash_good(int value);
int  hash_bad(int value);

void hash_init(HashTable *t);
void hash_insert(HashTable *t, int value);
int  hash_contains(HashTable *t, int value);
void hash_free(HashTable *t);

#endif