class Solution {
public:
    vector<int> result;
    vector<int> rearrangeArray(vector<int>& nums) {
        if(nums.size() == 0)
        return result;

        sort(nums.begin(), nums.end());
        int size = nums.size();
        int i = 0;
        vector<int> unused;
        while(i < size)
        {
            int newNum = nums[i];
            result.push_back(newNum);
            i++;
            while(i < size && nums[i] == newNum)
            {
                unused.push_back(newNum);
                i++;
            }
        }
        return rearrangeArray(unused);
    }
};