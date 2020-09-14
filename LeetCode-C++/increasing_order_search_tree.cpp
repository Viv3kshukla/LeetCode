#include <bits/stdc++.h>
using namespace std;

// problem link: https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode *r;
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *ans = new TreeNode();
        r = ans;
        inOrder(root);
        return ans->right;
    }
    void inOrder(TreeNode *node) {
        if (node == nullptr) return;
        inOrder(node->left);
        r->right = node;
        r->left = nullptr;
        r = node;
        inOrder(node->right);
    }
};

// mock
int main() {
    Solution m;
    TreeNode *root = nullptr;
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    TreeNode *ans = m.increasingBST(root);
    return 0;
}
// Time Complexity: O(N), where N is the number of nodes in the given tree.

// Space Complexity: O(H) in additional space complexity,
//  where H is the height of the given tree, and the size of the implicit call stack in our in-order traversal.