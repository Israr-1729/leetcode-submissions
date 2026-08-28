class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr = 1;
        int idx = 0;
        vector<string> result;
        while(idx < target.size())
        {
            while(target[idx] != curr)
            {
                curr++;
                result.push_back("Push");
                result.push_back("Pop");

                if(curr > n)
                break;
            }

            if(target[idx] == curr)
            {
                result.push_back("Push");
                idx++;
                curr++;
            }
        }
    return result;
    }
};