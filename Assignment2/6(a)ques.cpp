#include <iostream>
using namespace std;

#define MAX 100

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void input_Matrix(int arr[][MAX], int &rows, int &coln){
    cout << "Enter no. of rows and columns: \n";
    cin >> rows >> coln;
    for(int i=0; i<rows; i++){
        for(int j=0; j<coln; j++){
            cout << "Enter the element " << "[" << i << "]" << "[" << j << "] : ";
            cin >> arr[i][j];
        }
    }
    cout << "Matrix \n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<coln; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";    
    }
}

void sparse_Matrix(int arr[][MAX], int rows, int coln, int sparse[][3], int &size){        
    int k=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<coln; j++){
            if(arr[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    size=k;
    cout << "\nSparse Matrix (Triplet form):\n";
    for (int i = 0; i < size; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

void transpose(int sparse[][3], int size){
    for (int i = 0; i < size; i++) {
        swap(sparse[i][0], sparse[i][1]);
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(sparse[j][0] > sparse[j+1][0] || (sparse[j][0] == sparse[j+1][0] && sparse[j][1] > sparse[j+1][1])){
                swap(sparse[j][0] , sparse[j+1][0]);
                swap(sparse[j][1] , sparse[j+1][1]);
                swap(sparse[j][2] , sparse[j+1][2]);
            }
        }
    }
}

int main() {
    int rows,coln,size;
    int arr[100][100];
    int sparse[100][3]; 

    input_Matrix(arr, rows, coln);
    sparse_Matrix(arr,rows,coln,sparse,size);
    transpose(sparse, size);
    sparse_Matrix(arr,rows,coln,sparse,size);

    cin.ignore();
    cin.get();
    return 0;
}
