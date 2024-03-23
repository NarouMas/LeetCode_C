#include<iostream>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *node, *next;
        prev = nullptr, node = head;
        while(node)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *node = s.reverseList(head);
    while(node)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    return 0;
}