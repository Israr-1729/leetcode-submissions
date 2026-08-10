class Solution {
public:
    int dig(char c) { return c - '0'; }

    vector<vector<int>> allDigitsIntoNum1(const string& num1) {
        vector<vector<int>> result;
        for (int i = 0; i <= 9; i++) {
            int carry = 0;
            vector<int> forThisI;
            for (int j = num1.size() - 1; j >= 0; j--) {
                forThisI.push_back((dig(num1[j]) * i + carry) % 10);
                carry = (dig(num1[j]) * i + carry) / 10;
            }

            if (carry != 0) {
                forThisI.push_back(carry);
            }

            result.push_back(forThisI);
        }
        return result;
    }

    string multiply(string num1, string num2) {
        vector<vector<int>> digitWiseProductOfNum1 = allDigitsIntoNum1(num1);

        vector<vector<int>> num1intonum2;
        int zeroesAtEnd = 0;

        for (int i = num2.size() - 1; i >= 0; i--) {
            int thisDigit = dig(num2[i]);

            vector<int> toAdd = digitWiseProductOfNum1[thisDigit];
            toAdd.insert(toAdd.begin(), zeroesAtEnd, 0);
            zeroesAtEnd++;
            num1intonum2.push_back(toAdd);
        }

        int largestSize = 0;

        for (auto& v : num1intonum2) {
            if (largestSize < v.size())
                largestSize = v.size();
        }

        int carry = 0;
        string result = "";
        for (int i = 0; i < largestSize; i++) {
            int sum = carry;
            for (auto& v : num1intonum2) {
                if (i < v.size())
                    sum += v[i];
            }

            result += (to_string(sum % 10));
            carry = sum / 10;
        }

        if (carry != 0) {
            string strCarry = to_string(carry);
            result += strCarry;
        }

        reverse(result.begin(), result.end());

        bool allZero = true;
        for (char c : result) {
            if (c != '0') {
                allZero = false;
                break;
            }
        }

        if (allZero)
            return "0";

        return result;
    }
};