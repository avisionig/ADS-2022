#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    Node* next;
    Node* prev;
    Node(int data){
        x = data;
        next = NULL;
        prev = NULL;
    }
};
struct LinkedList{
    Node* head;
    Node* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert(int data){
        Node* newNode = new Node(data);
        if (head == NULL && tail == NULL){
            head = tail = newNode;
        } 
        else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void insert_front(int data){
        Node* newNode = new Node(data);
        if (head == NULL and tail == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void reverse(){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while ( curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
    void print(bool flag){
        if (flag){
            Node* cur = head;
            while (cur != NULL){
                cout<<cur -> x <<" ";
                cur = cur -> next;
            }
        }
        else {
            Node* cur = tail;
            while(cur != NULL){
                cout << cur -> x << " ";
                cur = cur ->prev;
            }
        }
    }
};
int main(){
    int n; cin >> n;
    int cmd, a;
    bool flag = false;
    LinkedList* list = new LinkedList();
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if (cmd == 1){
            cin >> a;
            if (flag){
                list -> insert(a);
            }
            else{
                list ->insert_front(a);
            }
        }
        else {
            flag = !flag;
        }
    }
    list -> print(flag);
    return 0;
} 