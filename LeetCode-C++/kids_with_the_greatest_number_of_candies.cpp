#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        int maxn = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++) {
            ans[i] = (candies[i] + extraCandies) >= maxn;
        }
        return ans;
    }
};

// mock
int main() {
    int n, extra;
    cin >> n >> extra;
    vector<int> candies(n);
    for (int i = 0; i < candies.size(); i++) {
        cin >> candies[i];
    }
    Solution m;
    vector<bool> ans = m.kidsWithCandies(candies, extra);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}