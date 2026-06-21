class Solution {
public:
    int maxDistance(string moves) {
        vector<int> frq(4);
        for(char c : moves)
        {
            if(c=='U')
                frq[0]++;
            if(c=='D')
                frq[1]++;
            if(c=='L')
                frq[2]++;
            if(c=='R')
                frq[3]++;
        }
        int highestIndex;
        int maxfrq=INT_MIN;
        for(int i = 0; i<4; i++)
        {
            if(frq[i]>maxfrq)
            {
                highestIndex = i;
                maxfrq = frq[i];
            }
        }
        char highest;
        if(highestIndex==0)
            highest = 'U';
        if(highestIndex==1)
            highest = 'D';
        if(highestIndex==2)
            highest = 'L';
        if(highestIndex==3)
            highest = 'R';

        int l = 0; int u = 0;
        int r = 0; int d = 0;

        int xAxis = 0; int yAxis = 0;

        for(char c : moves)
        {
            if(c=='U' || (c=='_' && highest == 'U'))
                yAxis++;
            if(c=='D' || (c=='_' && highest == 'D'))
                yAxis--;
            if(c=='L' || (c=='_' && highest == 'L'))
                xAxis--;
            if(c=='R' || (c=='_' && highest == 'R'))
                xAxis++;
            
        }
        return abs(xAxis) + abs(yAxis);
    }
};