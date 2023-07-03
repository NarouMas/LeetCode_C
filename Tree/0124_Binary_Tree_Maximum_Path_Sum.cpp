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
    int maxPathSum(TreeNode* root) {
       int res = INT_MIN;
       dfs(root, res);
       return res;
    }
private:
    int dfs(TreeNode* node, int& res)
    {
        if(node == NULL)
            return 0;
        int left = max(dfs(node->left, res), 0);
        int right = max(dfs(node->right, res), 0);
        res = max(res, node->val + left + right);
        return node->val + max(left, right);
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<sol.maxPathSum(root)<<endl;
    return 0;
}