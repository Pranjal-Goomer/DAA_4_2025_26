#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

int heap[MAX];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int val) {
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void deleteRoot() {
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int getMin() {
    return heap[0];
}

int main() {
    int K, N;
    cout << "Enter the value of k : " << endl;
    cin >> K;

    cout << "Enter the value of N : ";
    cin >> N;

    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    vector<int> result;

    for (int i = 0; i < N; i++) {
        int score = scores[i];

        if (heapSize < K) {
            insert(score);
        }
        else if (score > getMin()) {
            deleteRoot();
            insert(score);
        }

        if (heapSize < K) {
            result.push_back(-1);
        } else {
            result.push_back(getMin());
        }
    }

    cout << "The result is : " << endl;
    for (int x : result) {
        cout << x << endl;
    }

    return 0;
}
