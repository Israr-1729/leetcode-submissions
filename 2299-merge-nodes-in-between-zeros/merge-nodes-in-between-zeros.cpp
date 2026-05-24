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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* firstZero = head;
        ListNode* secondZero = head;
        ListNode* result = new ListNode(0);
        ListNode* dummyHead = result;
        while(true)
        {
            int sum = 0;
            firstZero = secondZero;
            if(secondZero->next == nullptr)
            break;
            secondZero = secondZero->next;
            while(secondZero->val != 0)
            {
                sum+=secondZero->val;
                secondZero = secondZero->next;
            }
            ListNode* newNode = new ListNode(sum);
            result->next = newNode;
            result = result->next;
        }
        return dummyHead->next;
    }
};