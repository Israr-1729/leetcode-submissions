class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int larger = 0;

        for(int i : nums)
        {
            if(i > target)
            larger++;

            if(i < target)
            smaller++;
        }

        int numOfTarget = nums.size()-smaller-larger;

        vector<int> result;
        for(int i = 0; i < numOfTarget; i++)
        {
            result.push_back(i+smaller);
        }
        return result;
    }
};