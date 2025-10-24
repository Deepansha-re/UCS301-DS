#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last; // Pointer to last node
public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Function to insert node at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (last == nullptr) { // First node
            last = newNode;
            last->next = last; // Circular link
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to display all node values including head repeated
    void display() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* head = last->next;
        Node* temp = head;

        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Repeat head value at end
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;

    cout << "=== Circular Linked List Program ===\n";

    while (true) {
        cout << "\n1. Insert a node\n2. Display list\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 2:
                cll.display();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
