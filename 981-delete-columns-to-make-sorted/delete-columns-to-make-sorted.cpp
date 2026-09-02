class Solution {
public:
    bool isSorted(vector<int> nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int deletions = 0;
        for(int idx = 0; idx < strs[0].size(); idx++)
        {
            vector<int> toCheck;
            for(const string &s : strs)
            {
                toCheck.push_back(s[idx]);
            }
            if(isSorted(toCheck))
            deletions++;
        }
        return strs[0].size()-deletions;
    }
};