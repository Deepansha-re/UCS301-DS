#include <iostream>
using namespace std;

#define MAX 100

// Function to input a normal matrix
void input_Matrix(int arr[][MAX], int &rows, int &coln){
    cout << "Enter no. of rows and columns: \n";
    cin >> rows >> coln;
    for(int i=0; i<rows; i++){
        for(int j=0; j<coln; j++){
            cout << "Enter the element [" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
    }
    cout << "Matrix: \n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<coln; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";    
    }
}

// Convert normal matrix → sparse triplet
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

// Convert sparse → normal matrix
void sparseToNormal(int sparse[][3], int size, int rows, int coln) {
    int normal[MAX][MAX] = {0};

    for (int i = 0; i < size; i++) {
        int r = sparse[i][0];
        int c = sparse[i][1];
        int val = sparse[i][2];
        normal[r][c] = val;
    }

    cout << "\nFinal Matrix after Addition:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            cout << normal[i][j] << " ";
        }
        cout << "\n";
    }
}

// Add two sparse matrices in triplet form
void addSparse(int A[][3], int B[][3], int C[][3], int sizeA, int sizeB, int &sizeC, int rows, int coln) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { // same position
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i < sizeA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j < sizeB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    sizeC = k;

    cout << "\nResultant Sparse Matrix (A + B):\n";
    for (int p = 0; p < sizeC; p++) {
        cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
    }

    // Print back as normal matrix
    sparseToNormal(C, sizeC, rows, coln);
}

int main() {
    int rows1, coln1, rows2, coln2;
    int arr1[MAX][MAX], arr2[MAX][MAX];
    int sparse1[MAX][3], sparse2[MAX][3], sparseSum[MAX][3];
    int size1, size2, sizeSum;

    cout << "Matrix A:\n";
    input_Matrix(arr1, rows1, coln1);
    sparse_Matrix(arr1, rows1, coln1, sparse1, size1);

    cout << "\nMatrix B:\n";
    input_Matrix(arr2, rows2, coln2);
    sparse_Matrix(arr2, rows2, coln2, sparse2, size2);

    if (rows1 != rows2 || coln1 != coln2) {
        cout << "\nAddition not possible! Different dimensions.\n";
    } else {
        addSparse(sparse1, sparse2, sparseSum, size1, size2, sizeSum, rows1, coln1);
    }

    return 0;
}
