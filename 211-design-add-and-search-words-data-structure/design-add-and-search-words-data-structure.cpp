class WordDictionary {
public:
    unordered_set<string> dic;

    WordDictionary() {}

    void addWord(string word) {
        dic.insert(word);
    }

    bool search(string word) {
        if (dic.contains(word))
            return true;

        int firstDot = -1;
        int secondDot = -1;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                if (firstDot == -1)
                    firstDot = i;
                else {
                    secondDot = i;
                    break;
                }
            }
        }

        if (firstDot == -1)
            return false;

        // One dot
        if (secondDot == -1) {
            for (char c = 'a'; c <= 'z'; c++) {
                word[firstDot] = c;

                if (dic.contains(word))
                    return true;
            }

            return false;
        }

        // Two dots
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            word[firstDot] = c1;

            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                word[secondDot] = c2;

                if (dic.contains(word))
                    return true;
            }
        }

        return false;
    }
};