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
        map_p.clear();
        map_q.clear();
    }
private:
    unordered_map<TreeNode*, bool> map_p;
    unordered_map<TreeNode*, bool> map_q;
    bool dfs(TreeNode* node, int val_p)
    {

    }
};