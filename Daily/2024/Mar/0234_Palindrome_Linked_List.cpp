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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i = 0, j = arr.size() - 1; i < j; i++, j--)
            if(arr[i] != arr[j])
                return false;
        return true;
    }
};