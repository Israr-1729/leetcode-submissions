class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        int size = s.size();
        if(size%2 != 0)
        return false;
        for(int i = 0; i<size; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            str.push(s[i]);

            if(str.size()==0)
            return false;

            if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(s[i]==')')
                {
                    if(str.top() != '(')
                    return false;
                    str.pop();
                }

                if(s[i]=='}')
                {
                    if(str.top() != '{')
                    return false;
                    str.pop();
                }

                if(s[i]==']')
                {
                    if(str.top() != '[')
                    return false;
                    str.pop();
                }
            }
          
        }
        if(str.size() != 0)
        return false;
        return true;
        
    }
};