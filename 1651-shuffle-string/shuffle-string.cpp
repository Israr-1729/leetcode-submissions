class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string newString(s.size(), 'a');
        for(int i = 0; i<s.size(); i++)
        {
            newString[indices[i]] = s[i];
        }
        return newString;
    }
};