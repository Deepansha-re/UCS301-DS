#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if(st.empty())
                    return false;
                char top = st.top();
                st.pop();
                
                if((c==')' && top != '(') ||
                    (c=='}' && top != '{') ||
                    (c==']' && top != '[')){
                        return false;
                }
            }
        }

        return st.empty();
    }

};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if (sol.isValid(s))
        cout << "Valid string \n";
    else
        cout << "Invalid string \n";

    cin.ignore();
    cin.get();
    return 0;
}

