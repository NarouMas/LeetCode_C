#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> map;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node *newNode;
        //cout<<node->val<<"\n";
        if(map.count(node->val) != 0)
            return map[node->val];
        else
        {
            newNode = new Node();
            newNode->val = node->val;
            map.insert(pair<int, Node*>(node->val, newNode));
        }
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};

int main()
{
    Solution sol;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    Node *newNode = sol.cloneGraph(node1), *next;
    cout<<newNode->val<<"\n";
    for(int i = 0; i < newNode->neighbors.size(); i++)
        cout<<newNode->neighbors[i]->val<<" ";
    cout<<"\n";
    next = newNode->neighbors[0];
    cout<<next->val<<"\n";
    for(int i = 0; i < next->neighbors.size(); i++)
        cout<<next->neighbors[i]->val<<" ";
    cout<<"\n";
    next = newNode->neighbors[0]->neighbors[1];
    cout<<next->val<<"\n";
    for(int i = 0; i < next->neighbors.size(); i++)
        cout<<next->neighbors[i]->val<<" ";
    cout<<"\n"; 
    next = newNode->neighbors[1];
    cout<<next->val<<"\n";
    for(int i = 0; i < next->neighbors.size(); i++)
        cout<<next->neighbors[i]->val<<" ";
    cout<<"\n";
}