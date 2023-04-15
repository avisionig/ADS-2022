#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, mult;
    Node *left, *right;
    Node(int data){
        key = data;
        mult = 1;
        right = NULL;
        left = NULL;
    }
};

Node* insert(Node* root, int data){
    if (root == NULL){
        Node* newNode = new Node(data);
        root =  newNode;
        return root;
    }
    if (root -> key == data){
        root->mult++;
        return root;
    }
    if (root -> key > data){
        root->left = insert(root->left, data);
    }
    else if(root -> key < data){
        root -> right = insert(root->right,data);
    }
    return root;
}
int cnt(Node* root, int x){
    if (root == NULL) return 0;
    if (root->key == x) return root -> mult;
    if (root -> key > x) return cnt(root->left, x);
    if (root -> key < x) return cnt(root -> right, x);
    return 0;
}
Node* del(Node* root,int x){
    if (root == NULL) return NULL;
    if (root -> key > x){
        root -> left = del(root->left, x);
        return root;
    }
    else if (root->key < x){
        root -> right = del(root -> right, x);
        return root;
    }
    else{
        if (root -> mult >= 1){
            root -> mult--;
        }
        return root;
    }
    return root;
}
int main(){
    int n, x; cin >> n;
    string a;
    Node* root = NULL;
    for (int i = 0; i < n;i++){
        cin >> a >> x;
        if (a == "insert") root = insert(root, x);
        else if (a == "delete") root = del(root,x);
        else if( a == "cnt") cout << cnt (root, x)<<"\n";
    }
    return 0;
}