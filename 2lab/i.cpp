#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    if (head == NULL){
        head = new Node (s);
        return;
    }
    Node* curr = head;
    while (curr -> next != NULL){
        curr = curr->next;
    }
    curr -> next = new Node(s);
}
void add_front(string s){
    Node* temp = new Node(s);
    temp -> next = head;
    head = temp;
}
bool empty(){
    return head == nullptr;
}
void erase_front(){
    Node* curr = head;
    head = head -> next;

    free(curr);
}
void erase_back(){
     if(head->next == NULL) {
      head = NULL;
      return;
      }
    Node* temp = head;
    while( temp -> next -> next != NULL){
        temp = temp -> next;
    }
    Node* delNode = temp -> next;
    temp -> next = NULL;
    free(delNode);
}
string front(){
    return head -> val;
}
string back(){
    Node* curr = head;
    while( curr -> next != NULL){
        curr = curr -> next;
    }
    return curr -> val;
}
void clear(){
    Node* temp = head;
    while(head){
        head = head -> next;
        free(temp);
        temp = head;
    }
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}