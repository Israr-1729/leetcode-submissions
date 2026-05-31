class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Seen;
        int size = s.size();
        int begin = 0; int end = 0;int maxLength = 0; int length = 0;
        while(end<size && begin<size)
        {
            if(end<size && Seen.find(s[end])==Seen.end())
            {
                length = end-begin+1;
                Seen.insert(s[end]);
                end++;
            }

            else
            {
                Seen.erase(s[begin]);
                begin++;
            }
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }
};