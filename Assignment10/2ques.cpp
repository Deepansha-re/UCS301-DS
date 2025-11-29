#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n = 4, m = 4;

    unordered_set<int> s(A, A + n);

    for(int i = 0; i < m; i++) {
        if(s.find(B[i]) != s.end()) {
            cout << B[i] << " ";
        }
    }
    cin.ignore();
    cin.get()
}
