class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> occurences(26, 0);
        for(char c : s)
        {
            occurences[c-'a']++;
        }

        int ans = s.size();

        for(int i : occurences)
        {
            while(i >= 3)
            {
                i-=2;
                ans -=2;
            }

            if(i == 2)
            {
            ans--;
            }
        }
        return ans;
    }
};