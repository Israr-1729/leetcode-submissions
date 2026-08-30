class Solution {
public:
    string reverseStr(string s, int k) {
        string result = "";
        bool toReverse = true;
        for(int i = 0; i < s.size(); i+=k)
        {
            string toAdd;
            if(i + k <= s.size())
            toAdd = s.substr(i, k);

            else
            toAdd = s.substr(i, s.size()-i+1);

            if(toReverse)
            reverse(toAdd.begin(), toAdd.end());

            result += toAdd;
            toReverse = !toReverse;
        }
        
        return result;
    }
};