#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

   Node(int val){
    data = val;
    left = right = nullptr;
   } 
};

Node* BuildTree(){
    int val ;
    cout << "Enter data (-1 for no node): ";
    cin >> val;
    if (val == -1)
        return nullptr;
    Node* newnode = new Node(val);
    cout << "Enter left child of "<< val <<endl;
    newnode->left = BuildTree();

    cout << "Enter right child of "<< val <<endl;
    newnode->right = BuildTree();

};

void preorder(Node* root){
    if (root == nullptr)
        return;
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
};
void inorder(Node* root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
};
void postorder(Node* root){
    if(root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data<<" ";
};

int main(){
    cout << "Build your binary tree\n";
    Node* root = BuildTree();

    cout << "\nPreorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cin.ignore();
    cin.get();
    return 0;
}