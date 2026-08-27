class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end)
        {
            if(s[start] != s[end])
            {
                char a = s[start]; char b = s[end];
                s[start] = min(a, b);
                s[end] = min(a, b);
            }
            start++;
            end--;
        }
        return s;
    }
};