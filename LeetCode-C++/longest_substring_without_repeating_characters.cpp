#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
   public:
    // int lengthOfLongestSubstring(string s) {  -- slow
    //     set<char> st;
    //     int ans = 0, i = 0, j = 0, n = s.length();
    //     while (i < n && j < n) {
    //         if (st.find(s[j]) == st.end()) {
    //             st.insert(s[j]);
    //             ans = max(ans, j - i + 1);
    //             j++;
    //         } else {
    //             st.erase(s[i]);
    //             i++;
    //         }
    //     }
    //     return ans;
    // }

    int lengthOfLongestSubstring(string s) {  // -- fast
        int hash[128];
        memset(hash, 0, sizeof(hash));
        int ans = 0, i = 0, j = 0, n = s.length();
        while (i < n && j < n) {
            if (hash[s[j]] == 0) {
                hash[s[j]]++;
                ans = max(ans, j - i + 1);
                j++;
            } else {
                hash[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};

//mock
int main() {
    string s;
    cin >> s;
    Solution m;
    int ans = m.lengthOfLongestSubstring(s);
    cout << ans << endl;
}