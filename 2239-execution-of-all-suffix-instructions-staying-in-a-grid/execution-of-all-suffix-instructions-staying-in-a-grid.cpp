class Solution {
public:
    void move(char m, int &x, int &y)
    {
        switch(m)
        {
            case 'L' : x--; break;
            case 'R' : x++; break;
            case 'D' : y++; break;
            case 'U' : y--; break;
        }
        return;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> result;
        for(int startingIndex = 0; startingIndex < s.size(); startingIndex++)
        {
            int x = startPos[1];
            int y = startPos[0];
            int i = startingIndex;
            int instructions = 0;

            while(x < n && y < n && x>=0 && y>=0 && i < s.size())
            {
                move(s[i], x, y);

                if(x >= n || y>=n || x<0 || y<0)
                break;

                instructions++;
                i++;
            }
            result.push_back(instructions);
        }
    return result;
    }
};