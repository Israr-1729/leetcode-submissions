class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int lrSize = l.size();
        vector<bool> result(lrSize, true);
        for(int i = 0; i<lrSize; i++)
        {
            int thisSize = r[i]-l[i]+1;
            vector<int> thisArray(thisSize);
            if(thisSize<2)
            {
                result[i] = false;
                continue;
            }
            if(thisSize == 2)
            {
                result[i] = true;
                continue;
            }
            //Extracting Array
            int j = 0;
            for(int k = l[i]; k<=r[i]; k++)
            thisArray[j++] = nums[k];

            sort(thisArray.begin(), thisArray.end());
            int commonDifference = thisArray[1] - thisArray[0];
            for(int k = 0; k<thisSize-1; k++)
            {
                if(thisArray[k+1]-thisArray[k]!=commonDifference)
                {
                    result[i] = false;
                    continue;
                }
            }
        }
        return result;
    }
};