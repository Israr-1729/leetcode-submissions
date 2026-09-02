class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for(auto &a : words)
        {
            int i = 0; int size = a.size();
            while(i < size)
            {
                while(i < size && a[i] == separator)
                i++;

                string newWord = "";
                while(i < size && a[i] != separator)
                {
                    newWord += a[i];
                    i++;
                }
                if(!newWord.empty())
                result.push_back(newWord);

            }
        }
        return result;
    }
};