#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    char data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert character at end
    void insertAtEnd(char value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Check if the linked list is a palindrome
    bool isPalindrome() {
        if (head == nullptr) return true;

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string input;

    cout << "Enter the string: ";
    cin >> input;

    // Insert characters into linked list
    for (char ch : input)
        dll.insertAtEnd(ch);

    dll.display();

    if (dll.isPalindrome())
        cout << "Output: True\n";
    else
        cout << "Output: False\n";

    cin.ignore();
    cin.get();
    return 0;
}
