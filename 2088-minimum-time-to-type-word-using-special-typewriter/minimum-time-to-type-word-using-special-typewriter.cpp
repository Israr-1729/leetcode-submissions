class Solution {
public:
    int minTimeToType(string word) {
        int currChar = 'a';
        int timeTaken = 0;
        for(char c : word)
        {
            timeTaken += min(abs(c-currChar), 26-abs(c-currChar));
            //cout<<min(abs(c-currChar), 26-abs(c-currChar))<<"\n";
            timeTaken++;
            currChar = c;
        }
        return timeTaken;
    }
};