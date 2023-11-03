#include <stdio.h>
#include <stdlib.h>

struct Heap{
    int *arr;
    int size;
    int capacity;
};

typedef struct Heap heap;

heap *createHeap(int arr[], int n);

void heapify(heap *h, int index,int size);

void heapsort(heap *h);

void print(heap *h);

heap *createHeap(int arr[],int n)
{
    heap *h = (heap *)malloc(sizeof(heap));

    if(h == NULL)
    printf("Memory error\n");

    h->arr = (int *)malloc(n*sizeof(int));

    if(h->arr == NULL)
    printf("Memory error\n");

    h->size = 0;
    h->capacity  = n;
    for(int i=0;i<n;i++)
    {
        h->arr[i] = arr[i];
        h->size++;
    }

    int i = (h->size-2)/2;
    while (i>=0)
    {
        heapify(h,i,h->size);
        i--;
    }
    
    return h;
}

void heapify(heap *h,int index,int size)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int min = index;

    if(left < 0 || left >= h->size)
    left = -1;

    if(right < 0 || right >= h->size)
    right = -1;

    if(left != -1 && h->arr[left] < h->arr[index])
    min = left;

    if(right != -1 && h->arr[right] < h->arr[min])
    min = right;

    if(min != index)
    {
        int temp = h->arr[min];
        h->arr[min] = h->arr[index];
        h->arr[index] = temp;

        heapify(h,min,size);
    }
}

void heapsort(heap *h)
{
    int n = h->size;
    for(int i=0;i<n;i++)
    {
        int temp = h->arr[0];
        h->arr[0] = h->arr[n-i-1];
        h->arr[n-i-1] = temp;
        heapify(h,0,h->size--);
    }
    print(h);
}

void print(heap *h)
{
    for(int i=0;i<h->capacity;i++)
    printf("%d ",h->arr[i]);

    printf("\n");
}
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements of array:");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    heap *hp = createHeap(arr,n);
    print(hp);

    heapsort(hp);
    print(hp);
    free(hp->arr);
    free(hp);
}
