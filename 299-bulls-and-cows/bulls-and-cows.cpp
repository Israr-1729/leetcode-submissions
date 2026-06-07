class Solution {
public:
    string getHint(string secret, string guess) {
        multiset<int> remaining;
        int bulls = 0, cows = 0;

        // First pass: count bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                remaining.insert(secret[i] - '0');
            }
        }

        // Second pass: count cows
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i]) {
                auto it = remaining.find(guess[i] - '0');
                if (it != remaining.end()) {
                    cows++;
                    remaining.erase(it);
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};