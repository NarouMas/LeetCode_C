#include<iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *l1_current = l1, *l2_current = l2, *head , *current, *prev;
        current = new ListNode();
        int carry = 0;
        head = current;
        while(l1_current != nullptr && l2_current != nullptr)
        {
            ListNode *next = new ListNode();
            int sum = l1_current->val + l2_current->val + carry;
            current->val = sum % 10;
            carry = sum / 10;
            current->next = next;
            prev = current;
            current = current->next;

            l1_current = l1_current->next;
            l2_current = l2_current->next;
        }
        while(l1_current != nullptr)
        {
            ListNode *next = new ListNode();
            int sum = l1_current->val + carry;
            current->val = sum % 10;
            carry = sum / 10;
            current->next = next;
            prev = current;
            current = current->next;
            l1_current = l1_current->next;
        }
        while(l2_current != nullptr)
        {
            ListNode *next = new ListNode();
            int sum = l2_current->val + carry;
            current->val = sum % 10;
            carry = sum / 10;
            current->next = next;
            prev = current;
            current = current->next;
            l2_current = l2_current->next;
        }
        if(carry != 0)
        {
            ListNode *next = new ListNode();
            current->val = carry;
            current->next = next;
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;

        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *l1_current = l1;
    l1_current->next = new ListNode(4);
    l1_current = l1_current->next;
    l1_current->next = new ListNode(3);
    l1_current = l1_current->next;
    ListNode *l2 = new ListNode(5);
    ListNode *l2_current = l2;
    l2_current->next = new ListNode(6);
    l2_current = l2_current->next;
    l2_current->next = new ListNode(4);
    l2_current = l2_current->next;
    Solution sol;
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    while(ans != nullptr)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
}