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
    int lenght;
    LinkedList(){
        head = NULL;
        tail = NULL;
        lenght = 0;
    }
    void insert(int data){
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
    void insertInPos(int pos, int data){
        Node* newNode = new Node(data); 
        newNode->next = NULL;
        if(pos == 0){
            newNode -> next = head;
            head = newNode;
        }
        else{
            Node* curr = head;
            for(int i = 0; i < pos - 1; i++){
                if (curr != NULL){
                    curr = curr -> next;
                }
            }
            if (curr != NULL){
                newNode -> next = curr ->next;
                curr -> next = newNode;
            }
        }
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
    int n; cin >> n;
    int a;
    LinkedList list;
    for(int i = 0; i < n; i++){
        cin >> a;
        list.insert(a);
    }
    int data, pos; cin>> data >> pos;
    list.insertInPos(pos, data);
    list.printList();
}