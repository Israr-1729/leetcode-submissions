class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        for(int i = 0, size = s.size(); i<size; i++)
        {
            bool containsA = false;
            bool containsB = false;
            bool containsC = false;

            for(int j = 0, size = s.size(); i+j<size; j++)
            {
                if(s[i+j]=='a')
                containsA = true;

                if(s[i+j]=='b')
                containsB = true;

                if(s[i+j]=='c')
                containsC = true;

                if(containsA && containsB && containsC)
                {
                ans += s.size()-j-i;
                break;
                }
            }
        }
        return ans;
    }
};