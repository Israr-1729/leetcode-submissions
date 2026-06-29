class Solution {
public:

//4-3 + 5-4 + 5-3
//2(5-3)
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            indices[nums[i]].push_back(i);
        }

        int minimum = INT_MAX;
        bool goodTupleExists = false;
        for(auto &p : indices)
        {
            if(p.second.size()<3)
            continue;

            else
            {
                goodTupleExists = true;
                for(int i = 1; i<p.second.size()-1; i++)
                {
                    minimum = min(minimum, 2*(p.second[i+1]-p.second[i-1]));
                }
            }
        }
        return goodTupleExists ? minimum : -1;
    }
};