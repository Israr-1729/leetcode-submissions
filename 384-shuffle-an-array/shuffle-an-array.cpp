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
        random_device rd;
        mt19937 g(rd());

        std::shuffle(arr.begin(), arr.end(), g);

        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */