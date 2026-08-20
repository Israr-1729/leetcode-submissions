class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string withoutDashes = "";
        for(char c : s)
        {
            if(c!='-')
            withoutDashes.push_back(c);
        }

        string result = "";
        int blockCount = 0;
        for(int i = withoutDashes.size()-1; i >= 0; i--)
        {
            result.push_back(toupper(withoutDashes[i]));
            blockCount++;
            if(blockCount == k)
            {
                result.push_back('-');
                blockCount = 0;
            }
        }
        
        if(result == "")
        return result; 
        
        if(result.back() == '-')
        result.pop_back();

        reverse(result.begin(), result.end());
        return result;
    }
};