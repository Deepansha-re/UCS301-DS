#include <iostream>
#include <algorithm>
using namespace std;

/* Implement the Binary search algorithm regarded as a fast search algorithm with
run-time complexity of Ο(log n) in comparison to the Linear Search. */

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)  // comparison, not assignment
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {65, 67, 89, 13, 98, 16, 54, 8, 80, 90, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 16;

    sort(arr, arr + size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Found target at index " << result;
    else
        cout << "Target not found";

    return 0;
}
