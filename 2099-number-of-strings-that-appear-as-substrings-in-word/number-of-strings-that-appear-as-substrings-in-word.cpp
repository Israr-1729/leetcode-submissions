class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int size = word.size();
        for(string &s : patterns)
        {
            for(int i = 0; i<size; i++)
            {
                if(word[i]!=s[0])
                continue;
                else if(i + s.size()<=size)
                {
                    if(word.substr(i, s.size())==s)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};