#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    stack<char> s;
    cout << "Enter any String : ";
    cin >> str;

    for(int i=0; i < str.length(); i++){
        s.push(str[i]); 
    }

    cout << "\nReversed string:\n";
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    cin.ignore();
    cin.get();
    return 0;
}