class FindSumPairs {
public:

    unordered_map<int, int> copy1;
    unordered_map<int, int> copy2;
    vector<int> arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr2 = nums2;

        for(int a : nums1)
        copy1[a]++;

        for(int a : nums2)
        copy2[a]++;
    }
    
    void add(int index, int val) {
        copy2[arr2[index]]--;
        arr2[index] += val;
        copy2[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &a : copy2)
        {
            int compliment = tot - a.first;
            if(copy1.contains(compliment))
            ans+=copy1[compliment] * a.second;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */