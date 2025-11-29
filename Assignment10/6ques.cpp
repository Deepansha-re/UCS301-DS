#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) { data = d; left = right = NULL; }
};

bool checkDuplicates(Node* root, unordered_set<int> &s) {
    if(root == NULL) return false;

    if(s.find(root->data) != s.end()) return true;

    s.insert(root->data);

    return checkDuplicates(root->left, s) || checkDuplicates(root->right, s);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3);  // duplicate

    unordered_set<int> s;
    bool ans = checkDuplicates(root, s);

    cout << (ans ? "Duplicates Found" : "No Duplicates");
    cin.ignore();
    cin.get();
}
