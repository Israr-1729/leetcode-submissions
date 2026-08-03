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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp)
        {
            int currVal = temp->val;
            ListNode* temp2 = temp;
            while(temp2)
            {
                if(temp2->val != currVal)
                break;

                temp2 = temp2->next;
            }

            temp->next = temp2;
            temp = temp->next;
        }
        return head;
    }
};