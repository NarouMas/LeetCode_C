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
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        int path = 0;
        dfs(root, path);
        return res;
    }
    void dfs(TreeNode* node, int path)
    {
        if(!node)
            return;

        if(!node->left && !node->right)
        {
            path ^= (1<<node->val);
            if((path & (path - 1)) == 0)
                res++;
            return;
        }
        dfs(node->left, path^(1<<node->val));
        dfs(node->right, path^(1<<node->val)); 
        
    }
};