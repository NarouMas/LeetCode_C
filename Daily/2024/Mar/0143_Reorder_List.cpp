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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode *node = head;
        while(node)
        {
            arr.push_back(node);
            node = node->next;
        }
        for(int i = 0, j = arr.size() - 1; i < j; i++, j--)
        {
            arr[i]->next = arr[j];
            arr[j]->next = arr[i + 1];
        }
        arr[arr.size() / 2]->next = nullptr;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution().reorderList(head);
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}