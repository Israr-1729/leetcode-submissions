class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> frq(26);

        int size = s.size();
        for(int i = 0; i<size; i++)
        {
            frq[s[i]-'a']++;
        }
        for(int i = 0; i<size+1; i++)
        {
            frq[t[i]-'a']--;
        }

        for(int i = 0; i<26; i++)
        {
            if(frq[i]!=0)
            return i+'a';
        }
    return 'a';     
    }
};