#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        // rotate old elements behind new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.top();    // 15
    s.pop();    // remove 15
    s.top();    // 10

    cin.ignore();
    cin.get();
    
    return 0;
}