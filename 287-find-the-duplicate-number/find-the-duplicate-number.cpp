class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> thisSeen;
        for(int a : nums)
        {
            if(thisSeen.find(a)!=thisSeen.end())
            return a;
            else 
            thisSeen.insert(a);
        }
        return -1;
    }
};