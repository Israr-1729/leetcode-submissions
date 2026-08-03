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
        set<int> nums;
        while(head)
        {
            nums.insert(head->val);
            head = head->next;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;

        for(int a : nums)
        {
            ListNode* newNode = new ListNode(a);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};