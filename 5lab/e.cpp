#include <bits/stdc++.h>
using namespace std;

struct heap{
    long long arr[1000000];
    int size;
    heap(){
        size = 0;
    }
    void heapUp(int i){
        if (i > 0 && arr[i] < arr[(i - 1)/2]){
            swap(arr[i],arr[(i - 1)/2]);
            heapUp((i - 1)/2);
        }
    }
    void heapDown(int i){
        int m = i;
        int l1 = 2 * i + 1;
        int l2 = 2 * i + 2;
        if (l1 < size && arr[l1] < arr[m]){
            m = l1;
        } 
        if (l2 < size && arr[l2] < arr[m]){
            m = l2;
        }
        if ( m != i){
            swap(arr[m], arr[i]);
            heapDown(m);
        }

    }
    void insert(long long data){
        arr[size] = data;
        size++;
        heapUp(size - 1);
    }
};
int main(){
    int n, q; cin >> n >> q;
    string cmd;
    heap* pq = new heap();
    long long a, sum = 0;
    vector <long long> ans;
    for (int i = 0; i < n; i++){
        cin >> cmd;
        if (cmd == "print"){
            ans.push_back(sum);
        }
        else {
            cin >> a;
            if (pq -> size == q){
                if (a > pq -> arr[0]){
                    sum += a - pq -> arr[0];
                    pq -> arr[0] = a;
                    pq -> heapDown(0);
                }
            }
            else{
                pq -> insert(a);
                sum += a;
            }
        }
    }
    for (auto x : ans){
        cout << x << endl;
    }
    return 0;
}