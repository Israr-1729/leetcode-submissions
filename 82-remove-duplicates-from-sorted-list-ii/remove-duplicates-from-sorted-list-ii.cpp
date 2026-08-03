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
        unordered_map<int, int> freq;
        ListNode* temp = head;
        while(temp)
        {
            freq[temp->val] ++;
            temp = temp->next;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* newTemp = dummyHead;
        temp = head;

        while(temp)
        {
            if(freq[temp->val] == 1)
            {
                ListNode* newNode = new ListNode(temp->val);
                newTemp->next = newNode;
                newTemp = newTemp->next;
                temp = temp->next;
            }
            else
            temp = temp->next;
        }
        return dummyHead->next;
    }
};