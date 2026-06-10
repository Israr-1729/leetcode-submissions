class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);
        for(char c : s)
        freq[c-'a']++;

        int vowelF = 0; int consonantF = 0;

        for(int i = 0; i<26; i++)
        {
            if(i=='a'-'a' ||i=='e'-'a' ||i=='i'-'a' ||i=='o'-'a' ||i=='u'-'a')
            {
                if(freq[i]>vowelF)
                {
                    vowelF = freq[i];
                }
            }
            else
            {
                if(freq[i]>consonantF)
                {
                    consonantF = freq[i];
                }
            }
        }
        return vowelF+consonantF;
    }
};