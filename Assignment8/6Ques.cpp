#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    bool maxHeap;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if ((maxHeap && heap[i] > heap[p]) ||
                (!maxHeap && heap[i] < heap[p])) {
                swap(heap[i], heap[p]);
                i = p;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i + 1, r = 2*i + 2;
            int extreme = i;

            if (maxHeap) {
                if (l < n && heap[l] > heap[extreme]) extreme = l;
                if (r < n && heap[r] > heap[extreme]) extreme = r;
            } else {
                if (l < n && heap[l] < heap[extreme]) extreme = l;
                if (r < n && heap[r] < heap[extreme]) extreme = r;
            }

            if (extreme != i) {
                swap(heap[i], heap[extreme]);
                i = extreme;
            } else break;
        }
    }

public:
    PriorityQueue(bool maxHeap = true) : maxHeap(maxHeap) {}

    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq(true);  // max-heap

    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cin.ignore();
    cin.get();
}
