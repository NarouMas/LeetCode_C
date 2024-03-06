#include<iostream>
#include<vector>
#include<queue>
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        bool even = true, first;
        qu.push(root);
        int prev;
        while(!qu.empty())
        {
            first = true;
            for(int i = qu.size(); i > 0; i--)
            {
                TreeNode* node = qu.front();
                qu.pop();
                if(even && !(node->val & 1))
                    return false;
                if(!even && (node->val & 1))
                    return false;
                if(!first)
                {
                    if(even && node->val <= prev)
                        return false;
                    if(!even && node->val >= prev)
                        return false;
                }
                prev = node->val, first = false;
                if(node->left)
                    qu.push(node->left);
                if(node->right)
                    qu.push(node->right);
            }
            even = !even;
        }
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)), nullptr), new TreeNode(4, new TreeNode(7, new TreeNode(6) ,nullptr), new TreeNode(9, nullptr, new TreeNode(2))));
    cout << s.isEvenOddTree(root) << endl;
    TreeNode* root2 = new TreeNode(5, new TreeNode(4, new TreeNode(3), new TreeNode(3)), new TreeNode(2, new TreeNode(7), nullptr));
    cout << s.isEvenOddTree(root2) << endl;
    return 0;
}