#include "Heap.h"

int main() {
    Heap myHeap;
    HeapInit(&myHeap);

    int a[] = {65, 100, 70, 32, 50, 60};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        HeapPush(&myHeap, a[i]);
    }

    return 0;
}
