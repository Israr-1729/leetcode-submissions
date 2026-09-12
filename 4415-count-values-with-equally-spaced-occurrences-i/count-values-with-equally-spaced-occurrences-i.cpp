class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]].push_back(i);
        }
        
        int count = 0;
        for(auto &a : indices)
        {
            const vector<int> &i = a.second;
            if(i.size() == 3 && i[2]-i[1] == i[1] - i[0])
            {
                count++;
            }
        }
        return count;
    }
};