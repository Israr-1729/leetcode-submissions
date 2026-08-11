class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //Larger is arr2

        if(arr1.size() > arr2.size())
        return longestCommonPrefix(arr2, arr1);

        unordered_set<int> copy2;
        for(int a : arr2)
        {
            while(a)
            {
                copy2.insert(a);
                a/=10;
            }
        }

        vector<int> copy1;
        for(int a : arr1)
        {
            while(a)
            {
                copy1.push_back(a);
                a/=10;
            }
        }


        int maxLength = 0;
        for(int a : copy1)
        {
            if(copy2.contains(a) && to_string(a).size() > maxLength)
            {
                maxLength = to_string(a).size();
            }
        }
    return maxLength;
    }
};