#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if (p == 0){
        node -> next = head;
        head = node;
        return head;
    }

    Node* curr = head;
    while (p > 1){
        curr = curr -> next;
        p--;
    }
    node -> next = curr -> next;
    curr -> next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    Node* curr = head;
    if (p == 0){
        head = curr -> next;
        free(curr);
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node* curr = head;
    int cnt = 0;
    while (curr != NULL){
        if (cnt == p1){
            Node* newNode = new Node(curr -> val);
            insert(head, newNode, p1);
            remove(curr, p1 + 1);
        }
        if (cnt == p2){
            Node* newNode = new Node(curr -> val);
            insert(head, newNode, p2);
            remove(curr, p2 + 1);
        }
        curr = curr -> next;
        cnt++;
    }
    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while ( curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
void print(Node* head){
    /* write your code here */
    Node* curr = head;
    while (curr != NULL){
        cout<< curr -> val << " ";
        curr = curr -> next; 
    }

}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    if (x == 0) return head;

    Node* curr = head;
    int cnt = 1;
    while (cnt < x && curr != NULL){
        curr = curr -> next;
        cnt++;
    }
    if (curr == NULL)
        return head;
    Node* xNode = curr;
    while ( curr -> next != NULL) curr = curr -> next;
    curr -> next = head;
    head = xNode -> next;
    xNode -> next = NULL;

    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    Node* temp = head;
    int len = 1;
    while ( temp -> next != NULL){
        temp = temp -> next;
        len++;
    }

    if ( x > len) x = x % len;
    x = len - x;

    if ( x == 0 || x == len) return head;

    Node* curr = head;
    int cnt = 1;
    while (cnt < x && curr != NULL){
        curr = curr -> next;
        cnt++;
    }
    if (curr == NULL) return head;

    Node* xNode = curr;

    temp -> next = head;
    head = xNode -> next;
    xNode -> next = NULL;

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}