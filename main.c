#include "Heap.h"

#if 0
//��ʵ�ֵĴ������
int main() {
    Heap myHeap;
    HeapInit(&myHeap);

    int a[] = {65, 100, 70, 32, 50, 60};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        HeapPush(&myHeap, a[i]);
    }
    HeapPrint(myHeap);

    HeapPop(&myHeap);
    HeapPrint(myHeap);

    printf("top:%d\n", HeapTop(myHeap));
    printf("size:%d\n", HeapSize(myHeap));

    HeapDestroy(&myHeap);

    return 0;
}
#endif

void HeapSort(int *arr, int n) {
    //����--���ϵ���--O(N*logN)
//    for(int i = 1; i < n; ++i){
//        AdjustUp(arr, i);
//    }

    // ��˼·��ѡ����������ѡ�����Ӻ���ǰ��
    // ���� -- ���
    // ���� -- С��
    //����--���µ���--O(LogN)
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(arr, n, i);
    }

    //ѡ��
//    int i = 1;
//    while (i < n) {
//        swap(&arr[0], &arr[n - i]);
//        AdjustDown(arr, n - i, 0);
//        ++i;
//    }
    for (int i = 1; i < n; ++i){
        swap(&arr[0], &arr[n - i]);
        AdjustDown(arr, n - i, 0);
    }
}


int main() {
    int a[] = {15, 1, 19, 25, 8, 34, 65, 4, 27, 7};
    HeapSort(a, sizeof(a) / sizeof(a[0]));

    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}