class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        vector<int> num1, num2;

        while(l1) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }

        while(l2) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        vector<int> sum;

        while(i >= 0 || j >= 0 || carry) {

            int total = carry;

            if(i >= 0) total += num1[i--];
            if(j >= 0) total += num2[j--];

            carry = total / 10;
            sum.push_back(total % 10);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int k = sum.size() - 1; k >= 0; k--) {
            curr->next = new ListNode(sum[k]);
            curr = curr->next;
        }

        return dummy->next;
    }
};