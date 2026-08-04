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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> copy;
        ListNode* temp = head;
        while(temp)
        {
            copy.push_back(temp->val);
            temp = temp->next;
        }

        sort(copy.begin(), copy.end());

        ListNode* dummyHead = new ListNode(0);
        temp = dummyHead;

        for(int a : copy)
        {
            ListNode* newNode = new ListNode(a);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};