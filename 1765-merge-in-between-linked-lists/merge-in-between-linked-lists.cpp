/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2begin = list2;
        ListNode* list2end = list2;
        while(list2end->next != 0)
        {
            list2end=list2end->next;
        }
        ListNode* partitionStart = list1;
        for(int i = 0; i<a-1; i++)
        {
            partitionStart = partitionStart->next;
        }

        ListNode* partitionEnd = list1;
        for(int i = 0; i<=b; i++)
        {
            partitionEnd = partitionEnd->next;
        }

        partitionStart->next = list2begin;
        list2end->next = partitionEnd;
        return list1;
    }
};