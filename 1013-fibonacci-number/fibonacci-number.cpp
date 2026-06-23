class Solution {
public:
    int fib(int n) {
        if(n<2)
        return n;
        int arr[2] = {0,1};
        for(int i = 2; i<=n; i++)
        {
            int thisElement = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = thisElement;
        }
        return arr[1];
    }
};