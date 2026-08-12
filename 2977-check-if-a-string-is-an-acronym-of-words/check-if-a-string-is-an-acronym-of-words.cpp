class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string acronym = "";
        for(auto &a : words)
        {
            acronym += a[0];
        }

        return s == acronym;
        
    }
};