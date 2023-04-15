#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node(int x){
        data = x;
        prev = NULL;
    }
};
Node* insert(Node* head, int x){
    if (head == NULL){
        return new Node(x);
    }
    Node* newNode = new Node(x);
    newNode -> prev = head;
    return newNode;
}
Node* delCur(Node* head){
    Node* del = head;
    head = head -> prev;
    delete del;
    return head;
}
int getMax(Node* head){
    Node* cur = head;
    int max = 0;
    while(cur != NULL){
        if (max < cur->data){
            max = cur -> data;
        }
        cur = cur -> prev;
    }
    return max;
}

int main(){
    int n; cin >> n;
    string cmd;
    int a;
    int maxs = 0;
    Node* head = NULL;
    for (int i = 0; i < n;i++){
        cin >> cmd;
        if (cmd == "add"){
            cin >> a;
            if (a > maxs){
                maxs = a;
            }
            head = insert(head, a);
        }
        else if (cmd == "delete"){
            if (head == NULL){
                cout << "error" << endl;
                continue;
            }
            if (maxs == head ->data){
                head = delCur(head);
                maxs = getMax(head);
                continue;
            }
            head = delCur(head);
        }
        else if (cmd == "getcur"){
            if (head == NULL){
                cout << "error" << endl;
                continue;
            }
            cout << head ->data << endl;
        }
        else if (cmd == "getmax"){
            if (head == NULL){
                cout << "error" << endl;
                continue;
            }
            cout << maxs << endl;
        }
    }
    return 0;
}