#include<iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int n=0;

void duplicate_element() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Exceeds maximum size. Try again.\n";
        return;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n) {
            if (arr[j] == arr[i]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // shrink size
            } else {
                j++; // only move forward if no deletion
            }
        }
    }

    cout << "Array after deleting duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    duplicate_element();
    cin.ignore();
    cin.get();
    return 0;
}
