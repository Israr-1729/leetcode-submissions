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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> copy;
        for(int a : nums)
        {
            copy.insert(a);
        }

        ListNode *dummyHead = new ListNode(0);
        ListNode *ansTemp = dummyHead;

        ListNode* temp = head;

        while(temp)
        {
            if(!copy.contains(temp->val))
            {
                ListNode* newNode = new ListNode(temp->val);
                ansTemp -> next = newNode;
                ansTemp = ansTemp->next;
            }

            temp = temp->next;
        }
        return dummyHead->next;
    }
};