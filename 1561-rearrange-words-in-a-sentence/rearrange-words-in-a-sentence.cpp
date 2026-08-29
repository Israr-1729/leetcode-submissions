class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> mp;
        int i = 0; int size = text.size();
        while(i < size)
        {
            string newWord = "";
            int idx = i;
            while(idx < size && text[idx] != ' ')
            {
                newWord += tolower(text[idx]);
                idx++;
            }
            mp[newWord.size()].push_back(newWord);
            i = idx+1;
        }

        string result = "";
        for(auto &a : mp)
        {
            const vector<string> &words = a.second;
            for(const string &s : words)
            {
                result += s;
                result += " ";
            }
        }
        result.pop_back();
        result[0] = toupper(result[0]);

        return result;
    }
};