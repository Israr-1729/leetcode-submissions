class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int i = 0; int size1 = s1.size();

        while(i<size1)
        {
            string thisWord = "";
            while(i<size1 && s1[i]!=' ')
            {
                thisWord += s1[i];
                i++;
            }
            mp[thisWord]++;
            i++;
        }

        i = 0;
        int size2 = s2.size();
        while(i<size2)
        {
            string thisWord = "";
            while(i<size2 && s2[i]!=' ')
            {
                thisWord += s2[i];
                i++;
            }
            mp[thisWord]++;
            i++;
        }

        vector<string> result;
        for(auto &a : mp)
        {
            if(a.second == 1)
            result.push_back(a.first);
        }
    return result;
    }
};