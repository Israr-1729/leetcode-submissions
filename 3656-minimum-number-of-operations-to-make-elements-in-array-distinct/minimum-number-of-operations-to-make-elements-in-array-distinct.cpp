class Solution {
public:

    int num = 0;
    bool isDistinct(vector<int> & nums)
    {
        unordered_set<int> isSeen;
        for(int a : nums)
        {
            if(isSeen.contains(a))
            return false;
            isSeen.insert(a);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {

        if(isDistinct(nums))
        return num;

        if(nums.size()<=3)
        return num+1;

        reverse(nums.begin(), nums.end());
        nums.pop_back(); nums.pop_back(); nums.pop_back();
        reverse(nums.begin(), nums.end());

        num++;

        return minimumOperations(nums);
        
    }
};