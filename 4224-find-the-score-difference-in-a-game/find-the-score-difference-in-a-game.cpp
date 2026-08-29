class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool ATakes = true;
        int scoreA = 0; int scoreB = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 1)
            {
                ATakes = !ATakes;
            }

            if((i+1) % 6 == 0) 
            {
                ATakes = !ATakes;
            }

            if(ATakes)
            {
                scoreA += nums[i];
            }

            else if(!ATakes)
            {
                scoreB += nums[i];
            }

        }
        return (scoreA-scoreB);
    }
};