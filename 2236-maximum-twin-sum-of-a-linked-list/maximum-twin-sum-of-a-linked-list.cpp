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
    int pairSum(ListNode* head) {
        vector<int> copy;
        ListNode *temp = head;
        while(temp)
        {
            copy.push_back(temp->val);
            temp = temp->next;
        }
        
        int maxSum = INT_MIN;
        int n = copy.size();
        for(int i = 0; i<n; i++)
        {
            maxSum = max(maxSum, copy[i]+copy[n-i-1]);
        }
        return maxSum;
    }
};