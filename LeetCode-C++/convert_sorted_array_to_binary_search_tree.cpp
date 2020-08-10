#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        return buildTree(l, r, nums);
    }
    TreeNode *buildTree(int l, int r, vector<int> &nums) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(l, mid - 1, nums);
        root->right = buildTree(mid + 1, r, nums);
        return root;
    }
};

void printInorder(TreeNode *root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

// mock
int main() {
    Solution m;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    TreeNode *ans = m.sortedArrayToBST(nums);
    printInorder(ans);
    return 0;
}