#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void da_init(DynamicArray *a);
void da_insert_back(DynamicArray *a, int value);
void da_insert_front(DynamicArray *a, int value);
int  da_get(DynamicArray *a, int index);
int  da_find(DynamicArray *a, int value);
void da_remove_front(DynamicArray *a);
void da_free(DynamicArray *a);

#endif