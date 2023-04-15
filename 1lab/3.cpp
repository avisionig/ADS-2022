#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> n = {1 , 3 ,4 , 0};
    int mini = *min_element(n.begin(), n.end());
    cout<<mini;
}