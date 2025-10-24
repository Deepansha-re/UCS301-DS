#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Make list circular manually (for testing)
    void makeCircular() {
        if (head == nullptr)
            return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head; // last node links to head
    }

    // Check if the linked list is circular
    bool isCircular() {
        if (head == nullptr)
            return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    // Display (limited nodes to avoid infinite loop)
    void display() {
        Node* temp = head;
        int count = 0;
        cout << "Linked List: ";
        while (temp != nullptr && count < 10) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "...\n";
    }
};

// =======================
// Main Function
// =======================
int main() {
    LinkedList list;
    int n, value, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Make list circular? (1 = Yes, 0 = No): ";
    cin >> choice;
    if (choice == 1)
        list.makeCircular();

    list.display();

    if (list.isCircular())
        cout << "Output: True (It is a Circular Linked List)\n";
    else
        cout << "Output: False (It is NOT a Circular Linked List)\n";

    cin.ignore();
    cin.get();
    return 0;
}
