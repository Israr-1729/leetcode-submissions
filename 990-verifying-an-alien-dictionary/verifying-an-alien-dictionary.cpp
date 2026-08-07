class Solution {
public:

    vector<int> positions;

    void fillPosition(const string &order) 
    {
        positions.resize(26);
        int idx = 0;
        for(char c : order)
        {
            positions[c-'a'] = idx++;
        }
    }

    string convertor (const string & alienWord)
    {
        string englishWord = "";
        for(char c : alienWord)
        {
            englishWord += (positions[c-'a'] + 'a');
        }
        return englishWord;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        fillPosition(order);
        vector<string> englishDictionary;

        for(const string &a : words)
        {
            englishDictionary.push_back(convertor(a));
        }

        for(int i = 0; i < englishDictionary.size() - 1; i++)
        {
            if(englishDictionary[i] > englishDictionary[i+1])
            return false;
        }
        return true;
    }
};