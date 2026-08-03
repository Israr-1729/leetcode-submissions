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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numsCopy;
        for(int a : nums)
        {
            numsCopy.insert(a);
        }

        bool goingOn = false;
        int count = 0;
        ListNode* temp = head;

        while(temp)
        {
            if(!numsCopy.contains(temp->val))
            goingOn = false;

            else
            {
                if(!goingOn)
                count++;
                goingOn = true;
            }

            temp = temp->next;
        }
        return count;
    }
};