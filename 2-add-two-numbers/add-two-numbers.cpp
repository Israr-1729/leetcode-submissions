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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        int carry = 0;

        while(l1 || l2 || carry != 0)
        {
            int thisSum = 0;
            if(l1)
            {
                thisSum += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                thisSum += l2->val;
                l2 = l2->next;
            }

            thisSum += carry;
            ListNode* newNode = new ListNode(thisSum%10);
            temp->next = newNode;
            temp = temp->next;
            carry = thisSum/10;
        }

        return dummyHead->next;
        
    }
};