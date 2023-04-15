#include <bits/stdc++.h>
using namespace std;

struct Node{
    string x;
    Node* next;
    Node* prev;
    Node(string data){
        x = data;
        next = NULL;
        prev = NULL;
    }
};
struct LinkedList{
    Node* head;
    Node* tail;
    int lenght;
    LinkedList(){
        head = NULL;
        tail = NULL;
        lenght = 0;
    }
    void insert(string data){
        Node* newNode = new Node(data);
        if (head == NULL && tail == NULL){
            head = tail = newNode;
        } 
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        lenght++;
    }
    void rotate (int k){
        if (k == 0) return;
        Node* curr = head;
        int cnt = 1;
        while (cnt < k && curr != NULL){
            curr = curr -> next;
            cnt++;
        }
        if (curr == NULL) return;
        Node* kNode = curr;
        while (curr -> next != NULL) curr = curr -> next;
        curr -> next = head;
        head = kNode -> next;
        kNode -> next = NULL;
    }
    void printList(){
        Node* curr = head;
        while (curr != NULL){
            cout<<curr -> x <<" ";
            curr = curr -> next;
        }
    }
};
int main(){
    LinkedList list;
    int n; cin >> n;
    int k; cin >> k;
    for ( int i = 0; i < n; i++){
        string a; cin >> a;
        list.insert(a);
    }
    list.rotate(k);
    list.printList();
}