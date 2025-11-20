#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i, bool maxHeap) {
    int extreme = i;     
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (maxHeap) {
        if (l < n && a[l] > a[extreme]) extreme = l;
        if (r < n && a[r] > a[extreme]) extreme = r;
    } else {
        if (l < n && a[l] < a[extreme]) extreme = l;
        if (r < n && a[r] < a[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(a[i], a[extreme]);
        heapify(a, n, extreme, maxHeap);
    }
}

void heapSort(vector<int> a, bool increasing) {
    bool maxHeap = increasing;  

    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, maxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, maxHeap);
    }

    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};

    cout << "Increasing: ";
    heapSort(a, true);

    cout << "Decreasing: ";
    heapSort(a, false);

    cin.ignore();
    cin.get();
    return 0;
}
