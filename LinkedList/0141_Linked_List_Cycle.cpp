#include<iostream>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next)
            return false;
        ListNode *node1, *node2;
        node1 = head->next; node2 = node1->next;
        while(true)
        {
            if(node1 == node2)
                return true;
            if(!node2->next || !node2->next->next)
                break;
            node2 = node2->next->next;
            node1 = node1->next;
        }
        return false;
    }
};