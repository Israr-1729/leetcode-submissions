class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> frequency(26);
        for(char c : s)
        {
            frequency[c-'a']++;
        }

        string result = "";
        for(char c : order)
        {
            int fr = frequency[c-'a'];
            for(int i = 0; i<fr; i++)
            {
                result += c;
                frequency[c-'a']--;
            }
        }

        for(int i = 0; i<26; i++)
        {
            int fr = frequency[i];
            for(int j = 0; j<fr; j++)
            {
                result += i + 'a';
            }
        }
    return result;
    }
};