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
    void reorderList(ListNode* head) {
        vector<int> copy;
        ListNode* temp = head;
        while(temp)
        {
            copy.push_back(temp->val);
            temp = temp->next;
        }

        int size = copy.size();

        int till = ((size%2 == 0) ? size : size-1);
        vector<int> result(size, 0);
        int leftPTR = 0;
        int rightPTR = ((size % 2 == 0) ? size-1 : size-1);
        int takeLeft = true;

        for(int i = 0; i<till; i++)
        {
            if(takeLeft)
            {
                result[i] = copy[leftPTR++];
                takeLeft = false;
            }

            else
            {
                result[i] = copy[rightPTR--];
                takeLeft = true;
            }
        }

        if(size % 2 == 1)
        {
            result[size - 1] = copy[(size-1)/2];
        }
    
    temp = head; int idx = 0;
    while(temp)
    {
        temp->val = result[idx++];
        temp = temp->next;
    }
    }
};