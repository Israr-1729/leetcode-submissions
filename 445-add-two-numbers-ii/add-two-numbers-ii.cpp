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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int size1 = 0; int size2 = 0;

        while(temp1)
        {
            size1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            size2++;
            temp2 = temp2->next;
        }

        vector<int> num1(size1);
        vector<int> num2(size2);
        temp1 = l1;
        temp2 = l2;

        for(int i = 0; i<size1; i++)
        {
            num1[i] = temp1->val;
            temp1 = temp1->next;
        }

        for(int j = 0; j<size2; j++)
        {
            num2[j] = temp2->val;
            temp2 = temp2->next;
        }

        vector<int> sum;
        int i = size1-1;
        int j = size2-1;
        int carry = 0;
        while(i>=0 && j>=0)
        {
            int sumDigit = carry;
            sumDigit+=num1[i];
            sumDigit+=num2[j];
            carry = sumDigit/10;
            sum.push_back(sumDigit%10);

            i--;
            j--;
        }

        while(i>=0)
        {
            int sumDigit = carry;
            sumDigit+=num1[i];
            carry = sumDigit/10;
            sum.push_back(sumDigit%10);
            i--;

        }

        while(j>=0)
        {
            int sumDigit = carry;
            sumDigit+=num2[j];
            carry = sumDigit/10;
            sum.push_back(sumDigit%10);
            j--;
        }

        if(carry != 0)
        sum.push_back(carry);

        int finalSize = sum.size();
        ListNode* result = new ListNode(0);
        ListNode* dummy = result;

        for(int k = finalSize-1; k>=0; k--)
        {
            ListNode* newNode = new ListNode(sum[k]);
            result->next = newNode;
            result = result->next;
        }
        return dummy->next;
    }
};