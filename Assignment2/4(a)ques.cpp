#include<iostream>
using namespace std;

int main(){
    string str1,str2;
    cout << "Enter any word: ";
    cin >> str1;
    cout << "Enter any word:";
    cin >> str2;
    cout << "Concatenated string: " << str1 + str2 << endl;
    cin.ignore();
    cin.get();
    return 0;
}