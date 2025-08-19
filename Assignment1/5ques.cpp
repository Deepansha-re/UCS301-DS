#include<iostream>
using namespace std;

#define MAX 100
int arr[MAX][MAX];

int main(){
    int m,n;
    cout << "Enter rows and columns of first matrix (m p): ";
    cin >> m >> n;

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < m; i++){
        int rowSum = 0;
        for (int j = 0; j < n; j++){
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
    return 0;
}
