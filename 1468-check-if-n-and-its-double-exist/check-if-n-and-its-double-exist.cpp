class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> copy;
        int numZeroes = 0;
        for(int a : arr)
        {
            copy.insert(a);

            if(a == 0)
            numZeroes++;
        }

        if(numZeroes > 1)
        return true; 
        
        for(int a : arr)
        {
            if(a == 0)
            continue;

            if(copy.contains(a * 2))
            return true;
        }
        return false;
    }
};