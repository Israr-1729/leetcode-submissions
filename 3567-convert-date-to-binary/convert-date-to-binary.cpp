class Solution {
public:

string toBinary(const string &s) {
    int n = stoi(s);

    if (n == 0)
        return "0";

    string ans;

    while (n > 0) {
        ans += (n % 2) + '0';
        n /= 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

    string convertDateToBinary(string date) {
        int firstDash = -1;
        int secondDash = -1;

        for(int i = 0; i < date.size(); i++)
        {
            if(date[i] == '-')
            {
                if(firstDash == -1)
                firstDash = i;

                else
                secondDash = i;
            }
        }

        string year = date.substr(0, firstDash);
        string month =  date.substr(firstDash + 1, 2);
        string day = date.substr(secondDash + 1, 2);


        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
        
    }
};