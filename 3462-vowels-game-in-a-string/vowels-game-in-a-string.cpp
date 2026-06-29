class Solution {
public:
    bool doesAliceWin(string s) {
        bool contains = false;
        for(char c : s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            {
                contains = true;
                break;
            }
        }
        if(contains)
        return true;
        return false;
    }
};