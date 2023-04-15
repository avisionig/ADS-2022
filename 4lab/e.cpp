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

Node* insert(Node* root, int parent, int data, int pos){
    queue <Node *> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        Node* temp = nodes.front();
        nodes.pop();
        if (temp -> key == parent){
            Node* newNode = new Node(data);
            if (pos == 0){
                temp ->left = newNode;
            }
            else{
                temp -> right = newNode;
            }
            return root;
        }
        if(temp -> right != NULL){
            nodes.push(temp -> right);
        }
        if(temp -> left != NULL){
            nodes.push(temp -> left);
        }
    }
    return root;
}
int getLevels(Node* root){
    if (root == NULL){
        return 0;
    } 
    return max(getLevels(root -> left), getLevels(root -> right)) + 1;
}
void getWidth(Node* root, int level, int width[]){
    if(root == NULL) return;
    width[level]++;
    getWidth(root-> left, level + 1, width);
    getWidth(root -> right, level + 1, width);
}
int main(){
    int n; cin >> n;
    Node* root = new Node(1);
    for (int i = 0; i < n - 1; i++){
        int x,y,z;
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    int level = getLevels(root);
    int width[level] = {0};

    int maxi = 1;
    getWidth(root, 0, width);
    width[0] = 1;
    for(int i = 0; i < level; i++){
        if (maxi < width[i]){
            maxi = width[i];
        }
    }
    cout << maxi;
    return 0;
}