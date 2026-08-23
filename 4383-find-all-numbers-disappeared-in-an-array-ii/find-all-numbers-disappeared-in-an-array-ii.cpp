class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> numsCopy;
        for(int i : nums)
        {
            numsCopy.insert(i);
        }

        int i = lower;
        vector<vector<int>> result = {};
        while(i <= upper)
        {
            while(i <= upper && numsCopy.contains(i))
            i++;

            if(!numsCopy.contains(i))
            {
                vector<int> newMissing = {i, i};
                while(i <= upper && !numsCopy.contains(i))
                {
                    i++;
                }

                if(i > upper + 1 || newMissing[0] > i-1)
                continue;

                newMissing[1] = i-1;


                result.push_back(newMissing);
            }
        }


        return result;
    }
};