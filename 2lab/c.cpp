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
    void delSecond(){
        Node* prev = NULL;
        Node* curr = head;
        for (int i = 0; i < lenght; i++){
            if ((i + 1) % 2 == 0){
                prev -> next = curr ->next;
                Node *del = curr;
                curr = curr -> next;
                delete(del);
            }
            else{
                prev = curr;
                curr = curr -> next;
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
int main (){
    int n; cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        list.insert(a);
    } 
    list.delSecond();
    list.printList();
}