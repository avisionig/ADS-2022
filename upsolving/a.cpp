#include <bits/stdc++.h>
using namespace std;
int arr[1000000] = {0};
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
        return newNode;
    }
    if (root -> data > x){
        root -> left = insert(root -> left, x);
    }
    else if(root -> data < x){
        root -> right = insert( root ->right, x);
    }
    return root;
}
int lcnt(Node* root){
    int cnt = 0;
    while(root != NULL){
        cnt++;
        root = root->left; 
    }
    return cnt;
}
int rcnt(Node* root){
    int cnt = 0;
    while(root != NULL){
        cnt++;
        root = root -> right;
    }
    return cnt;
}
void triangle(Node* root){
    if (root == NULL) return;

    if (root->left != NULL){
        triangle(root->left);
    }
    if (root->right != NULL){
        triangle(root->right);
    }
    int cnt = min(lcnt(root -> left), rcnt(root -> right));
    for (int i = 0;i < cnt; i++){
        arr[i]++;
    }
}
int main(){
    int n; cin >> n;
    int a;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        cin >> a;
        root = insert(root, a);
    }
    triangle(root);
    for(int i = 0; i < n - 1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}