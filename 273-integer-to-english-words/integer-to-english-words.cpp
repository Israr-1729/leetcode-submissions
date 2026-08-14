class Solution {
public:

    string pivotingNumberToWords(int num)
    {
        switch (num)
        {
            case 0 : return "Zero"; break;
            case 1 : return "One"; break;
            case 2 : return "Two"; break;
            case 3 : return "Three"; break;
            case 4 : return "Four"; break;
            case 5 : return "Five"; break;
            case 6 : return "Six"; break;
            case 7 : return "Seven"; break;
            case 8 : return "Eight"; break;
            case 9 : return "Nine"; break; 
            case 10: return "Ten"; break;
            case 11: return "Eleven"; break;
            case 12: return "Twelve"; break;
            case 13: return "Thirteen"; break;
            case 14: return "Fourteen"; break;
            case 15: return "Fifteen"; break;
            case 16: return "Sixteen"; break;
            case 17: return "Seventeen"; break;
            case 18: return "Eighteen"; break;
            case 19: return "Nineteen"; break;
            case 20: return "Twenty"; break;
            case 30: return "Thirty"; break;
            case 40: return "Forty"; break;
            case 50: return "Fifty"; break;
            case 60: return "Sixty"; break;
            case 70: return "Seventy"; break;
            case 80: return "Eighty"; break;
            case 90: return "Ninety"; break;
            case 100: return "One Hundred"; break;
            case 1000: return "One Thousand"; break;
            case 1000000: return "One Million"; break;
            case 1000000000: return "One Billion"; break;
        }
        return "";
    }

    void cleaner(string &s)
    {
        while(s[s.size() - 1] == ' ')
        {
            s.pop_back();
        }
    }

    string threeDigitNumberToWords (int num)
    {
        string result = "";
        if(num/10 == 0)
        {
            result = pivotingNumberToWords(num) + " ";
        }

        else if(num/100 == 0)
        {
            if(num <= 20 || num%10 == 0)
            result = pivotingNumberToWords(num) + " ";

            else
            result = pivotingNumberToWords((num/10)*10) + " " + pivotingNumberToWords(num % 10) + " ";
        }

        else
        {
            if(num % 100 == 0)
            result = pivotingNumberToWords(num/100) + " Hundred ";

            else if(num % 100 != 0)
            result = pivotingNumberToWords(num/100) + " Hundred " + threeDigitNumberToWords(num%100) + " ";
        }

    cleaner(result);
    return result;
    }



    int numReverser(int i)
    {
        int result = 0;
        while(i)
        {
            result = result * 10 + i % 10;
            i/=10;
        }
        return result;
    }

vector<int> fillThreeDigitEach(int num)
{
    if(num == 0)
        return {0};

    vector<int> threeDigitEach;

    while(num > 0)
    {
        threeDigitEach.push_back(num % 1000);
        num /= 1000;
    }
    return threeDigitEach;
}

    string suffixMaker(int i)
    {
        if(i == 0)
        return "";

        if(i == 1)
        return "Thousand";

        if(i == 2)
        return "Million";

        if(i == 3)
        return "Billion";

        return "";
    }

    string resultMaker(const vector<int> &triplets)
    {
        if(triplets.size() == 1 && triplets[0] == 0)
        return "Zero";

        int currSuffix = triplets.size() - 1;
        string result = "";

        for(int i = triplets.size()-1; i >= 0; i--)
        {
            if(triplets[i] == 0)
            {
                currSuffix--;
                continue;
            }

            result += threeDigitNumberToWords(triplets[i]) + " " + suffixMaker(currSuffix) + " ";
            currSuffix--;
        }
        cleaner(result);
        return result;
    }

    string numberToWords(int num) {
        
        vector<int> triplets = fillThreeDigitEach(num);

        return resultMaker(triplets);
    }
};