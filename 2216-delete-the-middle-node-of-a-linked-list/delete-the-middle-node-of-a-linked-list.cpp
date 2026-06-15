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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp)
        {
            size++;
            temp = temp->next;
        }

        if(size==1)
        return nullptr;

        else if(size==2)
        {
            head->next = nullptr;
            return head;
        }

        temp = head;
        if(size%2==1)
        {
            for(int i = 0; i<size/2-1; i++)
            {
                temp = temp->next;
            }
            ListNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }

        else
        {
            for(int i = 0; i<size/2-1; i++)
            {
                temp = temp->next;
            }
            ListNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        return head;
    }
};