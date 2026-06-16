class Solution {
public:


    vector<string> wordsGenerator(string &s)
    {
        int size = s.size();
        vector<string> copy;
        int i = 0;
        while(i<size)
        {
            string thisString = "";
            while(i<size && s[i]!=' ')
            {
                thisString += s[i];
                i++;
            }
            copy.push_back(thisString);
            i++;
        }
        return copy;
    }

    int maxSiz(vector<string> &copy)
    {
        int maxS = 0;
        for(int i = 0; i<copy.size(); i++)
        {
            int size = copy[i].size();
            maxS = max(maxS, size);
        }
        return maxS;
    }

    void removeTrailingSpaces(vector<string> &copy)
    {
        for(string &s : copy)
        {
            while(s[s.size()-1]==' ')
            s.pop_back();
        }
    }

    vector<string> printVertically(string s) {
        vector<string> copy = wordsGenerator(s);
        int maxSize = maxSiz(copy);
        vector<string> result;

        for(int i = 0; i<maxSize; i++)
        {
            string thisResult = "";
            for(int j = 0; j<copy.size(); j++)
            {
                if(i<copy[j].size())
                thisResult += copy[j][i];
                else
                thisResult += ' ';
            }
            result.push_back(thisResult);
        }
        removeTrailingSpaces(result);
    return result;
    }    
};