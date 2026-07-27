class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> se;
        for(char c : s)
        {
            if(se.contains(c))
            return c;

            se.insert(c);
        }
        return 'a';
    }
};