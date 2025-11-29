#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

bool hasCycle(Node* head) {
    unordered_set<Node*> s;
    Node* temp = head;
    while(temp != NULL) {
        if(s.find(temp) != s.end()) return true;
        s.insert(temp);
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;  // loop

    cout << (hasCycle(n1) ? "true" : "false");
    cin.ignore();
    cin.get();
}
