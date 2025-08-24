#include<iostream>
using namespace std;

void upper_Triangular_Matrix(int arr[][10], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i){
                cout << "Enter the elements [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    cout << "Upper Triangular Matrix\n";
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

    upper_Triangular_Matrix(arr, n);

    cin.ignore();
    cin.get();

    return 0;
}
