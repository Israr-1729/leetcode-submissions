class Solution {
public:
    int partitionString(string s) {
        vector<bool> isThere(26, false);

        int count = 1;

        for(char c : s)
        {
            if(isThere[c-'a'])
            {
                isThere = vector<bool> (26, false);
                isThere[c-'a'] = true;
                count++;
            }

            else
            {
                isThere[c-'a'] = true;
            }
        }
        return count;
    }
};