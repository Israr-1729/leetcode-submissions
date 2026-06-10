class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occurences;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            if(nums[i]==x)
            occurences.push_back(i);
        }

        int queriesSize = queries.size();
        int occurenceSize = occurences.size();
        vector<int> result;
        for(int i = 0; i<queriesSize; i++)
        {
            if(queries[i]>occurenceSize)
            result.push_back(-1);
            else
            result.push_back(occurences[queries[i]-1]);
        }
        return result;
    }
};