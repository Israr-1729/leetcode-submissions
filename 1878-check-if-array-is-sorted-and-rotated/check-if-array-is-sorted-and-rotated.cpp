class Solution {
public:
    bool check(vector<int>& nums) {
        int counter = 0; int size = nums.size(); 


        //for special cases:
        if(size==0 || size == 1)
        return true;

        //for a rotated sorted array, the maximum number of times a[i]>a[i+1] will be 1. It can be zero of number of rotations are zero.

        for(int i = 0; i<size-1; i++)
        {
            if (nums[i]>nums[i+1])
            {
                counter++;
            }
            if(counter>1)
            return false;
        }
        if(counter==1 && nums[size-1]>nums[0])//for a case like 2,1,3,4
        return false;

        return true;
    }
};