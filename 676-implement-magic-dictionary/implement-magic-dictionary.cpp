class MagicDictionary {
public:

    unordered_set<string> words;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(const string &s : dictionary)
        words.insert(s);
    }
    
    bool search(string searchWord) {
        for(int j = 0; j < searchWord.size(); j++)
        {
            for(int i = 0; i<26; i++)
            {
                if(i + 'a' == searchWord[j])
                continue; 

                string buffer = searchWord;
                searchWord[j] = i + 'a';

                if(words.contains(searchWord))
                return true;

                searchWord = buffer;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */