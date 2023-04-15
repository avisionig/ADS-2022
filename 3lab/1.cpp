#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> nums  = {1,2,2,3, 5};
    int target = 2;
    vector <int> ans;
    int l = 0, r = nums.size() - 1;
    while(r >= l){
        int m = l + (r - l) / 2;
        cout << m;
        if( nums[m] == target){
            ans.push_back(nums[m]);
        }
        else if (nums[m] > target){
            r = m - 1;
        }
        else l = m + 1;
    }
    for (auto x : ans){
        cout << x;
    }
}