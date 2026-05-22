class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        int size = nums.size();
       /* for(int j = 0; j<size-1; j++)
        {
            if(nums[j]==nums[j+1])
            counter++;
        }*/
        
        
        
        
        for(int i= 1; i<size; i++)
        {
            while(nums[i]==nums[i-1])
            {
                nums[i-1] = INT_MAX;
                counter++;
            }
        }
        sort(nums.begin(), nums.end());

        return size- counter;
        
        
    }
};