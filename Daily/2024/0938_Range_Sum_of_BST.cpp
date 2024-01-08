#include<iostream>
#include<vector>
using namespace std;

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        foo(root,low , high, res);
        return res;
    }
    void foo(TreeNode* node, int low, int high, int& res)
    {
        if(node)
        {
            if(node->val >= low && node->val <= high)
                res += node->val;
            foo(node->left, low, high, res);
            foo(node->right, low, high, res);
        }
    }
};