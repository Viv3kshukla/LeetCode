#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/shuffle-the-array/

class Solution {
   public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[n + i]);
        }
        return ans;
    }
};

// mock
int main() {
    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
    }
    Solution m;
    vector<int> ans = m.shuffle(nums, n);
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}