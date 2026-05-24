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

    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr)
        return head;

        ListNode* dummy = head;

        while(head->next != nullptr)
        {
            ListNode* newNode = new ListNode(gcd(head->val, head->next->val));
            ListNode* temp = head->next;
            head->next = newNode;
            newNode->next = temp;
            head = head->next->next;
        }
        return dummy;
    }
};