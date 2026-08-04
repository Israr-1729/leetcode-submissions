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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        vector<int> criticalPoints;
        while(curr->next != nullptr)
        {
            int nextVal = curr->next->val;
            int currVal = curr->val;
            int prevVal = prev->val;

            if((currVal>prevVal && currVal>nextVal) || (currVal < prevVal && currVal < nextVal))
            criticalPoints.push_back(idx);

            curr = curr->next;
            prev = prev->next;
            idx++;
        } 

        if (criticalPoints.size() < 2)
        return {-1, -1};

        int minDistance = INT_MAX;
        for(int i = 0; i<criticalPoints.size() - 1; i++)
        {
            minDistance = min(minDistance, criticalPoints[i+1] - criticalPoints[i]);
        }
        
        return {minDistance, criticalPoints.back()-criticalPoints.front()};
    }
};