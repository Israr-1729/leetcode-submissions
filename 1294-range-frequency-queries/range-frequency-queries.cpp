class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> nums;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i<arr.size(); i++)
        {
            nums[arr[i]].push_back(i);
        }

    }
    
int query(int left, int right, int value) {
    const vector<int> &arr = nums[value];

    int leftIndex = lower_bound(arr.begin(), arr.end(), left) - arr.begin();
    int rightIndex = upper_bound(arr.begin(), arr.end(), right) - arr.begin() - 1;

    if (leftIndex > rightIndex)
        return 0;

    return rightIndex - leftIndex + 1;
}
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */