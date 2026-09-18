/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void traverse(Node* root, vector<vector<int>>&result)
    {
        if(root == nullptr)
        return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> thisLevel;

            for(int i = 0; i < size; i++)
            {
                Node* newNode = q.front();
                for(auto &a : newNode->children)
                {
                    q.push(a);
                }
                thisLevel.push_back(newNode->val);
                q.pop();

            }
            result.push_back(thisLevel);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        traverse(root, result);
        return result;
    }
};