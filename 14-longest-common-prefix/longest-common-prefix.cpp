class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        int common = strs[0].size();
        int size = strs.size();


        for(int i = 0; i<size-1; i++)
        {
            int counter = 0;

            while(counter<strs[i].size() && counter<strs[i+1].size() && strs[i][counter]==strs[i+1][counter])
            {
                counter++;
            }

            if(counter<common)
            common = counter;
            
        }

        if(size == 0 || common==0)
        return "";
        else
        {
        string result;
        for(int j = 0; j<common; j++)
        result.push_back(strs[0][j]);
        return result;
        }
    }
};