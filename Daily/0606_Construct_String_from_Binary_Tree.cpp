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
    string tree2str(TreeNode* root) {
        string s = "";
        foo(root, s);
        return s;
    }
private:
    void foo(TreeNode* Node, string& s)
    {
        s += to_string(Node->val);
        if(Node->left)
        {
            s += "(";
            foo(Node->left, s);
            s += ")";
        }
        if(Node->right)
        {
            if(!Node->left)
                s += "()";
            s += "(";
            foo(Node->right, s);
            s += ")";
        }
    }
};