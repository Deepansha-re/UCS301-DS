#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int countAndDelete(int key) {
    int count = 0;

    // Delete from beginning if matches
    while (head && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }

    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }

    return count;
}

void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertAtEnd(x);

    cout << "Original List: "; display();
    int key = 1;
    int cnt = countAndDelete(key);
    cout << "Count: " << cnt << endl;
    cout << "Updated List: "; display();
}
