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
    vector<int> nextLargerNodes(ListNode* head) {

        if(head==nullptr)
        return {0};
        vector<int> result;
        ListNode* temp = head;
        while(temp)
        {
            if(temp->next == nullptr)
            {
                result.push_back(0);
                break;
            }
            int resultIDX = 0;
            ListNode* traverse = temp->next;
            while(traverse)
            {
                if(traverse->val > temp->val)
                {
                    resultIDX = traverse->val;
                    break;
                }
                traverse = traverse->next;
            }
            result.push_back(resultIDX);
            temp = temp->next;
        }
        return result;
    }
};