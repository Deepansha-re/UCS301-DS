#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (key == root->key) return root;
        root = (key < root->key) ? root->left : root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchRec(root, key);
    if (!target) return NULL;

    if (target->right)
        return findMin(target->right);

    Node* succ = NULL;
    while (root) {
        if (key < root->key) {
            succ = root;
            root = root->left;
        } else if (key > root->key)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchRec(root, key);
    if (!target) return NULL;

    if (target->left)
        return findMax(target->left);

    Node* pred = NULL;
    while (root) {
        if (key > root->key) {
            pred = root;
            root = root->right;
        } else if (key < root->key)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Search Recursive 40: "
         << (searchRec(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Search Non-Recursive 25: "
         << (searchNonRec(root, 25) ? "Found" : "Not Found") << endl;

    cout << "Min: " << findMin(root)->key << endl;
    cout << "Max: " << findMax(root)->key << endl;

    Node* s = inorderSuccessor(root, 50);
    cout << "Successor of 50: " << (s ? to_string(s->key) : "None") << endl;

    Node* p = inorderPredecessor(root, 50);
    cout << "Predecessor of 50: " << (p ? to_string(p->key) : "None") << endl;

    cin.ignore();
    cin.get();
    
    return 0;
}
