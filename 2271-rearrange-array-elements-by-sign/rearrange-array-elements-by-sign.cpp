class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int>Positive(size/2);
        vector<int>Negative(size/2);
        vector<int>Result(size);

        int idxP = 0;
        int idxN = 0;
        for(int i = 0; i<size; i++)
        {
            if(nums[i]>0)
            {
                Positive[idxP] = nums[i];
                idxP++;
            }
            else
            {
                Negative[idxN] = nums[i];
                idxN++;
            }
        }
        idxP = 0;
        idxN = 0;
        for(int i = 0; i<size; i++)
        {
            Result[i] = i%2==0 ? Positive[idxP++] : Negative[idxN++];
        }
        return Result;
    }
};