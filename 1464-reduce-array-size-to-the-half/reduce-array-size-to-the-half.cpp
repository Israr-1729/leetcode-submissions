class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int arrSize = arr.size();
        unordered_map<int, int> freq;
        for(int a : arr)
        freq[a]++;

        vector<int> frequencies; 
        for(auto &p : freq)
        {
            frequencies.push_back(p.second);
        }

        sort(frequencies.begin(), frequencies.end());
        
        int counter = 0;
        int size = frequencies.size();
        int sum = 0;

        for(int i = size-1; i>=0; i--)
        {
            sum += frequencies[i];
            counter++;
            if(sum>=arrSize/2)
            break;
        }
        return counter;
    }
};