class Solution {
public:
    bool areSimilar(const string &s1, const string &s2)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for(char c : s1)
        v1[c-'a']++;

        for(char c : s2)
        v2[c-'a']++;

        for(int i = 0; i < 26; i++)
        {
            if((v1[i] == 0 && v2[i] != 0) || (v1[i] != 0 && v2[i] == 0))
            return false;
        }
        return true;
    }
    int similarPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            if(areSimilar(words[i], words[j]))
            count++;
        }
        return count;
    }
};