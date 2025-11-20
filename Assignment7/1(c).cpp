#include <iostream>
using namespace std;

// ---------------- BUBBLE SORT ----------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);

    cin.ignore();
    cin.get();
    
    return 0;
}