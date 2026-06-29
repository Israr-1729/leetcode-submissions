class Solution {
public:
    bool rotateString(string s, string goal) {
        char goalFirst = goal[0];
        if(s.size() != goal.size())
        return false;
        int size = s.size();
        int i = 0;
        while(i<size)
        {
            if(s[i]==goalFirst)
            {
                string thisString = s.substr(i, size-i) + s.substr(0, i);
                if(thisString == goal)
                return true;
            }
            i++;
        }
    return false;
    }
};