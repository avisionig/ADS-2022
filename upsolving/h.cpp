#include <bits/stdc++.h>
using namespace std;

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
    int sons(){
        int cnt = 0;
        for (int i = 0; i < size; i++){
            int l1 = i * 2 + 1;
            int l2 = i * 2 + 2;
            if(l1 < size && l2 < size && arr[l1] < arr[l2] ) cnt++;
        }
        return cnt;
    }
    void print(){
        for (auto x: arr){
            cout << x << " ";
        }
    }

};
int main (){
    int n; cin >> n;
    int a;
    maxHeap* heap = new maxHeap();
    for (int i = 0;i < n; i++){
        cin >> a;
        heap -> insert(a);
    }
    cout << heap -> sons();
    return 0;
}