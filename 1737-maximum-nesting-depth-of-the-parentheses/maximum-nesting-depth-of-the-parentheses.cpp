class Solution {
public:
    int maxDepth(string s) {
        int maxm = -1;
        int currDepth = 0;
        for(char c : s)
        {
            if(c == '(')
            currDepth++;

            else if(c == ')')
            currDepth--;

            maxm = max(maxm, currDepth);
        }
        return maxm;
    }
};