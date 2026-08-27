class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        map<int, vector<string>> mp;
        for(auto &a : nums)
        {
            mp[a.size()].push_back(a);
        }

        vector<vector<string>> numbers; 
        for(auto &a : mp)
        {
            numbers.push_back(a.second);
        }

        reverse(numbers.begin(), numbers.end());

        for(auto &a : numbers)
        {
            sort(a.rbegin(), a.rend());
        }

        vector<string> final;

        for(auto &a : numbers)
        {
            for(const string &s : a)
            {
                final.push_back(s);
            }
        }


        return final[k-1];


        
    }
};