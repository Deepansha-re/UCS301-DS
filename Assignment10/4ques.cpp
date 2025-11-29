#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = 6;
    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == 1) {
            cout << arr[i];
            break;
        }
    }
    cin.ignore();
    cin.get();
}
