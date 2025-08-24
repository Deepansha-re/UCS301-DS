#include<iostream>
#include<algorithm>
using namespace std;

/*Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1
distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
(a) Linear time
(b) Using binary search
*/

void LinearSearch(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    int n = size + 1; // Total numbers should be n
    int Actual_sum = n * (n + 1) / 2;

    int missing = Actual_sum - sum;
    cout << "Missing Number is: " << missing << endl;
}

void BinarySearch(int arr[], int size){
    int left = 0;
    int right = size-1;
    int missing = size + 1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == mid+1){
            left = mid+1;
        }
        else {
            // mismatch, missing is here or before
            missing = mid + 1;
            right = mid - 1;
        }
    }

    cout << "Missing Number (Binary Search): " << missing << endl;
}


int main(){
    int arr[] = {1, 2, 3, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    LinearSearch(arr,size);
    BinarySearch(arr,size);
    cin.ignore();
    cin.get();
    return 0;
}