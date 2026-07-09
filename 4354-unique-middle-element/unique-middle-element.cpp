class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int middle = nums[(nums.size()-1)/2];
        int count = 0;
        for(int a : nums)
        {
            if(a==middle)
            count++;
        }
        return count == 1;
    }
};