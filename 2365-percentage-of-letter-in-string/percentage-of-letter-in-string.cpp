class Solution {
public:
    int percentageLetter(string s, char letter) {
        int charCount = 0;
        for(char c : s)
        {
            if(c == letter)
            charCount++;
        }

        double percentage = (double)charCount/s.size();
        return (int) (percentage * 100);
        
    }
};