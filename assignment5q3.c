#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Heap {
    int *arr;
    int size;
    int capacity;
};

typedef struct Heap heap;

heap *createHeap(int capacity);
void heapify(heap *h, int index);
int deleteMax(heap *h);
void insert(heap *h, int key);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

heap *createHeap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->arr = (int *)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapify(heap *h, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int minmax = index;

    if (left < h->size && h->arr[left] > h->arr[minmax])
        minmax = left;

    if (right < h->size && h->arr[right] > h->arr[minmax])
        minmax = right;

    if (minmax != index) {
        swap(&(h->arr[index]), &(h->arr[minmax]));
        heapify(h, minmax);
    }
}

int deleteMax(heap *h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        return INT_MIN; 
    }

    int max = h->arr[0];
    int last = h->arr[h->size - 1];
    h->size--;
    h->arr[0] = last;

    int minmaxLevel = 0; 
    while ((1 << minmaxLevel) <= h->size)
        minmaxLevel++;

    minmaxLevel--;

    if (minmaxLevel % 2 == 0) {
        heapify(h, 0);
    } else {
        int parent = (h->size - 2) / 2;
        if (h->arr[0] < h->arr[parent]) {

            swap(&(h->arr[0]), &(h->arr[parent]));
            heapify(h, parent);
        }
    }

    return max;
}

void insert(heap *h, int key) {
    if (h->size >= h->capacity) {
        printf("Heap is full\n");
        return;
    }

    h->arr[h->size] = key;
    h->size++;

    int index = h->size - 1;
    int parent = (index - 1) / 2;

    if (index % 2 == 0) {
        while (index > 0 && h->arr[index] < h->arr[parent]) {
            swap(&(h->arr[index]), &(h->arr[parent]));
            index = parent;
            parent = (index - 1) / 2;
        }
    } else {
        while (index > 0 && h->arr[index] > h->arr[parent]) {
            swap(&(h->arr[index]), &(h->arr[parent]));
            index = parent;
            parent = (index - 1) / 2;
        }
    }
}

int main() {
    int capacity;
    printf("Enter the capacity of the min-max heap: ");
    scanf("%d", &capacity);

    heap *h = createHeap(capacity);

    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements to insert:\n", n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(h, key);
    }

    printf("Min-max heap elements: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");

    int max = deleteMax(h);
    printf("Deleted maximum element: %d\n", max);

    printf("Min-max heap elements after deletion: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");

    free(h->arr);
    free(h);

    return 0;
}