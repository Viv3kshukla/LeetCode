#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
};

// mock
int main() {
    return 0;
}