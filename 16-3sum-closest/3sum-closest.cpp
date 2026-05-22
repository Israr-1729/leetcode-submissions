class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closestTarget;
        int minDifference = INT_MAX;

        for (int i = 0; i < size - 2; i++) {
            int j = i + 1;
            int k = size - 1;

            int Difference;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];
                Difference = abs(target - sum);
                if (Difference < minDifference)
                    {
                    minDifference = Difference;
                    closestTarget = sum;
                    }

                if (j < k && sum > target) {
                    k--;
                }

                else if (j < k && sum < target) {
                    j++;
                }

                else if (j < k && sum == target) {
                    return target;
                }
            }
        }
        return closestTarget;
    }
};