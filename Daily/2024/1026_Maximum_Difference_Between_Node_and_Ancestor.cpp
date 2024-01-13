#include<iostream>
#include<vector>
#include<cmath>
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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        foo(root, root->val, root->val, res);
        return res;
    }
    void foo(TreeNode* node, int low, int high, int& res)
    {
        if(node)
        {
            res = max(res, max(abs(low - node->val), abs(high - node->val)));
            low = min(low, node->val);
            high = max(high, node->val);
            foo(node->left, low, high, res);
            foo(node->right, low, high, res);
        }
    }
};