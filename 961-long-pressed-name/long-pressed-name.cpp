class Solution {
public:
    vector<string> blockMaker(const string &s)
    {
        int i = 0; int size = s.size();
        vector<string> result;
        while(i < size)
        {
            string newBlock = "";
            char toCheck = s[i];

            while(s[i] == toCheck)
            {
                newBlock += s[i];
                i++;
            }
            result.push_back(newBlock);
        }
        return result;
    }
    bool isLongPressedName(string name, string typed) {
        const vector<string> &nBlock = blockMaker(name);
        const vector<string> &tBlock = blockMaker(typed);

        if(nBlock.size() != tBlock.size())
        return false;

        for(int i = 0; i < nBlock.size(); i++)
        {
            if(tBlock[i][0] != nBlock[i][0] || tBlock[i].size() < nBlock[i].size())
            return false;
        }
        return true;
    }
};