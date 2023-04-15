#include <bits/stdc++.h> 
using namespace std; 


vector <int> mat [1001];
void res(int n, vector <int> mat [1001]){
    int pCounter[n];
    for(int i = 0; i < n; i++){
        pCounter[mat[i][0]]++;
    }
    
    vector<int> q;
    for(int i=0; i<n; i++){
        if(pCounter[i]==0){
            q.push_back(i);
        }
    }
    
    int numNoPre = q.size();
    
    int result[n];
    int j=0;
    
    while(q.size()!=0){
        int c = 0;
        if(!q.empty()){
            c = q.back();
            q.pop_back();
        }    
        result[j++]=c;
        
        for(int i=0; i<n; i++){
            if(mat
        [i][1]==c){
                pCounter[mat
            [i][0]]--;
                if(pCounter[mat
            [i][0]]==0){
                    q.push_back(mat
                [i][0]);
                    numNoPre++;
                }
            }
        
        }
    }
    
    cout<<"[";
    for(int i=0; i<n; i++){
        cout<<result[i]<<",";
    }
    cout<<"]";
}
  
int main(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        mat[--x].push_back(--y);
    }

    res(n, mat);
    return 0; 
}