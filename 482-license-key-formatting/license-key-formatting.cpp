class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        bool allDash = true;
        for(char c : s)
        {
            if(c != '-')
            {
                allDash = false;
                break;
            }
        }

        if(allDash)
        return "";

        int alphaNumericCount = 0;
        for(char c : s)
        {
            if(c != '-')
            {
                alphaNumericCount++;
            }
        }

        string result = "";

        int count = 0;
        for(int i = s.size()-1; i >=0; i--)
        {
            if(s[i] == '-')
            continue;

            else
            {
                result.push_back(toupper(s[i]));
            }
            

            count++;
            if(count == k && i!=0)
            {
                result.push_back('-');
                count = 0;
            }
        }


        if(result[result.size()-1] == '-' && s != "-")
        result.pop_back();


        reverse(result.begin(), result.end());
        return result;
    }
};