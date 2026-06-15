class Solution {
public:
    int minOperations(int n) {
            int first = n-1;
            int sum = 0;
            while(first>0)
            {
                sum += first;
                first = first-2;
            } 
        return sum;
    }
};