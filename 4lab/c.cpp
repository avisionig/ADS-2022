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
Node* find(Node* root, int x){
    if (root == NULL) return NULL;
    if ( root -> key == x) return root;
    Node* res1 = find(root -> left, x);
    if (res1) return res1;
    Node* res2 = find(root->right, x);
    return res2;
}
void print(Node * root){
    if(root == NULL){return;}
    cout << root->key << ' ';
    print(root->left);
    print(root->right);
}
int main(){
    int n; cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n;i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    int x; cin >> x;
    Node* temp = find(root, x);
    print(temp);
}