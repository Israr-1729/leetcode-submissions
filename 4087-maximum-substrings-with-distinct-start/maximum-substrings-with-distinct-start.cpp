class Solution {
public:
    int maxDistinct(string s) {
        vector<int> frequency(26);
        int size = s.size();
        for(int i = 0; i<size; i++)
        {
            frequency[s[i]-'a']++;
        }
        int count = 0;
        for(int i = 0; i<26; i++)
        {
            if(frequency[i] != 0)
            count++;
        }
    return count;    
    }
};