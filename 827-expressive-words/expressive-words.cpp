class Solution {
public:
    vector<string> blocks(const string& s) {
        vector<string> result;
        int i = 0;
        int size = s.size();
        while (i < size) {
            char toCheck = s[i];
            string newBlock = "";

            while (i < size && s[i] == toCheck) {
                newBlock += toCheck;
                i++;
            }

            result.push_back(newBlock);
        }

        return result;
    }

    bool compare(const vector<string> &mainBlock, const vector<string> &toCheck) {
        if (mainBlock.size() != toCheck.size())
            return false;

        for (int i = 0; i < mainBlock.size(); i++) {
            const string& s1 = mainBlock[i];
            const string& s2 = toCheck[i];

            if (s1[0] != s2[0] || s1.size() < s2.size() ||
                (s1.size() < 3 && s1.size() != s2.size())) {
                return false;
            }
        }

        return true;
    }

    int expressiveWords(string s, vector<string>& words) {
        vector<string> mainBlock = blocks(s);
        int count = 0;
        for (auto& i : words) {
            const vector<string>& toCompare = blocks(i);
            if (compare(mainBlock, toCompare))
                count++;
        }
        return count;
    }
};