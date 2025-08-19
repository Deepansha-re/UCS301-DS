#include<iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int n=0;

void reverseArray(){
    cout << "enter number of elements: ";
    cin >> n;
    if(n>MAX){
        cout << "Exceeds maximum size. Try again.\n";
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    reverseArray();
    cin.ignore();
    cin.get();
    return 0;
}