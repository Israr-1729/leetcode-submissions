class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        int i = 0;
        int n = paragraph.size();

        while (i < n) {
            // Skip all non-letter characters
            while (i < n && !isalpha(paragraph[i]))
                i++;

            string word;

            // Read one word
            while (i < n && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
                i++;
            }

            if (!word.empty() && !bannedWords.contains(word))
                freq[word]++;
        }

        string ans;
        int maxFreq = 0;

        for (auto &[word, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                ans = word;
            }
        }

        return ans;
    }
};