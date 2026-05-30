class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> nums2;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            nums2.insert(nums[i]);
        }
        for(int i = 1; i>0; i++)
        {
            if(nums2.find(i)==nums2.end())
            {
                return i;
                break;
            }
        }
        return 1;
    }
};