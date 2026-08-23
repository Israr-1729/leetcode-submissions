class Solution {
public:
    string removeOuterParentheses(string s) {
        unordered_set<int> indicesToRemove;
        int inside = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(inside == 0 && s[i] == '(')
            {
                indicesToRemove.insert(i);
                inside++;
            }

            else if(inside == 1 && s[i] == ')')
            {
                indicesToRemove.insert(i);
                inside--;
            }

            else if(inside != 0 && s[i] == '(')
            {
                inside++;
            }

            else if(inside != 0 && s[i] == ')')
            {
                inside--;
            }
        }

        string result = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(!indicesToRemove.contains(i))
            {
                result += s[i];
            }
        }

        return result;
        
    }
};