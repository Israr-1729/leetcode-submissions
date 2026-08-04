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
    int size;
    ListNode* temp;
    ListNode* thisHead;

    Solution(ListNode* head) {
        temp = head;
        size = 0;
        thisHead = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        temp = head;
    }
    

        int randomNumber() {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, size-1);

        return dist(gen);
    }

    int getRandom() {
        int idxNeeded = randomNumber();
        int currIDX = 0;
        temp = thisHead;

        while(currIDX != idxNeeded)
        {
            temp = temp->next;
            currIDX++;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */