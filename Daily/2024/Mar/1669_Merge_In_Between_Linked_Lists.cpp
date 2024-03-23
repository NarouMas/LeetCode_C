#include<iostream>
#include<vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = -1;
        a--, b++;
        ListNode *node = list1, *first, *end;
        while(node)
        {
            count++;
            if(count == a)
                first = node;
            if(count == b)
            {
                end = node;
                break;
            }
            node = node->next;
        }
        node = list2, first->next = list2;;
        while(node)
        {
            if(!node->next)
            {
                node->next = end;
                break;
            }
            node = node->next;
        }
        return list1;
    }
};