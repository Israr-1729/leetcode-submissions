class Solution {
public:


    int isWavy(int i)
    {
        if(i<3)
        return false;
        string num = to_string(i);
        int size = num.size();
        int peak = 0; int valley = 0;
        for(int i = 1; i<size-1; i++)
        {
            if(num[i]>num[i-1] && num[i]>num[i+1])
            peak++;
            else if(num[i]<num[i-1] && num[i]<num[i+1])
            valley++;
        }
        return peak + valley;
    }
    int totalWaviness(int num1, int num2) {
        int wavies = 0;
        for(int i = num1; i<=num2; i++)
        {
            wavies += isWavy(i);
        }
        return wavies;
    }
};