#include <iostream>
using namespace std;

/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order. Code the Bubble sort with the
following elements:
64 34 25 12 22 11 90
*/

void BubbleSort(int arr[], int size) {
    for (int pass = 0; pass < size - 1; pass++) { // number of passes
        for (int i = 0; i < size - pass - 1; i++) { // inner loop
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    BubbleSort(arr, size);

    cin.ignore();
    cin.get();

    return 0;
}
