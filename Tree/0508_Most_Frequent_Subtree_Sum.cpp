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
    vector<int> findFrequentTreeSum(TreeNode* root) {
          unordered_map<int, int> map;
          vector<int> ans;
          int max = 0;
          dfs(root, map, max);
          for(auto v:map)
          {
               if(v.second == max)
                    ans.push_back(v.first);
          }
          return ans;
    }
private:
     int dfs(TreeNode* node, unordered_map<int, int>& map, int& max)
     {
          if(node == NULL)
               return 0;
          int val = node->val + dfs(node->left, map, max) + dfs(node->right, map, max);
          if(map.find(val) != map.end())
          {
               map[val] = map[val] + 1;
          }
          else
          {
               map.insert({val, 1});
          }
          if(map[val] > max)
               max = map[val];
          return val;
     }
};

int main()
{
     TreeNode* root = new TreeNode(5);
     root->left = new TreeNode(2);
     root->right = new TreeNode(-5);
     Solution s;
     vector<int> ans = s.findFrequentTreeSum(root);
     for(auto v:ans)
          cout<<v<<" ";
     cout<<endl;
     return 0;
}