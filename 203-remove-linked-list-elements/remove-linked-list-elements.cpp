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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* newTemp = dummyHead;

        ListNode* temp = head;

        while(temp)
        {
            if(temp->val != val)
            {
                newTemp->next = temp;
                newTemp = newTemp->next;
            }
            temp = temp->next;
        }
        newTemp->next = nullptr;
        return dummyHead->next;
    }
};