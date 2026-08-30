class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        unordered_map<double, pair<int, int>> decimalToIndices;
        vector<double> decimals;

        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i+1; j < arr.size(); j++)
            {
                double value = (double)arr[i]/arr[j];
                decimalToIndices[value] = {arr[i], arr[j]};
                decimals.push_back(value);
            }
        }
        sort(decimals.begin(), decimals.end());
        double toFindValue = decimals[k-1];

        return {decimalToIndices[toFindValue].first, decimalToIndices[toFindValue].second};
        
    }
};