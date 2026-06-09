
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp; // value -> index

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;

        int idx = mp[val];
        int lastVal = nums.back();

        // move last element to idx
        nums[idx] = lastVal;
        mp[lastVal] = idx;

        // remove last
        nums.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
};