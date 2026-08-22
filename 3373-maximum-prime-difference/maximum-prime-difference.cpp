class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> primes;
        primes.insert(2);
        primes.insert(3);
        primes.insert(5);
        primes.insert(7);
        primes.insert(11);
        primes.insert(13);
        primes.insert(17);
        primes.insert(19);
        primes.insert(23);
        primes.insert(29);
        primes.insert(31);
        primes.insert(37);
        primes.insert(41);
        primes.insert(43);
        primes.insert(47);
        primes.insert(53);
        primes.insert(59);
        primes.insert(61);
        primes.insert(67);
        primes.insert(71);
        primes.insert(73);
        primes.insert(79);
        primes.insert(83);
        primes.insert(89);
        primes.insert(97);

        int startIDX = -1;
        int endIDX = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(primes.contains(nums[i]))
            {
                if(startIDX == -1)
                startIDX = i;

                else
                endIDX = i;
            }
        }

        if(endIDX == -1)
        return 0;

        return endIDX - startIDX;
    }
};