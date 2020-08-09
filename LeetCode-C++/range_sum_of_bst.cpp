#include <bits/stdc++.h>
using namespace std;

// problem-link : https://leetcode.com/problems/range-sum-of-bst/

class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr);
    TreeNode(int x) : val(x), left(nullptr), right(nullptr);
};

class Solution {
   public:
    int ans;
    int rangeSumBST(TreeNode *root, int L, int R) {
        ans = 0;
        dfs(root, L, R);
        return ans;
    }

    void dfs(TreeNode *root, int L, int R) {
        if (root == nullptr) return;
        if (root->val >= L && root->val <= R) {
            ans += root->val;
        }
        if (root->val >= L) {
            dfs(root->left, L, R);
        }
        if (root->val <= R) {
            dfs(root->right, L, R);
        }
    }
};

//mock
int main() {
    Solution m;
    TreeNode *root = nullptr;
    int l, r;
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cin >> l >> r;
    int ans = m.rangeSumBST(root, l, r);
    return 0;
}
