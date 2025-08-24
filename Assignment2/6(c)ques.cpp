#include <iostream>
using namespace std;

#define MAX 100

// Function to input a normal matrix
void input_Matrix(int arr[][MAX], int &rows, int &coln) {
    cout << "Enter no. of rows and columns: \n";
    cin >> rows >> coln;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            cout << "Enter the element [" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
    }
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Convert normal matrix → sparse triplet
void sparse_Matrix(int arr[][MAX], int rows, int coln, int sparse[][3], int &size) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            if (arr[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    size = k;
    cout << "\nSparse Matrix (Triplet form):\n";
    for (int i = 0; i < size; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

// Multiply two sparse matrices in triplet form
void multiplySparse(int A[][3], int B[][3], int C[][3], int sizeA, int sizeB,
                    int &sizeC, int rowsA, int colnA, int rowsB, int colnB) {
    if (colnA != rowsB) {
        cout << "\nMultiplication not possible! Column of A must equal Row of B.\n";
        sizeC = 0;
        return;
    }

    int temp[MAX][MAX] = {0};  // store result in normal 2D form first

    // Multiply
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i][1] == B[j][0]) {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    // Convert back to sparse triplet
    int k = 0;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colnB; j++) {
            if (temp[i][j] != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = temp[i][j];
                k++;
            }
        }
    }
    sizeC = k;

    // Print Sparse Result
    cout << "\nResultant Sparse Matrix (A × B):\n";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }

    // Print Full Matrix
    cout << "\nResultant Matrix in Normal Form:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colnB; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, coln1, rows2, coln2;
    int arr1[MAX][MAX], arr2[MAX][MAX];
    int sparse1[MAX][3], sparse2[MAX][3], sparseProduct[MAX][3];
    int size1, size2, sizeProduct;

    cout << "Matrix A:\n";
    input_Matrix(arr1, rows1, coln1);
    sparse_Matrix(arr1, rows1, coln1, sparse1, size1);

    cout << "\nMatrix B:\n";
    input_Matrix(arr2, rows2, coln2);
    sparse_Matrix(arr2, rows2, coln2, sparse2, size2);

    multiplySparse(sparse1, sparse2, sparseProduct, size1, size2,
                   sizeProduct, rows1, coln1, rows2, coln2);

    return 0;
}
