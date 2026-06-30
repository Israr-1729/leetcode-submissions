class Solution {
public:
    bool equalFrequency(string word) {

        vector<int> freq(26, 0);

        for(char c : word)
            freq[c-'a']++;

        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0)
                continue;

            freq[i]--;

            int commonFrequency = 0;
            bool possible = true;

            for(int a : freq)
            {
                if(a == 0)
                    continue;

                if(commonFrequency == 0)
                    commonFrequency = a;
                else if(a != commonFrequency)
                {
                    possible = false;
                    break;
                }
            }

            if(possible)
                return true;

            freq[i]++;
        }

        return false;
    }
};