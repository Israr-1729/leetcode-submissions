class Solution {
public:

    int smallestRemainder(int remainder, const vector<int> &ones, const vector<int> &twos)
    {
        if(remainder == 1) //Need one ones or two twos.
        {
            if(twos.size() < 2 && ones.empty())
            return -1;

            else if(twos.size() < 2 && !ones.empty())
            return ones[0];

            else if(twos.size() >= 2 && ones.empty())
            return twos[0] + twos[1];

            else
            return min(ones[0], twos[0] + twos[1]);
        }

        if(remainder == 2) //Need one twos or two ones.
        {
            if(ones.size() < 2 && twos.empty())
            return -1;

            else if(ones.size() < 2 && !twos.empty())
            return twos[0];

            else if(ones.size() >= 2 && twos.empty())
            return ones[0] + ones[1];

            else
            return min(twos[0], ones[0] + ones[1]);
        }
return -1;
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<int> smallestRemainder1;
        vector<int> smallestRemainder2;
        long long totalSum = 0;
        sort(nums.begin(), nums.end());
        for(int i : nums)
        {
            totalSum += i;

            if(i % 3 == 1)
            {
                smallestRemainder1.push_back(i);
            }

            else if(i % 3 == 2)
            {
                smallestRemainder2.push_back(i);
            }
        }

        if(totalSum % 3 == 0)
        {
            return totalSum;
        }

        if(totalSum % 3 == 1)
        {
            int toSubtract = smallestRemainder(1, smallestRemainder1, smallestRemainder2);
            if(toSubtract == -1)
            return 0;
            return totalSum - toSubtract;
        }

        if(totalSum % 3 == 2)
        {
            int toSubtract = smallestRemainder(2, smallestRemainder1, smallestRemainder2);
            if(toSubtract == -1)
            return 0;
            return totalSum - toSubtract;
        }
        
        return 0;
    }
};