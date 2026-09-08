#include <stdio.h>
#include "dynamic_array.h"

int main(void) {
    DynamicArray a;
    da_init(&a);

    for (int i = 0; i < 10; i++)
        da_insert_back(&a, i * 10);

    printf("size=%d capacity=%d\n", a.size, a.capacity);

    da_insert_front(&a, 999);
    printf("get(0)=%d get(1)=%d\n", da_get(&a, 0), da_get(&a, 1));
    printf("find(50)=%d find(777)=%d\n", da_find(&a, 50), da_find(&a, 777));

    da_remove_front(&a);
    printf("get(0)=%d size=%d\n", da_get(&a, 0), a.size);

    da_free(&a);
    return 0;
}