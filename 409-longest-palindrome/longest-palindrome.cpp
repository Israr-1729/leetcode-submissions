class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for(auto &p : mp) {
            int freq = p.second;

            if(freq % 2 == 0) {
                length += freq;
            } else {
                length += freq - 1; // use even part
                hasOdd = true;      // one odd char can go in center
            }
        }

        return hasOdd ? length + 1 : length;
    }
};