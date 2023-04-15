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
int sum = 0;
void treeSum(Node* root){
    if( root == NULL) return;
    treeSum(root -> left);
    int temp = root -> key;
    root -> key = sum;
    sum -= temp;
    treeSum(root ->right);
}
void print(Node * root){
    if(root == NULL){return;}
    print(root->right);
    cout << root->key << ' ';
    print(root->left);
}
int main(){
    int n; cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n;i++){
        int a; cin >> a;
        sum += a;
        root = insert(root, a);
    }
    treeSum(root);
    print(root);
    return 0;
}