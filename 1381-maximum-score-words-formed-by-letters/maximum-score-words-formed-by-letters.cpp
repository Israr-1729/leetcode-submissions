class Solution {
public:
    int dfs(int index, vector<string>& words, vector<int>& lettersFreq,
            vector<int>& score) {

        if (index == words.size())
            return 0;

        // Option 1: Skip this word
        int notTake = dfs(index + 1, words, lettersFreq, score);

        // Count letters and score of current word
        vector<int> need(26, 0);
        int wordScore = 0;
        bool possible = true;

        for (char c : words[index]) {
            need[c - 'a']++;
            wordScore += score[c - 'a'];

            if (need[c - 'a'] > lettersFreq[c - 'a'])
                possible = false;
        }

        int take = 0;

        if (possible) {
            // Use the letters
            for (int i = 0; i < 26; i++)
                lettersFreq[i] -= need[i];

            take = wordScore + dfs(index + 1, words, lettersFreq, score);

            // Backtrack
            for (int i = 0; i < 26; i++)
                lettersFreq[i] += need[i];
        }

        return max(take, notTake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        vector<int> lettersFreq(26, 0);

        for (char c : letters)
            lettersFreq[c - 'a']++;

        return dfs(0, words, lettersFreq, score);
    }
};