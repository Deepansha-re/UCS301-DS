#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void findMiddle() {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle: " << slow->data << endl;
}

int main() {
    for (int i=1; i<=5; i++) insertAtEnd(i);
    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
    cout << temp->data;
    if (temp->next) cout << "->";
    temp = temp->next;
    }
    cout << endl;
    findMiddle();
    cin.ignore();
    cin.get();
    return 0;
}
