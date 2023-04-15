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
    int nearstNum( int num){
        int index = 0;
        int ans = 0;
        Node* curr = head;
        int temp = abs(curr -> x - num);
        while( curr != NULL){
            if (abs(curr->x - num) < temp){
                temp = abs(curr->x - num);
                ans = index;
            }
            curr = curr -> next;
            index++;
        }
        return ans;
    }
};
int main(){
    int n; cin >> n;
    LinkedList list;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        list.insert(a);
    }
    int near; cin >> near;
    cout << list.nearstNum(near);
    return 0;
}