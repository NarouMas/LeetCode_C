#include<iostream>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1, res;
        foo(root, 0, maxDepth, res);
        return res;
    }
    void foo(TreeNode* node, int depth, int &maxDepth, int &res)
    {
        if(!node)
            return;
        if(depth > maxDepth)
            res = node->val, maxDepth = depth;
        foo(node->left, depth + 1, maxDepth, res);
        foo(node->right, depth + 1, maxDepth, res);
    }
};