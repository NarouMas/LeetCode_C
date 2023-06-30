#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        ser(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return des(in);
    }
private:
    void ser(TreeNode* node, ostringstream& out)
    {
        if(node != NULL)
        {
            out<<node->val<<" ";
            ser(node->left, out);
            ser(node->right, out);
        }
        else
        {
            out<<"# ";
        }
    }
    TreeNode* des(istringstream& in)
    {
        string val;
        in >> val;
        if(val == "#")
            return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = des(in);
        node->right = des(in);
        return node;
    }
};

int main()
{
    Codec codec;
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    string res = codec.serialize(root);
    cout << res << endl;
}