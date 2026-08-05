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
    ListNode* doubleIt(ListNode* head) {
        vector<int> copy;
        ListNode* temp = head;
        while(temp)
        {
            copy.push_back(temp->val);
            temp = temp->next;
        }

        int size = copy.size();
        int idx = size-1;
        int carry = 0;
        vector<int> twice;

        while(idx >= 0)
        {
            twice.push_back((2 * copy[idx] + carry) % 10);
            carry = (2 * copy[idx] + carry) / 10;
            idx--;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* ansTemp = dummyHead;
        if(carry != 0)
        {
            ListNode* carryDigit = new ListNode(carry);
            ansTemp->next = carryDigit;
            ansTemp = ansTemp->next;
        }

        for(int i = twice.size() - 1; i>=0; i--)
        {
            ListNode* newNode = new ListNode(twice[i]);
            ansTemp -> next = newNode;
            ansTemp = ansTemp->next;
        }
        return dummyHead->next;
    }
};