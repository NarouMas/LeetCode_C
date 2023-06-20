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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
private:
    void dfs(TreeNode* node, int num, int& sum)
    {
        if(node == NULL)
            return;
        int add = num * 10 + node->val;
        if(node->left == NULL && node->right == NULL)
        {
            sum += add;
            return;
        }
        dfs(node->left, add, sum);
        dfs(node->right, add, sum);
    }
};