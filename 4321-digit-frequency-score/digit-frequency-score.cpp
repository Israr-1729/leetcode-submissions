class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> frq(10);
        while(n!=0)
        {
            frq[n%10]++;
            n/=10;
        }
        int answer = 0;
        for(int i = 0; i<10; i++)
        {
            answer += i * frq[i];
        }
        return answer;
    }
};