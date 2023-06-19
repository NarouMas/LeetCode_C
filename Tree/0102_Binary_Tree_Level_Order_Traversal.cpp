#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        TreeNode* node;
        if(root == NULL)
            return ans;
        qu.push(root);
        while(!empty(qu))
        {
            int size = qu.size();
            vector<int> level;
            while(size--)
            {
                node = qu.front();
                qu.pop();
                level.push_back(node->val);
                if(node->left != NULL)
                    qu.push(node->left);
                if(node->right != NULL)
                    qu.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};