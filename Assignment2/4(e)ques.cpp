#include<iostream>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]= str[i] +32;
        }
    }
    cout << "Lowercase string: " << str << endl;
    cin.ignore();
    cin.get();
    return 0;
}