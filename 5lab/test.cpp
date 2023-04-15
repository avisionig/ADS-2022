#include <bits/stdc++.h>
using namespace std;

struct minHeap{
    vector<int> arr;
    int size;
    minHeap(){
        int size = 0;
    }
    void heapUp(int i){
        if (i > 0 and arr[i] < arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            heapUp((i-1)/2);
        }
    }
    void heapDown(int i){
        int m = i;
        int l1 = i*2 + 1;
        int l2 = i*2 + 2;
        if (i > 0 and arr[l1] < arr[m]){
            m = l1;
        }
        if (i > 0 and arr[l2] < arr[m]){
            m = l2;
        }
        if (m != i){
            swap(arr[m], arr[i]);
            heapDown(m);
        }
    }
    void insert(int data){
        arr.push_back(data);
        size++;
        heapUp(size - 1);
    }
    void print(){
        for (auto x: arr){
            cout << x << " ";
        }
    }
};
struct maxHeap{
    vector<int> arr;
    int size;
    maxHeap(){
        int size = 0;
    }
    void heapUp(int i){
        if (i > 0 and arr[i] > arr[(i-1)/2]){
            swap(arr[i], arr[(i-1)/2]);
            heapUp((i-1)/2);
        }
    }
    void heapDown(int i){
        int m = i;
        int l1 = i * 2 + 1;
        int l2 = i * 2 + 2;
        if ( l1 < size and arr[l1] > arr[m]){
            m = l1;
        }
        if (l2 < size and arr[l2] > arr[m]){
            m = l2;
        }
        if (m != i){
            swap(arr[i], arr[m]);
            heapDown(m);
        }
    }
    void insert(int data){
        arr.push_back(data);
        size++;
        heapUp(size - 1);
    }
    void print(){
        for (auto x: arr){
            cout << x << " ";
        }
    }

};
int main(){
    int n; cin>>n;
    //minHeap* mini = new minHeap();
    maxHeap* maxi = new maxHeap();
    int a;
    for(int i = 0; i < n; i++){
        cin>> a;
        //mini->insert(a);
        maxi->insert(a);
    }
    //mini->print();
    //cout << endl;
    maxi->print();
}
