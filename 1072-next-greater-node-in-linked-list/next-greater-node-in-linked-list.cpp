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
        ListNode* temp = head;

        int size = 0;

        while(temp)
        {
            size++;
            temp = temp->next;
        }

        if(head==nullptr)
        return {};
        vector<int> result(size);
        temp = head; int i = 0;
        while(temp)
        {
            if(temp->next == nullptr)
            {
                result[size-1]=0;
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
            result[i] = resultIDX;
            temp = temp->next;
            i++;
        }
        return result;
    }
};