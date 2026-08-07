class Solution {
public:
    bool oneCharacterEvenFrequency(const string& s) {
        vector<int> sCopy(26, 0);

        for (char c : s) {
            sCopy[c - 'a']++;
        }

        for (int a : sCopy) {
            if (a != 0 && a >= 2)
                return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        int count = 0;

        vector<char> sMismatch;
        vector<char> goalMismatch;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                count++;
                sMismatch.push_back(s[i]);
                goalMismatch.push_back(goal[i]);
            }

            if (count > 2)
                return false;
        }

        if (count == 0) {
            if (s != goal)
                return false;

            return oneCharacterEvenFrequency(s);
        }

        if (count != 2)
            return false;

        // if(uniqueS.size() == 1 && s==goal)
        // return true;

        return (sMismatch[0] == goalMismatch[1] &&
                sMismatch[1] == goalMismatch[0]);
    }
};