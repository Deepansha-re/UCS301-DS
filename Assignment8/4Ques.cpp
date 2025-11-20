#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

bool isBST(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBST(root->left, minVal, root->data)
        &&   isBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << (isBST(root, LLONG_MIN, LLONG_MAX) ? "BST" : "Not BST");
    
    cin.ignore();
    cin.get();
    return 0;
}
