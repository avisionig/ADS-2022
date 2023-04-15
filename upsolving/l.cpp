#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        this -> data = x;
        right = NULL;
        left = NULL;
    }
};
Node* insert(Node* root, int x){
    if (root == NULL){
        Node* newNode = new Node(x);
        root = newNode;
    }
    if (root -> data > x){
        root -> left = insert(root -> left, x);
    }
    else if(root -> data < x){
        root -> right = insert( root ->right, x);
    }
    return root;
}
int childFree(Node* root,int cnt){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL and root->right == NULL){
        return cnt + 1;
    }
    else return childFree(root -> left, cnt) + childFree(root -> right, cnt);
}
int main(){
    int n; cin >> n;
    int a;
    Node* root = NULL;
    for (int i = 0; i < n; i++){
        cin >> a;
        root = insert(root, a);
    }
    cout << childFree(root, 0);
    return 0;
}