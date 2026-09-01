/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void lot(Node* root, vector<vector<Node*>> &ans)
    {
        if(root == nullptr)
        return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<Node*> thisLevel;

            for(int i = 0; i < levelSize; i++)
            {
                Node* current = q.front();
                q.pop();

                thisLevel.push_back(current);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }

            ans.push_back(thisLevel);
        }
    }

    void populate(Node* &root, unordered_map<Node*, Node*> &mp)
    {
        if(root == nullptr)
        return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* current = q.front();
            q.pop();

            current->next = mp[current];

            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }

    void mapper(const vector<vector<Node*>> rights, unordered_map<Node*, Node*> &mp)
    {
        for(int i = 0; i < rights.size(); i++)
        {
            for(int j = 0; j < rights[i].size(); j++)
            {
                if(j != rights[i].size()-1)
                mp[rights[i][j]] = rights[i][j+1];

                else
                mp[rights[i][j]] = nullptr;
            }
        }
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> levelOrder;
        lot(root, levelOrder);

        unordered_map<Node*, Node*> mp;
        mapper(levelOrder, mp);

        populate(root, mp);

        return root;
    }
};