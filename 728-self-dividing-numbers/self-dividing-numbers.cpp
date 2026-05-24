class Solution {
public:

    bool isSelfDividing(int i)
    {
        int copy = i;
        while(i>0)
        {
            if(i%10 == 0)
            return false;
            if((copy)%(i%10)!=0)
            return false;
            i/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int>result;
        for(int i = left; i<=right; i++)
        {
            if(isSelfDividing(i))
            result.push_back(i);
        }
        return result;
    }
};