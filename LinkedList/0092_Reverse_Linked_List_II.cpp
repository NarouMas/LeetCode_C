#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode *dummy = new ListNode(0, head), *node = dummy, *lprev, *next, *prev = new ListNode();
        for(int i = 0; i < left; i++)
            lprev = node, node = node->next;
        for(int i = left; i <= right; i++)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        lprev->next->next = node, lprev->next = prev;
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *res = s.reverseBetween(head, 2, 4);
    while(res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}