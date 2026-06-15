class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        if(s[0]-'0'==x)
        return false;

        else
        {
            int size = s.size();
            for(int i = 0; i<size; i++)
            {
                if(s[i]-'0'==x)
                return true;
            }
            return false;
        }
        
    }
};