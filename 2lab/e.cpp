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
            lenght++;
        } 
        else {
            if (head -> x != data){
                head -> prev = newNode;
                newNode -> next = head;
                head = newNode;
                lenght++;
            }
        }
    }
    void printList(){
        Node* curr = head;
        while (curr != NULL){
            cout<<curr -> x <<"\n";
            curr = curr -> next;
        }
    }
};
int main(){
    int n; cin >> n;
    LinkedList list;
    string a; 
    for (int i = 0; i < n; i++){
        cin >> a;
        list.insert(a);
    }
    cout << "All in all: " << list.lenght <<"\n";
    cout << "Students:" << "\n";
    list.printList();
}