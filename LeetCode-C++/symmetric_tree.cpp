#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/symmetric-tree/

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 && root2 && (root1->val == root2->val) && isSymmetric(root1->right, root2->left) && isSymmetric(root1->left, root2->right))
            return true;
        return false;
    }
};

// mock
int main() {
    Solution m;
    TreeNode *root = new TreeNode();
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    bool ans = m.isSymmetric(root);
    cout << ans << endl;
    return 0;
}