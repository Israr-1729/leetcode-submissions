class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int numEven = 0;
        int numOdd = 0;

        for(int i : nums)
        {
            if(i % 2 == 0)
            numEven++;

            else
            numOdd++;
        }

        vector<int> result(numEven, 0);

        for(int i = 0; i < numOdd; i++)
        {
            result.push_back(1);
        }
        
        return result;
    }
};