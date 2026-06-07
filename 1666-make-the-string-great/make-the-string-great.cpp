class Solution {
public:

    bool isGood(string s)
    {
        int size = s.size();
        for(int i = 0; i<size-1; i++)
        {
            if(s[i+1]==s[i]+32 || s[i+1]==s[i]-32)
            return false;
        }
        return true;
    }
    string makeGood(string s) {

        if(isGood(s))
        return s;

        string result = "";
        int size = s.size();
        for(int i = 0; i<size; i++)
        {
            while(i<size-1 && ((s[i+1]==s[i]+32)||s[i+1]==s[i]-32))
            i+=2;
            if(i<size)
            result.push_back(s[i]);
        }
        return makeGood(result); 
    }
};