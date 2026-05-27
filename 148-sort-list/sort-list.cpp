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
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode *temp = head;
        while(temp)
        {
            temp = temp->next;
            size++;
        }

        if(size==0 || size==1)
        return head;
        vector<int> toArray(size);
        temp = head; int i = 0;
        while(temp)
        {
            toArray[i] = temp->val;
            temp = temp->next;
            i++;
        }
        sort(toArray.begin(), toArray.end());
        ListNode *result = new ListNode(0);
        ListNode *dummy = result;

        for(int i = 0; i<size; i++)
        {
            ListNode* newNode = new ListNode(toArray[i]);
            result->next = newNode;
            result = result->next;
        }
        return dummy->next;
    }
};