class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int sum = 0; int size = nums.size(); 
        for(int i = 0; i<size; i++)
        {
            sum+=nums[i];
        }     
        return sum%k;   
    }
};