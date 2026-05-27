class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowerSeen(26, false);
        vector<bool> upperSeen(26, false);
        vector<bool> counted(26, false);
        vector<bool> invalid(26, false);

        int count = 0;

        for (char ch : word) {
            int idx = tolower(ch) - 'a';

            if (islower(ch)) {
                // lowercase after uppercase => invalidate
                if (upperSeen[idx]) {
                    if (counted[idx]) {
                        count--;
                        counted[idx] = false;
                    }
                    invalid[idx] = true;
                }

                lowerSeen[idx] = true;
            } 
            else { // uppercase
                upperSeen[idx] = true;

                if (lowerSeen[idx] &&
                    !counted[idx] &&
                    !invalid[idx]) {
                    count++;
                    counted[idx] = true;
                }
            }
        }

        return count;
    }
};