#include <iostream>
using namespace std;

// ===========================
// Doubly Linked List Node
// ===========================
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// ===========================
// Circular Linked List Node
// ===========================
struct CNode {
    int data;
    CNode* next;
};

// ===========================
// Doubly Linked List Class
// ===========================
class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Find size
    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display
    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ===========================
// Circular Linked List Class
// ===========================
class CircularLinkedList {
private:
    CNode* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert at end
    void insertAtEnd(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last; // circular
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Find size
    int size() {
        if (last == nullptr)
            return 0;
        int count = 0;
        CNode* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }

    // Display
    void display() {
        if (last == nullptr) {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        CNode* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)\n";
    }
};

// ===========================
// Main Function
// ===========================
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, value;

    cout << "=== Find Size of Linked Lists ===\n";

    while (true) {
        cout << "\n1. Insert in Doubly Linked List"
             << "\n2. Display Doubly Linked List"
             << "\n3. Size of Doubly Linked List"
             << "\n4. Insert in Circular Linked List"
             << "\n5. Display Circular Linked List"
             << "\n6. Size of Circular Linked List"
             << "\n7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 2:
                dll.display();
                break;
            case 3:
                cout << "Size of Doubly Linked List = " << dll.size() << endl;
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 5:
                cll.display();
                break;
            case 6:
                cout << "Size of Circular Linked List = " << cll.size() << endl;
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
