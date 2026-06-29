class Solution {
public:
    bool doesAliceWin(string s) {
        int numOfVowels = 0;
        for(char c : s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            numOfVowels++;
        }
        if(numOfVowels>0)
        return true;
        return false;
    }
};