class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();

        int i = size1 - 1;
        int j = size2 - 1;
        int carry = 0;
        string result = "";

        while(i>=0 || j>=0)
        {
            int sum = carry;

            if(i>=0)
            {
                sum += num1[i] - '0';
                i--;
            }

            if(j>=0)
            {
                sum += num2[j] - '0';
                j--;
            }

            carry = sum/10;
            result.push_back((sum%10)+'0');
        }
        if(carry != 0)
        result.push_back((carry)+'0');
        reverse(result.begin(), result.end());
        return result;
    }
};