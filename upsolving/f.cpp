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

int getLevel(Node* root, int x, int i){
    if (root == NULL){
        return 0;
    }
    /*f (root -> data == x){
        return i + 1;
    }*/
    if (root -> data > x){
        return getLevel(root->left, x,i + 1);
    }
    else if ( root -> data < x){
        return getLevel(root ->right, x, i + 1);
    }
    return i + 1;
}

int main(){
    int n; cin >> n;
    int a;
    Node* root = NULL;
    int as[n] = {0};
    int levels[n] = {0};
    for (int i = 0; i < n; i++){
        cin >> a;
        root = insert(root, a);
        as[i] = a;
    }
    for (int i = 0; i < n; i++){
        levels[i] = getLevel(root, as[i], 0);
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += as[i] - (levels[i] - 1);
    }
    cout << sum;
    return 0;
}