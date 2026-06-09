class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mapS(26);
        vector<int> mapT(26);
        int size = s.size();
        for(int i = 0; i<size; i++)
        {
            mapS[s[i]-'a']++;
            mapT[t[i]-'a']++;
        }

        // {1, 2}
        // {2, 1}
        int counter = 0;
        for(int i = 0; i<26; i++)
        {
            if(mapT[i]<mapS[i])
            counter+= mapS[i]-mapT[i];
        }
        return (counter);
    }
};