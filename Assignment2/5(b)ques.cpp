#include<iostream>
using namespace std;

void tridiagonal_Matrix(int arr[][10], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || i-1==j || i==j-1){
                cout << "Enter the elements [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    cout << "Tridiagonal Matrix\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int arr[10][10], n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    tridiagonal_Matrix(arr, n);

    cin.ignore();
    cin.get();

    return 0;
}
