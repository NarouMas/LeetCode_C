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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(), *node, *prev;
        prev = dummy;
        while(list1 && list2)
        {
            node = new ListNode();
            if(list1->val <= list2->val)
                node->val = list1->val, list1 = list1->next;
            else
                node->val = list2->val, list2 = list2->next;
            prev->next = node;
            prev = node;
        }
        if(list1)
            prev->next = list1;
        if(list2)
            prev->next = list2;
        return dummy->next;
    }
};

int main()
{
    Solution obj;
    ListNode *list1, *list2, *node;
    list1 = new ListNode(1);
    node = new ListNode(2);
    list1->next = node;
    node = new ListNode(4);
    list1->next->next = node;
    list2 = new ListNode(1);
    node = new ListNode(3);
    list2->next = node;
    node = new ListNode(4);
    list2->next->next = node;
    node = obj.mergeTwoLists(list1, list2);
    while(node)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}