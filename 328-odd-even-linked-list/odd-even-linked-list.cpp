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
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr)
        {
            return head;
        }

        else if(head->next == nullptr)
        {
            return head;
        }
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* evenStart = head->next;

        while(evenHead && evenHead->next)
        {
            oddHead->next = oddHead->next->next;
            oddHead = oddHead->next;

            evenHead->next = evenHead->next->next;
            evenHead = evenHead->next;
        }
        oddHead->next = evenStart;
        return head;
    }
};