class Solution {
public:

    bool isAnagram(string s, string &p)
    {
        int size = s.size();
        vector<int> frq(26, 0);
        for(int i = 0; i<size; i++)
        {
            frq[s[i]-'a']++;
            frq[p[i]-'a']--;
        }
        for(int i = 0; i<26; i++)
        {
            if(frq[i]!=0)
            return false;
        }
    return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int Psize = p.size();
        int Ssize = s.size();
        vector<int> result;
        for(int i = 0; i<Ssize-Psize+1; i++)
        {
            if(isAnagram(s.substr(i, Psize), p))
            result.push_back(i);
        }
        return result;
    }
};