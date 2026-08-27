class Solution {
public:
void kRotation(vector<int>& nums, int k)
{
    if (nums.empty())
        return;

    k %= nums.size();

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}

    vector<int> rotateElements(vector<int>& nums, int k) {
        unordered_set<int> negativeIndices;
        vector<int> positiveAndZero;
        vector<int> negative;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                negativeIndices.insert(i);
                negative.push_back(nums[i]);
            }
            else
            {
                positiveAndZero.push_back(nums[i]);
            }
        }

            kRotation(positiveAndZero, k);
        

        int nIDX = 0; int pIDX = 0;

        vector<int> result(nums.size(), 0);
        for(int i = 0; i<nums.size(); i++)
        {
            if(!negativeIndices.contains(i))
            {
                result[i] = positiveAndZero[pIDX++];
            }

            else
            {
                result[i] = negative[nIDX++];
            }
        }
        return result;
    }
};