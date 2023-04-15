# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	// Implement this function
    int sum = head -> val;
    Node* curr = head;
    while( curr != NULL){
        Node* temp = curr;
        int tempSum = 0;
        while ( temp != NULL){
            tempSum += temp -> val;
            temp = temp -> next;
            if ( tempSum > sum){
                sum = tempSum;
            }
        }
        curr = curr -> next;
    }
    return sum;
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}