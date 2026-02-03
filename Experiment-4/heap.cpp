#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if(right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int val) {
    if(heapSize == MAX) {
        cout << "Heap Full\n";
        return;
    }
    heap[heapSize++] = val;
    heapifyUp(heapSize - 1);
}

int searchElement(int val) {
    for(int i = 0; i < heapSize; i++)
        if(heap[i] == val)
            return i;
    return -1;
}

void deleteElement(int val) {
    int index = searchElement(val);

    if(index == -1) {
        cout << "Element not found\n";
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;

    int parent = (index - 1) / 2;
    if(index > 0 && heap[index] < heap[parent])
        heapifyUp(index);
    else
        heapifyDown(index);
}

void printHeap() {
    for(int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    insert(3);
    insert(12);
    insert(9);
    insert(2);
    insert(15);
    
    cout << "Before deleting the element" << endl;
    printHeap();
    cout << endl;

    cout << "Searching for the element to be deleted: " << endl;
    int idx = searchElement(9);
    if (idx != -1)
        cout << "Element 9 found at index: " << idx << endl;
    else
        cout << "Element 9 not found" << endl;

    deleteElement(9);

    cout << endl << "After deleting the element" << endl;
    printHeap();
}
