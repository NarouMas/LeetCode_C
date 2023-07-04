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
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1: 0) + res;
    }
private:
    int res = 0;
    int dfs(TreeNode* node)
    {
        if(node == NULL)
            return 2;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        if(left == 1 || right == 1)
            return 2;
        return 0;
    }
};