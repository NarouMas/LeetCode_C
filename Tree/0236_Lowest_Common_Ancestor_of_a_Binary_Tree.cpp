#include<iostream>
#include<vector>
#include<unordered_map>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && !right)
            return left;
        if(!left && right)
            return right;
        if(left && right)
            return root;
        return NULL;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(0);
    TreeNode* node6 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(4);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4; 
    node2->left = node5;
    node2->right = node6;
    node4->left = node7;
    node4->right = node8;
    Solution sol;
    TreeNode* res = sol.lowestCommonAncestor(root, node1, node2);
    cout << res->val << endl;
    return 0;
}