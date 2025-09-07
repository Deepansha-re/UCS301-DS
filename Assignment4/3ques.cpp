#include<iostream>
using namespace std;

#define MAX 100
int que[MAX];
int que2[MAX];

void interleave(){
    // n can even only
    int n;
    cout << "Enter the even length of Queue starting from 1: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter the number to fill in Queue at " << i << " index : ";
        cin >> que[i];
    }
    cout << "Queue given: \n";
    for(int i=0; i<n; i++){
        cout << que[i] << " ";
    }
    cout << "\n";

    int mid = n/2;
    int index = 0;
    for(int i=0; i<mid; i++){
        que2[index++] = que[i];       // take from first half
        que2[index++] = que[i + mid]; // take from second half
    }
    cout << "Interleaved Queue: ";
    for(int i=0; i<n; i++){
        cout << que2[i] << " ";
    }
    cout << "\n";
}

int main(){
    interleave();
    cin.ignore();
    cin.get();
    return 0;
}