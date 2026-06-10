class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int stringSize = s.size();
        string result = "";

        int spacesSize = spaces.size(); int idx = 0;
        for(int i = 0; i<stringSize; i++)
        {
            if((idx < spacesSize && i!=spaces[idx])||(idx >= spacesSize))
            result += (s[i]);

            else
            {
                idx++;
                result += ' ';
                result += s[i];
            }
        }   
    return result;  
    }
};