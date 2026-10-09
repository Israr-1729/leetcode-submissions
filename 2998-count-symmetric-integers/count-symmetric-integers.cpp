class Solution {
public:
    bool isSymmetric(int n)
    {
        vector<int> digits;
        while(n)
        {
            digits.push_back(n%10);
            n/=10;
        }

        if(digits.size() == 1 || digits.size() == 3 || digits.size() == 5)
        {
            return false;
        }

        else
        {
            if(digits.size() == 2)
            return digits[0] == digits[1];

            else
            return digits[0] + digits[1] == digits[2] + digits[3];
        }

        return false;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++)
        {
            if(isSymmetric(i))
            count++;
        }
        return count;
    }
};