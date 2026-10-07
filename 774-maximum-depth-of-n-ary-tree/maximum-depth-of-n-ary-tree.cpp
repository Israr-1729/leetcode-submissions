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
    int maxDepth(Node* root) {
        if(root == nullptr)
        return 0;

        queue<Node*> q;
        q.push(root);
        
        int counter = 0;

        while(q.size() != 0)
        {
            counter++;
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                for(auto &a : q.front()->children)
                q.push(a);
                q.pop();

            }
        }

        return counter;
    }
};