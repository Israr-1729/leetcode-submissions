class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> nextGreater;
        unordered_map<int, int> Map;
        int size2 = nums2.size();
        for(int i = size2-1; i>=0; i--)
        {
            while(nextGreater.size()!=0 && nextGreater.top()<=nums2[i])
            {
                nextGreater.pop();
            }
            if(nextGreater.empty())
            Map[nums2[i]] = -1;
            else
            Map[nums2[i]] = nextGreater.top();

            nextGreater.push(nums2[i]);
        }
        int size1 = nums1.size();
        vector<int> result(size1);
        for(int i = 0; i<size1; i++)
        {
            result[i] = Map[nums1[i]];
        }
        return result;
    }
};