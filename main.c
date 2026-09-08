#include <stdio.h>
#include "dynamic_array.h"
#include "linked_list.h"

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

    printf("\nliste chainee :\n");

    LinkedList l;
    ll_init(&l);

    for (int i = 0; i < 5; i++)
        ll_insert_back(&l, i * 10);

    ll_insert_front(&l, 999);

    printf("size=%d\n", l.size);
    printf("get(0)=%d get(1)=%d get(5)=%d\n",
           ll_get(&l, 0), ll_get(&l, 1), ll_get(&l, 5));
    printf("find(30)=%d find(777)=%d\n", ll_find(&l, 30), ll_find(&l, 777));

    ll_remove_front(&l);
    printf("get(0)=%d size=%d\n", ll_get(&l, 0), l.size);

    ll_free(&l);
    return 0;
}