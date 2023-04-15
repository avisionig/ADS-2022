#include <iostream>
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
        return newNode;
    }
    if (root -> key == data) return root;
    else if(root -> key < data){
        root -> right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left, data);
    }
    return root;
}
int getLevel(Node* root){
    if (root == NULL){
        return 0;
    }
    return max(getLevel(root -> right), getLevel(root -> left)) + 1;
}
int maxDistance(Node* root){
    if (root == NULL) return 0;
    int dist = getLevel(root -> right) + getLevel(root-> left) + 1;
    int temp = max(maxDistance(root -> left), maxDistance(root -> right));
    return max(dist, temp);
}
int main(){
    int n; cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n;i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    
    cout << maxDistance(root);
    return 0;
}