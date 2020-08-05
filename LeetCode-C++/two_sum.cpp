#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/two-sum/

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[complement]);
                break;
            }
            mp.insert({nums[i], i});
        }
        return ans;
    }
};

// mock
int main() {
    int n, x;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    int target;
    cin >> target;
    Solution m;
    vector<int> ans = m.twoSum(vec, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}