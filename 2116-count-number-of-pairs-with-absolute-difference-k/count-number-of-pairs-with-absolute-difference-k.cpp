class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_set<string> indices;
        int size = nums.size();
        for(int i = 0; i < size-1; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                if(abs(nums[i] - nums[j]) == k)
                {
                    string toAdd = "";
                    toAdd += 'a' + i;
                    toAdd += 'a' + j;

                    indices.insert(toAdd);
                }
            }
        }
        return indices.size();
    }
};