class Solution {
public:
    vector<int> arr;
    vector<int> org;
    int size;
    Solution(vector<int>& nums) {
        arr = nums;
        org = nums;
        size = nums.size();
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        vector<int> &v = arr;
for(int i = v.size() - 1; i > 0; i--)
{
    int j = rand() % (i + 1);
    swap(v[i], v[j]);
}   return v;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */