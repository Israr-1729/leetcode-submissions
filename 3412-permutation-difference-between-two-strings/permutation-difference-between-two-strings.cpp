class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> sCopy;

        int size = s.size(); 

        for(int i = 0; i<size; i++)
        {
            sCopy[s[i]] = i;
        }

        int result = 0;
        for(int i = 0; i<size; i++)
        {
            result += abs(sCopy[t[i]]-i);
        }
        return result;
    }
};