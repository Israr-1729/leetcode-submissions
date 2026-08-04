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
    ListNode* swapNodes(ListNode* head, int k) {
        //Using 1-index coz why not!

        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }

        //size - k + 1
        temp = head;
        for(int i = 0; i<size-k; i++)
        {
            temp = temp->next;
        }

        ListNode* rightPTR = temp;

        temp = head;
        for(int i = 0; i<k-1; i++)
        {
            temp = temp->next;
        }

        ListNode* leftPTR = temp;

        int useless = rightPTR->val;
        rightPTR->val = leftPTR->val;
        leftPTR->val = useless;

        return head;
    }
};