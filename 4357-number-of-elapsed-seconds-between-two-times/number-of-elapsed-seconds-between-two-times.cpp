class Solution {
public:

    vector<int> seperator (string s)
    {
        int i = 0;
        int h = 0;

        while(s[i] != ':')
        {
            h = h*10 + (s[i]-'0');
            i++;
        }
        i++;

        int m = 0;
        while(s[i] != ':')
        {
            m = m*10 + (s[i]-'0');
            i++;
        }
        i++;

        int seconds = 0;
        while(i<s.size())
        {
            seconds = seconds*10 + (s[i]-'0');
            i++;
        }

        return {h, m, seconds};
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        vector<int> start = seperator(startTime);
        vector<int> end = seperator(endTime);

        return (end[0]-start[0])*3600 + (end[1]-start[1])*60 + (end[2]-start[2]);
        
    }
};