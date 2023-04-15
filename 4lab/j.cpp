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
void storeNode(Node* root, vector<Node*> &nodes){
    if (root == NULL) return;
        storeNode(root->left, nodes);
        nodes.push_back(root);
        storeNode(root->right, nodes);
}
Node* buildTree(vector<Node*>&nodes, int l, int r){
    if (l > r){
        return NULL;
    }
    int m = (r + l)/2;
    Node* root = nodes[m];
    root -> left = buildTree(nodes, l, m - 1);
    root -> right = buildTree(nodes, m + 1, r);
    return root;
}
Node* tree(Node* root){
    vector<Node*> nodes;
    storeNode(root, nodes);
    int n = nodes.size();
    return buildTree(nodes, 0, n - 1);
}
void print(Node * root){
    if(root == NULL){return;}
    cout << root->key << ' ';
    print(root->left);
    print(root->right);
}
int main(){
    int n; cin >> n;
    int size = 1;
    for(int i = 0; i < n; i++){
        size *= 2;
    }
    size--;
    Node* root = NULL;
    for (int i = 0; i < size;i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    root = tree(root);
    print(root);
    return 0;
}