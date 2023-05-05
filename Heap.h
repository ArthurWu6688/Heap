//
// Created by 93539 on 2023/5/5.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap{
    HPDataType *base;
    int size;
    int capacity;
}Heap;

void HeapPrint(Heap php);
void HeapInit(Heap *php);
void HeapDestroy(Heap *php);
void HeapPush(Heap *php, HPDataType value);
void HeapPop(Heap *php);
bool HeapEmpty(Heap php);
HPDataType HeapTop(Heap php);
int HeapSize(Heap php);
void AdjustUp(HPDataType *arr, int child);
void AdjustDown(HPDataType *arr, int Heap_size, int parent);
void swap(int *p1, int *p2);

#endif //HEAP_HEAP_H
