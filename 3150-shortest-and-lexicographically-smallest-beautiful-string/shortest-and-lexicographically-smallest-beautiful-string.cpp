class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int minSize = INT_MAX;

        for(int i = 0; i < s.size(); i++)
        {
            int onesCount = 0;

            for(int j = i; j < s.size(); j++)
            {
                if(s[j] == '1')
                    onesCount++;

                if(onesCount == k)
                {
                    string newAns = s.substr(i, j-i+1);

                    if(j-i+1 < minSize)
                    {
                        ans = newAns;
                        minSize = j-i+1;
                    }
                    else if(j-i+1 == minSize && newAns < ans)
                    {
                        ans = newAns;
                    }

                    break;
                }
            }
        }

        return ans;
    }
};