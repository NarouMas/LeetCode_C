#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(0), *node, *prev;
        unordered_map<Node*, Node*> map;
        prev = dummy;
        while(head)
        {
            node = new Node(head->val);
            node->next = head->next;
            node->random = head->random;
            map[head] = node;
            prev->next = node;
            prev = node;
            head = head->next;
        }
        node = dummy->next;
        while(node)
            node->random = map[node->random], node = node->next;
        
        return dummy->next;
    }
};