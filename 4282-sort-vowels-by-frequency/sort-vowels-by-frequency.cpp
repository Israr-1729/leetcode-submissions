class Solution {
public:
    int firstOccurence(string &s, char c)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == c)
                return i;
        }
        return INT_MAX;
    }

    string sortVowels(string s) {
        unordered_map<char, int> freq;

        for(char c : s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                freq[c]++;
        }

        vector<vector<char>> letterFrequency(s.size()+1);

        for(auto &p : freq)
            letterFrequency[p.second].push_back(p.first);

        vector<char> vowels;

        for(int i = s.size(); i > 0; i--)
        {
            vector<char> &frequencyAtThis = letterFrequency[i];

            // order by first occurrence in the string.
            sort(frequencyAtThis.begin(), frequencyAtThis.end(),
                 [&](char a, char b){
                     return firstOccurence(s, a) < firstOccurence(s, b);
                 });

            for(char c : frequencyAtThis)
            {
                for(int j = 0; j < i; j++)
                    vowels.push_back(c);
            }
        }

        string modified;
        int idx = 0;

        for(char c : s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                modified.push_back(vowels[idx++]);
            else
                modified.push_back(c);
        }

        return modified;
    }
};