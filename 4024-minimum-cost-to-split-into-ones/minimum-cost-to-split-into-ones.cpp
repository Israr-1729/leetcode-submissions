class Solution {
public:
    int minCost(int n) {

        long long a = n-1;
        long long b = n;

        long long c = a*b/2;
        return c;
        
    }
};