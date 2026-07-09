class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int size = nums.size();
        vector<int> digitRanges(size);

        int maxDigitDiff = INT_MIN;
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int maxDigit = 0;
            int minDigit = 9;
            while (num > 0) {
                int digit = num % 10;
                maxDigit = max(maxDigit, digit);
                minDigit = min(minDigit, digit);
                num /= 10;
            }

            digitRanges[i] = maxDigit - minDigit;
            maxDigitDiff = max(maxDigitDiff, digitRanges[i]);
        }

        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (digitRanges[i] == maxDigitDiff)
                ans += nums[i];
        }
        return ans;
    }
};