#include<iostream>
#include<vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *fast = head->next, *slow = head;
        while(fast)
        {
            cout<<"fast:"<<fast->val<<" slow:"<<slow->val<<"\n";
            if(slow == fast)
                return true;
            if(fast->next && fast->next->next)
                fast = fast->next->next, slow = slow->next;
            else
                break;
        }
        return false;
    }
};