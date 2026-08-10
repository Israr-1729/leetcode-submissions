class Solution {
public:

    pair<int, int> number(string num1)
    {
        pair<int, int> result;
        result.first = 0; result.second = 0;
        int i = 0;
        int size = num1.size();
        bool firstFound = false;

        while(i < size)
        {
            if(!isdigit(num1[i]))
            {
                i++;
                continue;
            }

            if(i < size && isdigit(num1[i]))
            {
                int num = 0;
                bool isNegative = (i>0 && num1[i-1] == '-') ? true : false;
                while(i < size && isdigit(num1[i]))
                {
                    num = num * 10 + (num1[i] - '0');
                    i++;
                }

                if(isNegative)
                num *= -1;

                if(!firstFound)
                {
                    firstFound = true;
                    result.first = num;
                }

                else
                {
                    result.second = num;
                }
            }
        }
    return result;
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> copy1 = number(num1);
        pair<int, int> copy2 = number(num2);

        return (to_string(copy1.first * copy2.first - copy1.second * copy2.second) + "+" + to_string(copy1.first*copy2.second + copy2.first*copy1.second) + "i"); 
        
    }
};