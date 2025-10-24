#include <iostream>
using namespace std;

// ============================
// Doubly Linked List Node
// ============================
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// ============================
// Circular Linked List Node
// ============================
struct CNode {
    int data;
    CNode* next;
};

// ============================
// Doubly Linked List Operations
// ============================
class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        DNode* newNode = new DNode{value, nullptr, head};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << "Inserted " << value << " at beginning.\n";
    }

    void insertAtEnd(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as first node.\n";
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at end.\n";
    }

    void insertAfter(int key, int value) {
        DNode* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        DNode* newNode = new DNode{value, temp, temp->next};
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        DNode* temp = head;

        // If head is to be deleted
        if (temp->data == value) {
            head = temp->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            cout << "Deleted node " << value << ".\n";
            return;
        }

        while (temp != nullptr && temp->data != value)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << value << " not found.\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Deleted node " << value << ".\n";
    }

    void search(int value) {
        DNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << value << " not found.\n";
    }

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

// ============================
// Circular Linked List Operations
// ============================
class CircularLinkedList {
private:
    CNode* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtBeginning(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (last == nullptr) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Inserted " << value << " at beginning.\n";
    }

    void insertAtEnd(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (last == nullptr) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Inserted " << value << " at end.\n";
    }

    void insertAfter(int key, int value) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode{value, temp->next};
                temp->next = newNode;
                if (temp == last)
                    last = newNode;
                cout << "Inserted " << value << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int value) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        CNode* curr = last->next;
        CNode* prev = last;

        do {
            if (curr->data == value) {
                if (curr == last && curr->next == last) {
                    last = nullptr; // only one node
                } else {
                    prev->next = curr->next;
                    if (curr == last)
                        last = prev;
                }
                delete curr;
                cout << "Deleted node " << value << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << value << " not found.\n";
    }

    void search(int value) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        CNode* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "Node " << value << " not found.\n";
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty.\n";
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

// ============================
// Main Menu
// ============================
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, key;

    while (true) {
        cout << "\n==================== MENU ====================\n";
        cout << "1. Doubly Linked List Operations\n";
        cout << "2. Circular Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n4. Delete a Node\n5. Search for a Node\n6. Display List\n7. Back to Main Menu\n";

        while (true) {
            cout << "\nEnter operation choice: ";
            cin >> choice;
            if (choice == 7) break;

            cout << "Enter value: ";
            cin >> val;

            if (listType == 1) {
                // Doubly Linked List
                switch (choice) {
                    case 1: dll.insertAtBeginning(val); break;
                    case 2: dll.insertAtEnd(val); break;
                    case 3: cout << "Insert after which node? "; cin >> key; dll.insertAfter(key, val); break;
                    case 4: dll.deleteNode(val); break;
                    case 5: dll.search(val); break;
                    case 6: dll.display(); break;
                    default: cout << "Invalid choice.\n";
                }
            } else if (listType == 2) {
                // Circular Linked List
                switch (choice) {
                    case 1: cll.insertAtBeginning(val); break;
                    case 2: cll.insertAtEnd(val); break;
                    case 3: cout << "Insert after which node? "; cin >> key; cll.insertAfter(key, val); break;
                    case 4: cll.deleteNode(val); break;
                    case 5: cll.search(val); break;
                    case 6: cll.display(); break;
                    default: cout << "Invalid choice.\n";
                }
            }
        }
    }

    cout << "Program exited successfully.\n";
    return 0;
}
