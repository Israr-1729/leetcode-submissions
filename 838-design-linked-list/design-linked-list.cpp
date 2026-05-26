/*class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};*/

class MyLinkedList {
    ListNode* head;

public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        ListNode* temp = head;

        for(int i = 0; i < index; i++)
        {
            if(temp == nullptr)
            {
                return -1;
            }
            temp = temp->next;
        }

        if(temp == nullptr)
        {
            return -1;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        ListNode* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {

        if(index == 0)
        {
            addAtHead(val);
            return;
        }

        ListNode* temp = head;

        for(int i = 0; i < index - 1; i++)
        {
            if(temp == nullptr)
            {
                return;
            }

            temp = temp->next;
        }

        if(temp == nullptr)
        {
            return;
        }

        ListNode* newNode = new ListNode(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void deleteAtIndex(int index) {

        if(head == nullptr)
        {
            return;
        }

        if(index == 0)
        {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        ListNode* temp = head;

        for(int i = 0; i < index - 1; i++)
        {
            if(temp == nullptr)
            {
                return;
            }

            temp = temp->next;
        }

        if(temp == nullptr || temp->next == nullptr)
        {
            return;
        }

        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;

        delete toDelete;
    }
};