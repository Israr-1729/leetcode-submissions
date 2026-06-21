class Solution {
public:

    bool isSorted(vector<vector<int>> &arr)
    {
        int size = arr.size();
        for(int i = 0; i<size-1; i++)
        {
            if(arr[i][0]<arr[i+1][0])
            return false;
        }
        return true;
    }

    vector<vector<int>> sortRecursively(vector<vector<int>> &arr)
    {
        if(isSorted(arr))
        return arr;
        int size = arr.size();
        for(int i = 0; i<size-1; i++)
        {
            if(arr[i][0]<arr[i+1][0])
            swap(arr[i], arr[i+1]);
        }
        return sortRecursively(arr);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int a : nums)
        {
            freq[a]++;
        }
        vector<vector<int>> freqVector;
        for(auto &a : freq)
        {
            freqVector.push_back({a.second, a.first});
        }

        sortRecursively(freqVector);
        int idx = 0;
        int i = 0; int j = 0;
        vector<int> result(k);
        while(i<k)
        {
            result[idx++] = freqVector[j++][1];
            i++;
        }
    return result;
    }
};