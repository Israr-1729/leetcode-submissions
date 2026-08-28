class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string start = "";

        for(int i = 0; i < target.size(); i++)
        {
            start.push_back(' ');
            int idx = 'a';
            while(start[start.size()-1] != target[i])
            {
                start[start.size()-1] = idx++;
                result.push_back(start);
            } 
        }
        return result;
    }
};