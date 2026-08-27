class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int size1 = word1.size();
        int size2 = word2.size();
        string result = "";

        while(i < size1 && i < size2)
        {
            result += word1[i];
            result += word2[i];

            i++;
        }

        while(i < size1)
        {
            result += word1[i];
            i++;
        }

        while(i < size2)
        {
            result += word2[i];
            i++;
        }

        return result;
        
    }
};