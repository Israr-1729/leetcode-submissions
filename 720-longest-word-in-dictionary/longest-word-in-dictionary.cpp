class Solution {
public:

    bool containsAllDependencies(const unordered_set<string> &wordsCopy, const string &word) {
        string dep = "";
        for(char c : word)
        {
            dep += c;
            if(!wordsCopy.contains(dep))
            return false;
        }
        return true;
    }

    string longestWord(vector<string>& words) {
        unordered_set<string> wordsCopy;
        for(const string &s : words) {
            wordsCopy.insert(s);
        }

        string ans = "";
        int maxSize = 0;  

        for(const string &s : words)
        {
            if(s.size() >= maxSize && containsAllDependencies(wordsCopy, s))
            {
                if(s.size() > maxSize)
                {
                    maxSize = s.size();
                    ans = s;
                }

                else if(s.size() == maxSize)
                {
                    ans = min(s, ans);
                }
            }
        }
        return ans;
    }
};