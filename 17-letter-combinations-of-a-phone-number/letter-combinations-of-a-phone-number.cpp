class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};


        vector<string> result = {""};
        for(char c : digits)
        {

            vector<string> copy = result;
            result = {};
            for(string &s : copy)
            {
                for(char a : mp[c])
                result.push_back(s + a);
            }
        }
        return result;
    }
};