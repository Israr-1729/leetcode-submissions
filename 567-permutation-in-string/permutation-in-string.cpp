class Solution {
public:


    bool check(vector<int> &one, string &s2)
    {
        vector<int> two(26, 0);

        for(char a : s2)
        {
            two[a-'a']++;
        }

        for(int i = 0; i<26; i++)
        {
            if(two[i]<one[i])
            return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();

        vector<int> one(26);
        for(char a : s1)
        {
            one[a-'a']++;
        }

        for(int i = 0; i<=s2Size-s1Size; i++)
        {
            string toCheck = s2.substr(i, s1Size);
            if(check(one, toCheck))
            return true;
        }
    return false;
    }
};