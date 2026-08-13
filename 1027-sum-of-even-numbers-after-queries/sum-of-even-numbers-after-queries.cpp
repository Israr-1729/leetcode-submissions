class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;

        long long orgSum = 0;
        for(int i : nums)
        {
            if(i % 2 == 0)
            orgSum += i;
        }

        for(auto &v : queries)
        {
            //If original value is odd
            if(nums[v[1]] % 2 != 0)
            {
                nums[v[1]] += v[0];

                //If original value becomes even now
                if(nums[v[1]] % 2 == 0)
                {
                    orgSum += nums[v[1]];
                } 
            }

            //If orginal value is even
            else if(nums[v[1]] % 2 == 0)
            {
                orgSum -= nums[v[1]];

                nums[v[1]] += v[0];

                //If original value becomes even again

                if(nums[v[1]] % 2 == 0)
                {
                    orgSum += nums[v[1]];
                }
            }
        result.push_back(orgSum);
        }
        return result;
    }
};