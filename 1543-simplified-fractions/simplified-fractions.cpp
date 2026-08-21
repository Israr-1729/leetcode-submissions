class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(gcd(i, j) == 1)
                {
                    string thisResult = "";
                    thisResult += to_string(j);
                    thisResult += '/';
                    thisResult += to_string(i);

                    result.push_back(thisResult);
                }
            }
        }
        return result;
    }
};