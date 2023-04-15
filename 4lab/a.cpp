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
bool validPath(Node* root, string path){
    Node* curr = root;
    for(int i = 0; i < path.size(); i++){
        if (curr == NULL) {
            return false;
        }
        else if(path[i] == 'L'){
            curr = curr->left;
        }
        else curr = curr -> right;
    }
    return curr != NULL;
}
int main(){
    int n, m;
    cin >>n >>m;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        root = insert(root, a);
    }
    string path;
    string ans[m];
    for (int i = 0; i < m; i ++){
        cin >> path;
        if (validPath(root, path)){
            ans[i] = "YES";
        }
        else ans[i] =  "NO";
    }
    for (int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}