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
    void mode(){
        Node* curr = head;
        int highest = 0;
        map <int, int> hashMap;
        while (curr != NULL){
            hashMap[curr -> x]++;
            if ( hashMap[curr -> x] > highest){
                highest = hashMap[curr -> x];
            }
            curr = curr -> next;
        }
        for ( auto it = hashMap.rbegin(); it != hashMap.rend(); it++){
            if (it -> second == highest){
                cout << it -> first << " ";
            }
        }
    }

};
int main(){
    int n; cin >> n;
    LinkedList list;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        list.insert(a);
    }
    list.mode();
    return 0;
}