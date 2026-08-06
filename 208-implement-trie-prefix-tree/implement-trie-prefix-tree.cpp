class Trie {
public:
    unordered_set<string> s;
    vector<string> sCopy;
    Trie() {
        
    }
    
    void insert(const string &word) {
        if(!s.contains(word))
        {
        s.insert(word);
        sCopy.push_back(word);
        }
    }
    
    bool search(const string &word) {
        if(s.contains(word))
        return true;

        return false;
    }
    
    bool startsWith(const string &prefix) {
        for(const string &a : sCopy)
        {
            if(a.starts_with(prefix))
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */