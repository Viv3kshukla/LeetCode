#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/leaf-similar-trees/

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        if (leaves1.size() != leaves2.size()) return false;
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }

    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) leaves.push_back(root->val);
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
};

// mock
int main() {
    return 0;
}