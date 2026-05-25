class Solution {
public:

//Basic Idea is that if a smaller valued character is before a larger valued character, we subtract. Else, we add.

int value(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000; // M
    }


    int romanToInt(string s) {
        int size = s.size();
        int ans = 0;
        for(int i = 0; i<size-1; i++)
        {
            if(value(s[i])<value(s[i+1]))
            ans-=value(s[i]);
            else
            ans+=value(s[i]);
        }
        ans+=value(s[size-1]);
        return ans;
    }
};