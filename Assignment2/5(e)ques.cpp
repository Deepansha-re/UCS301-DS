#include<iostream>
using namespace std;

void symmetric_Matrix(int arr[][10], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cout << "Enter the elements [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            if (i != j){
                arr[j][i] = arr[i][j];
            }

        }
    }
    cout << "Symmetric Matrix\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int arr[10][10], n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    symmetric_Matrix(arr, n);

    cin.ignore();
    cin.get();

    return 0;
}
