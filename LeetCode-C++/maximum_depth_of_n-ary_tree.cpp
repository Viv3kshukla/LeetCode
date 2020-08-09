#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

class Node {
   public:
    int val;
    vector<Node *> children;
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    int maxDepth(Node *root) {
        if (root == nullptr) return 0;
        int ans = 1;
        for (Node *child : root->children) {
            ans = max(ans, maxDepth(child) + 1);
        }
        return ans;
    }
};

// mock
int main() {
    Solution m;

    return 0;
}