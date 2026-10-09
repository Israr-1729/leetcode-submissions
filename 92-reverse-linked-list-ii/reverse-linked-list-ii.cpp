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
        ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return head;

        if(head->next->next == nullptr)
        {
            ListNode* temp = head->next;
            temp->next = head;
            head->next = nullptr;

            return temp;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }

    int counter(ListNode* head)
    {
        int count = 0;
        while(head)
        {
        count++;
        head = head->next;
        }
        return count;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int length = counter(head);
        ListNode* beforeLeft = head;
        ListNode* afterRight = head;

        ListNode* l = head; ListNode* r = head;
        for(int i = 0; i < left-1; i++)
        {
            l = l->next;
        }

        for(int i = 0; i < right-1; i++)
        {
            r = r->next;
        }


        cout<<l->val<<" "<<r->val;

        while(beforeLeft && beforeLeft->next != l)
        {
            beforeLeft = beforeLeft->next;
        }
        
        if(r->next != nullptr)
        {
            afterRight = r->next;
        }
        else
        afterRight = nullptr;


        //if(right != length)
        r->next = nullptr;

        reverseList(l);

        if(beforeLeft != nullptr)
{
        beforeLeft->next = r;
        l->next = afterRight;
        return head;
}
        l->next = afterRight;

        return r;
    }
};