#include "Heap.h"
#include <time.h>
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

#if 0
//������������
void HeapSort(int *arr, int n) {
    //����--���ϵ���--O(N*logN)
//    for(int i = 1; i < n; ++i){
//        AdjustUp(arr, i);
//    }
//    for(int i = 1; i < n; ++i){
//        swap(&arr[0], &arr[n - i]);
//        AdjustDown(arr, n - i, 0);
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
#endif

void CreatDataFile(const char* filename, int N){
    FILE *fin = fopen(filename, "w");
    if (fin == NULL) {
        perror("fopen error");
        return;
    }
    srand(time(0));
    for(int i = 0; i < N; ++i){
        fprintf(fin, "%d ", rand()%10);
    }

    fclose(fin);
}

void PrintTopK(const char *filename, int k) {
    assert(filename);

    FILE *fout = fopen(filename, "r");
    if (fout == NULL) {
        perror("fopen error");
        return;
    }

    int *minHeap = (int *) malloc(sizeof(int) * k);
    if (minHeap == NULL) {
        perror("malloc error");
        return;
    }
    ///��ζ�ȡǰ k ������
    for (int i = 0; i < k; ++i) {
        fscanf(fout, "%d", &minHeap[i]);
    }

    ///��k������С��
    for (int j = k - 2 / 2; j >= 0; --j) {
        AdjustDown(minHeap, k, j);
    }

    ///��ζ�ȡ n - k
    int val = 0;
    while (fscanf(fout, "%d", &val) != EOF) {
        if (val > minHeap[0]) {
            minHeap[0] = val;
            AdjustDown(minHeap, k, 0);
        }
    }

    for(int i = 0; i < k; ++i){
        printf("%d ",minHeap[i]);
    }

    free(minHeap);
    fclose(fout);
}

int main() {
    const char *filename = "data.txt";

    int N = 10000;
    int k = 5;
    //CreatDataFile(filename,N);
    PrintTopK(filename, k);

    return 0;
}