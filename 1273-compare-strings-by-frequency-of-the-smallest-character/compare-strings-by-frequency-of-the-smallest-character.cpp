class Solution {
public:
    
    int helper(string s)
    {
        vector<int> freq(26);
        for(char c : s)
        freq[c-'a']++;

        for(int i = 0; i<26; i++)
        {
            if(freq[i]!=0)
            return freq[i];
        }
        return -1;
    }
    
    
    vector<int> fSmallest(vector<string> &arr)
    {
        int size = arr.size();
        vector<int> result(size);
        for(int i = 0; i<size; i++)
        {
            result[i] = helper(arr[i]);
        }
        return result;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fQueries = fSmallest(queries);
        vector<int> fWords = fSmallest(words);

        int queriesSize = queries.size();
        int wordsSize = words.size();

        vector<int> result(queriesSize);

        for(int i = 0; i<queriesSize; i++)
        {
            int count = 0;
            for(int j = 0; j<wordsSize; j++)
            {
                if(fQueries[i]<fWords[j])
                count++;
            }
            result[i] = count;
        }
        return result;
    }
};