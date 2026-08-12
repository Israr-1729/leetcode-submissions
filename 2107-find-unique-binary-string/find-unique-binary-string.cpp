class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums[0].size();
        unordered_set<string> copy;
        for(string &s : nums)
        {
            copy.insert(s);
        }

        string ans (size, '0');

        while(copy.contains(ans))
        {
            ans = string (size, '0');
        for(char &c : ans)
        {
            int x = rand() % 2 + 1;

            if(x == 2)
            c = '1';
        }
        }

        return ans;
        
    }
};