class Solution {
public:
    string binary(int n) {
        string s;

        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
    int minimumFlips(int n) {
        string b = binary(n);
        string r = b;
        reverse(r.begin(), r.end());
        int count = 0;
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i] != r[i])
            count++;
        }
        return count;
    }
};