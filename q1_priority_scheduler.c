#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into heap
void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;

    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

// Heapify
void heapify(int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Extract max
int extractMax() {
    if (size == 0) return -1;

    int max = heap[1];
    heap[1] = heap[size];
    size--;

    heapify(1);

    return max;
}

int main() {
    insert(10);
    insert(30);
    insert(20);

    printf("Extracted Max: %d\n", extractMax());
    printf("Extracted Max: %d\n", extractMax());

    return 0;
}

// Max Heap is better in Time complexity as compared to Sorted Tree Because if more number or elements are greater or lesser than the root it will form the skewed tree which will Make the Time Complexity T(n)=O(n)