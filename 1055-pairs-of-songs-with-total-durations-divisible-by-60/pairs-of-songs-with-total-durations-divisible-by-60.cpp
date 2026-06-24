class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>modulo(60);
        for(int a : time)
        {
            modulo[a%60]++;
        }

        long long sum = 0;
        for(int i = 1; i<30; i++)
        sum += modulo[i]*modulo[60-i];

        sum += 1LL*modulo[0]*(modulo[0]-1)/2;
        sum += 1LL*modulo[30]*(modulo[30]-1)/2;
        return sum;
        
    }
};