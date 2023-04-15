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
int getLevels(Node* root){
    if (root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root -> left == NULL){
        return getLevels(root->right) + 1;
    }
    else if (root -> right == NULL){
        return getLevels(root -> left) + 1;
    }  
    return max(getLevels(root -> left), getLevels(root -> right)) + 1;
}
void sumLevel(Node* root, int level, int sum[]){
    if(root == NULL) return;
    sum[level] += root -> key;
    sumLevel(root -> left, level + 1, sum);
    sumLevel(root -> right, level + 1, sum);
}
int main(){
    int n; cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n;i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    int levels = getLevels(root);
    int sum[levels] = {0};

    sumLevel(root, 0, sum);
    cout << levels << endl;
    for(int i = 0; i < levels; i++){
        cout << sum[i] << " ";
    }
    return 0;
}