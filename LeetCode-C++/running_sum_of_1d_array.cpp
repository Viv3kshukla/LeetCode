#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
   public:
    vector<int> runningSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                ans[i] = nums[i];
            else
                ans[i] = ans[i - 1] + nums[i];
        }
        return ans;
    }

    // vector<int> runningSum(vector<int>& nums) {  --fast
    //     for (int i = 1; i < nums.size(); i++) {
    //             nums[i] += nums[i-1];
    //     }
    //     return nums;
    // }
};

//mock
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution m;
    vector<int> ans = m.runningSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}