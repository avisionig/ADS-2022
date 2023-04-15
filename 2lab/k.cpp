#include <bits/stdc++.h>
using namespace std;

struct Node{
    char x;
    Node* next;
    Node* prev;
    Node(char data){
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
    void insert(char data){
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
    void printList(){
        Node* curr = head;
        while (curr != NULL){
            cout<<curr -> x <<" ";
            curr = curr -> next;
        }
    }
};
int main(){
    int t; cin >> t;
    return 0;
}