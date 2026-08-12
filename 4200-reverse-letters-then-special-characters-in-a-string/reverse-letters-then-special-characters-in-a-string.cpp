class Solution {
public:
    string reverseByType(string s) {
        vector<int> specialIndices;
        vector<int> lowerIndices;

        string allLower = "";
        string allSpecial = "";

        for(int i = 0; i<s.size(); i++)
        {
            if(islower(s[i])) {
            lowerIndices.push_back(i);
            allLower += s[i];
            }

            else {
            specialIndices.push_back(i);
            allSpecial += s[i];
            }
        }

        reverse(allLower.begin(), allLower.end());
        reverse(allSpecial.begin(), allSpecial.end());

        string result(s.size(), 'a');

        int idx = 0;

        for(int a : lowerIndices)
        {
            result[a] = allLower[idx++];
        }

        idx = 0;
        for(int a : specialIndices)
        {
            result[a] = allSpecial[idx++];
        }


        return result;
    }
};