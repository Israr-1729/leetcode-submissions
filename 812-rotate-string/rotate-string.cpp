class Solution {
public:

    void rotateOnce(string &s)
    {
        int size = s.size();
        char begin = s[0];
        for(int i = 0; i < size - 1; i++)
        {
            s[i] = s[i + 1];
        }

        s[size-1] = begin;
    }
    bool rotateString(string s, string goal) {
        if(s==goal)
        return true;
        int size = s.size();
        for(int i = 0; i<size; i++)
        {
            rotateOnce(s);
            if(s==goal)
            return true;
        }
        return false;
    }
};