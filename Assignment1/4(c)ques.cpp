#include<iostream>
using namespace std;

#define MAX 10
void transpose(){
    int A[MAX][MAX], B[MAX][MAX];
    int n;
    // Transpose only posiible for square matrix
    cout << "Enter number of rows or column: ";
    cin >> n;

    cout << "Enter Elements: \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> A[i][j];
    
    cout << "input Matrix: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            B[i][j] = A[j][i];

    cout << "Result Matrix: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    transpose();
    cin.ignore();
    cin.get();
    return 0;
}