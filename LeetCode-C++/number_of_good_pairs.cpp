#include <bits/stdc++.h>
using namespace std;

// problem-link : https://leetcode.com/problems/number-of-good-pairs/

class Solution {
   public:
    int numIdenticalPairs(vector<int> &nums) {
        int hash[101] = {0}, ans = 0;
        for (auto i : nums) {
            hash[i]++;
        }
        for (auto i : hash) {
            ans += (i * (i - 1)) / 2;
        }
        return ans;
    }
};

// mock
int main() {
    Solution m;
    int n, x;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    int ans = m.numIdenticalPairs(vec);
    cout << ans << endl;
    return 0;
}