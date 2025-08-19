#include<iostream>
using namespace std;


#define MAX 10

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int m, p, n;

    cout << "Enter rows and columns of first matrix (m p): ";
    cin >> m >> p;

    cout << "Enter rows and columns of second matrix (p n): ";
    int p2;
    cin >> p2 >> n;

    if (p != p2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    // Multiply
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           C[i][j] = 0;
           for(int k=0; k<p; k++){
            C[i][j] += A[i][k] * B[k][j];
           } 
        }
    }
    cout << "Result matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
