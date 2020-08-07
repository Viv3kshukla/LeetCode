#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
   public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) ans.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return ans;
    }
};

// mock
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution m;
    vector<int> ans = m.findDuplicates(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}