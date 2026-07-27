class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        unordered_set<char> letters;
        for(char c : word)
        {
            mp[c]++;
            letters.insert(c);
        }

        vector<char> sortedLetters;
        for(char c : letters)
        sortedLetters.push_back(c);

        sort(sortedLetters.begin(), sortedLetters.end(), [&](char a, char b) { return mp[a] > mp[b];});

        unordered_set<char> pushOnce;
        unordered_set<char> pushTwice;
        unordered_set<char> pushThrice;
        unordered_set<char> pushFourTimes;

        int size = sortedLetters.size();
        int idx = 0;

        while(idx<size && idx<8)
        {
            pushOnce.insert(sortedLetters[idx]);
            idx++;
        }

        while(idx<size && idx<16)
        {
            pushTwice.insert(sortedLetters[idx]);
            idx++;
        }

        while(idx<size && idx<24)
        {
            pushThrice.insert(sortedLetters[idx]);
            idx++;
        }

        while(idx<size && idx<32)
        {
            pushFourTimes.insert(sortedLetters[idx]);
            idx++;
        }


        int result = 0;
        for(char c : word)
        {
            if(pushOnce.contains(c))
            result++;

            else if(pushTwice.contains(c))
            result += 2;

            else if(pushThrice.contains(c))
            result += 3;

            else
            result += 4;
        }

        return result;
    }
};