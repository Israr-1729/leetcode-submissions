class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> seen;

        for(int num : nums) {
            seen.insert(num);

            int reversed = 0;
            int copy = num;

            while(copy != 0) {
                reversed = reversed * 10 + copy % 10;
                copy /= 10;
            }

            seen.insert(reversed);
        }

        return seen.size();
    }
};