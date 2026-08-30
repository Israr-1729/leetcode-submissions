class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        string result = "";
        int i = 0;

        while(i < a.size() || i < b.size() || carry != 0)
        {
            int sum = 0;

            if(i < a.size())
            {
                sum += a[i] - '0';
            }

            if(i < b.size())
            {
                sum += b[i] - '0';
            }

            sum += carry;

            result += (sum%2 + '0');
            carry = sum/2;
            i++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};