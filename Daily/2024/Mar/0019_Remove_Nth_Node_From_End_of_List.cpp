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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head), *fast = dummy, *slow = dummy;
        while(fast)
        {
            if(n >= 0)
                n--;
            else
                slow = slow->next;
            fast = fast->next;
        }
        //cout<<"slow:"<<slow->val<<"\n";
        if(slow->next != nullptr)
            slow->next = slow->next->next;

        return dummy->next;
    }
};

