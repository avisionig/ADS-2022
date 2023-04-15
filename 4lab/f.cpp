#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
    Node(int data){
        key = data;
        right = NULL;
        left = NULL;
    }
};

Node* insert(Node* root, int data){
    if (root == NULL){
        Node* newNode = new Node(data);
        root = newNode;
    }
    if (root -> key > data){
        root->left = insert(root->left, data);
    }
    else if(root -> key < data){
        root -> right = insert(root->right,data);
    }
    return root;
}
int triangles(Node* root){
    if (root == NULL) {
        return 0;
    }
    if (root->right == NULL && root->left == NULL){
        return 0;
    }
    if (root->right == NULL && root->left != NULL){
        return triangles(root->left);
    }
    if (root->right != NULL && root->left == NULL){
        return triangles(root->right);
    }
    return triangles(root->left) + triangles(root->right) + 1;
}

int main(){
    int n; cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n;i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    cout<<triangles(root);
    return 0;
}