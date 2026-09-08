#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

void da_init(DynamicArray *a) {
    a->data = NULL;
    a->size = 0;
    a->capacity = 0;
}

static void da_grow(DynamicArray *a) {
    if (a->size < a->capacity) return;
    int new_cap = (a->capacity == 0) ? 4 : a->capacity * 2;
    int *tmp = realloc(a->data, new_cap * sizeof(int));
    if (tmp == NULL) return;
    a->data = tmp;
    a->capacity = new_cap;
}

void da_insert_back(DynamicArray *a, int value) {
    da_grow(a);
    a->data[a->size] = value;
    a->size++;
}

void da_insert_front(DynamicArray *a, int value) {
    da_grow(a);
    memmove(a->data + 1, a->data, a->size * sizeof(int));
    a->data[0] = value;
    a->size++;
}

int da_get(DynamicArray *a, int index) {
    if (index < 0 || index >= a->size) return -1;
    return a->data[index];
}

int da_find(DynamicArray *a, int value) {
    for (int i = 0; i < a->size; i++)
        if (a->data[i] == value) return i;
    return -1;
}

void da_remove_front(DynamicArray *a) {
    if (a->size == 0) return;
    memmove(a->data, a->data + 1, (a->size - 1) * sizeof(int));
    a->size--;
}

void da_free(DynamicArray *a) {
    free(a->data);
    a->data = NULL;
    a->size = 0;
    a->capacity = 0;
}