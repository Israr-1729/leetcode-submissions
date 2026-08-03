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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> copy;
        while(temp)
        {
            copy.push_back(temp->val);
            temp = temp->next;
        }

        stack<int> st;

        for(int i = copy.size()-1; i>=0; i--)
        {
            if(st.empty())
            st.push(copy[i]);

            if(copy[i] >= st.top())
            st.push(copy[i]);
        }

        vector<int> result;
        while(true)
        {
            if(!st.empty())
            {
            result.push_back(st.top());
            st.pop();
            }

            else
            break;
        }

        result.pop_back();

        ListNode* dummyHead = new ListNode(0);
        ListNode* newTemp = dummyHead;

        for(int a : result)
        {
            ListNode* newNode = new ListNode(a);
            newTemp->next = newNode;
            newTemp = newTemp->next;
        }
        
        return dummyHead->next;
    }
};