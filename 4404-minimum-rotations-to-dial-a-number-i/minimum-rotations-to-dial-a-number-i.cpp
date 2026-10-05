class Solution {
public:
    int minRotations(string s) {
        s.insert(0, 1,'0');
        int total = 0;
        for(int i = 0; i < s.size()-1; i++)
        {
            int from = s[i] - '0';
            int to = s[i+1] - '0';

            int cw = 0; 
            int acw = 0;

            if(to > from)
            {
                cw = to-from;
                acw = from + (10 - to);
            }

            else if(to < from)
            {
                cw = (0, from - to);
                acw = (10-from) + to;
            }

            else
            {
                cw = 0; acw = 0;
            }
        cout<<min(cw, acw)<<"\n";
        total += min(cw, acw);
        }
        return total;
    }
};