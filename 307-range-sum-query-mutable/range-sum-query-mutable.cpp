class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int runningSum = 0;
        for(int a : nums)
        {
            runningSum += a;
            prefixSum.push_back(runningSum);
        }
    }
    
    void update(int index, int val) {
        int difference = ((index == 0) ? val - (prefixSum[0]) : (val - prefixSum[index] + prefixSum[index - 1]));

        for(int i = index; i < prefixSum.size(); i++)
        {
            prefixSum[i] += difference;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
        return prefixSum[right];

        else
        return prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */