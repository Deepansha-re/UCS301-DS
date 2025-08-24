#include<iostream>
using namespace std;

void count_elements(int arr[], int n){
    cout << "Enter " << n << " elements: \n"; 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int count =0;
    for(int i=0; i<n; i++){
        bool isDuplicate = false;
        for(int j=0; j<i; j++){
            if(arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
        count++;
        }
    }
    cout << "Unique elements in array\n";
    cout << count;
    
}

int main(){
    int arr[100], n;

    cout << "Enter Number of Elements: ";
    cin >> n;
    count_elements(arr,n);

    cin.ignore();
    cin.get();

    return 0;
}