class Solution {
public:
    vector<int> numerators(const string &expression)
    {
        vector<int> result;
        int i = 0;
        int size = expression.size();

        while(i < size)
        {
            if(i < size && expression[i] == '+' || expression[i] == '-')
            {
                int copy = i;
                int lengthTillSlash = 0;
                while(copy < size && expression[copy] != '/')
                {
                    lengthTillSlash++;
                    copy++;
                }

                result.push_back(stoi(expression.substr(i, lengthTillSlash)));
                i = copy;
                i++;
            }
            i++;
        }
        return result;
    }

    vector<int> denominators(const string &expression)
    {
        vector<int> result;
        int i = 0;
        int size = expression.size();

        while(i < size)
        {
            if(expression[i] == '/')
            {
                int copy = i+1;
                int lengthTillNonDigit = 0;
                while(copy < size && isdigit(expression[copy]))
                {
                    lengthTillNonDigit++;
                    copy++;
                }
                result.push_back(stoi(expression.substr(i+1, lengthTillNonDigit)));
                i = copy;
                i++;
            }
            i++;
        }
        return result;
    }
    string fractionAddition(string expression) {
        if(isdigit(expression[0]))
        {
            reverse(expression.begin(), expression.end());
            expression.push_back('+');
            reverse(expression.begin(), expression.end());
        }

        vector<int> nums = numerators(expression);
        vector<int> dems = denominators(expression);

        long long LCM = 1;

        for(int i : dems)
        {
            LCM = lcm(LCM, i);
        }

        int idx = 0;
        long long numSum = 0;
        for(int &i : nums)
        {
            numSum +=  i * (LCM/dems[idx++]);
        }

        if(numSum == 0)
        return "0/1";

        int GCD = gcd(abs(numSum), LCM);
        numSum/= GCD;
        LCM/=GCD;

            string ans = "";
            ans += to_string(numSum);
            ans += '/';
            ans += to_string(LCM);
            return ans;
        
    }
};