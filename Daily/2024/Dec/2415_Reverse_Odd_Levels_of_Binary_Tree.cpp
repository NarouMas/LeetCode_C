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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        vector<TreeNode*> currentLevelNodes, nextLevelNodes;
        currentLevelNodes.push_back(root);
        while(root)
        {
            if(level & 1)
            {
                vector<int> arr(1<<level);
                for(TreeNode* node: currentLevelNodes)
                    arr.push_back(node->val);
                int i = arr.size() - 1;
                for(TreeNode* node: currentLevelNodes)
                    node->val = arr[i], i--; 
            }
            nextLevelNodes.clear();
            if(currentLevelNodes[0]->left)
            {
                for(TreeNode* node: currentLevelNodes)
                {
                    nextLevelNodes.push_back(node->left);
                    nextLevelNodes.push_back(node->right);
                }
                currentLevelNodes = nextLevelNodes;
            }
            else
                break;
            level++;
        }
        return root;
    }
};