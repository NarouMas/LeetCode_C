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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root ==NULL)
            return ans;
        search(root, ans);
        return ans;
    }
private:
    void search(TreeNode* node, vector<int>& ans)
    {
        if(node->left != NULL)
            search(node->left, ans);
        ans.push_back(node->val);
        if(node->right != NULL)
            search(node->right, ans);
    }
};