#include <bits/stdc++.h>
using namespace std;

// problem-link : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int hash[101] = {0};
        for(int i=0;i<nums.size();i++) {
            hash[nums[i]]++;
        }
        for(int i=1;i<101;i++) {
            hash[i] += hash[i-1];
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) continue;
            nums[i] = hash[nums[i]-1];
        }
        return nums;
    }
};

// mock
int main() {
    Solution m;
    int n,x;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++) {
        cin>>x;
        vec.push_back(x);
    }
    vector<int> ans = m.smallerNumbersThanCurrent(vec);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}