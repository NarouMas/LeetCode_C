#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> map;
        unordered_set<TreeNode*> set;
        TreeNode* st, *node;
        queue<TreeNode*> qu;
        int res = -1;
        foo(root, map, &st, start);
        map[root] = nullptr;
        set.insert(st);
        qu.push(st);
        while(!qu.empty())
        {
            res++;
            for(int i = qu.size() - 1; i >= 0; i--)
            {
                node = qu.front();
                qu.pop();
                if(node->left && set.count(node->left) == 0)
                {
                    set.insert(node->left);
                    qu.push(node->left);
                }
                if(node->right && set.count(node->right) == 0)
                {
                    set.insert(node->right);
                    qu.push(node->right);
                }
                if(map[node] && set.count(map[node]) == 0)
                {
                    set.insert(map[node]);
                    qu.push(map[node]);
                }
            }
        }
        return res;
    }
    void foo(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& map, TreeNode** start, int val)
    {
        if(node->val == val)
            *start = node;
        if(node->left)
        {
            map[node->left] = node;
            foo(node->left, map, start, val);
        }
        if(node->right)
        {
            map[node->right] = node;
            foo(node->right, map, start, val);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5, nullptr, new TreeNode(4));
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    root->right = new TreeNode(3, new TreeNode(10), new TreeNode(6));
    cout << sol.amountOfTime(root, 3) << endl;
    return 0;
}