#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Evaluate postfix numerically
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
                case '^': st.push(pow(val2, val1)); break;
            }
        }
    }
    return st.top();
}

// Convert postfix to infix expression
string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {   // operand
            string op(1, c);
            st.push(op);
        } else {            // operator
            string val1 = st.top(); st.pop();
            string val2 = st.top(); st.pop();
            string expr = "(" + val2 + c + val1 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    string infix = postfixToInfix(postfix);

    cout << "Infix expression: " << infix << endl;
    cout << "Evaluated result: " << result << endl;

    return 0;
}
