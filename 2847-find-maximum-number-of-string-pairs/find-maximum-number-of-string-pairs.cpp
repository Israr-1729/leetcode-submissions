class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {

        unordered_set<string> history;
        int count = 0;

        for(auto &a : words)
        {
            string rev = a;
            reverse(rev.begin(), rev.end());

            if(history.contains(rev))
            count++;

            history.insert(a);
        }
       return count; 
    }
};