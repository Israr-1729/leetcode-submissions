class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq1Even (26);
        vector<int> freq2Odd (26);

        for(int i = 0; i<s1.size(); i+=2)
        {
            freq1Even[s1[i]-'a']++;
            freq1Even[s2[i]-'a']--;
        }

        for(int i = 1; i<s1.size(); i+=2)
        {
            freq2Odd[s1[i]-'a']++;
            freq2Odd[s2[i]-'a']--;
        }
        for(int i = 0; i<26; i++)
        {
            if(freq1Even[i] != 0 || freq2Odd[i]!=0)
            return false;
        }
        return true;
    }
};