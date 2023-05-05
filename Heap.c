//
// Created by 93539 on 2023/5/5.
//

#include "Heap.h"


void HeapPrint(Heap php) {

}

void HeapInit(Heap *php) {
    assert(php);
    php->base = NULL;
    php->size = 0;
    php->capacity = 0;
}

void HeapDestroy(Heap *php) {

}

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = *p1;
}

void AdjustUp(HPDataType *arr, int child) {
    int parent = (child - 1) / 2;
    while (child > 0) {
        if (arr[child] < arr[parent]) {
            swap(&arr[child], &arr[parent]);
            child = parent;
            parent = (child - 1) / 2;
        } else {
            break;
        }
    }
}

void HeapPush(Heap *php, HPDataType value) {
    assert(php);
    if (php->size == php->capacity) {
        int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
        HPDataType *tmp = (HPDataType *) realloc(php->base, newCapacity * sizeof(HPDataType));
        if (tmp == NULL) {
            perror("realloc error");
            exit(-1);
        }
        php->base = tmp;
        php->capacity = newCapacity;
    }
    php->base[php->size] = value;
    ++php->size;
    AdjustUp(php->base, php->size - 1);
}

void AdjustDown(HPDataType *arr, int Heap_size, int parent) {
    int minChild = parent * 2 + 1;
    while (minChild < Heap_size) {
        if (minChild + 1 < Heap_size && arr[minChild + 1] < arr[minChild]) {
            ++minChild;
        }
        if (arr[parent] > arr[minChild]) {
            swap(&arr[parent], &arr[minChild]);
            parent = minChild;
            minChild = parent * 2 + 1;
        } else {
            break;
        }
    }
}

void HeapPop(Heap *php) {
    assert(php);
    assert(!HeapEmpty(*php));
    swap(&php->base[0], &php->base[php->size - 1]);
    --php->size;
    AdjustDown(php->base, php->size, 0);
}

bool HeapEmpty(Heap php) {
    return php.size == 0;
}

HPDataType HeapTop(Heap php) {
    assert(!HeapEmpty(php));
    return php.base[0];
}

int HeapSize(Heap php) {
    return php.size;
}