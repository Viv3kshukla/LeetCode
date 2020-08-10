#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if ((p != nullptr) && (q != nullptr) && (p->val == q->val) && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)) return true;
        return false;
    }
};

// mock
int main() {
    return 0;
}