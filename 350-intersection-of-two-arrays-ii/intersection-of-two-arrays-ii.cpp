class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;

        for(int a : nums1)
        {
            freq1[a]++;
        }

        for(int a : nums2)
        {
            freq2[a]++;
        }

        vector<int> result;
        for(auto &p : freq1)
        {
            if(!freq2.contains(p.first))
            continue;
            int occIn1 = p.second;
            int occIn2 = freq2[p.first];

            for(int i = 0; i<min(occIn1, occIn2); i++)
            {
                result.push_back(p.first);
            }
        }
    return result;  
    }
};