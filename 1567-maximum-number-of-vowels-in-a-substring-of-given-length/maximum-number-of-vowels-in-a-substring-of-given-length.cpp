class Solution {
public:

    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
        return false;
    }

    int maxVowels(string s, int k) {
        
        int currVowels = 0;
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]))
            currVowels++;
        }
        int maxVowels = currVowels;

        for(int i = 1; i + k <= s.size(); i++)
        {
            if(isVowel(s[i-1]))
            currVowels--;

            if(isVowel(s[i+k-1]))
            currVowels++;

            if(maxVowels < currVowels)
            {
                maxVowels = currVowels;
            }


        }
        return maxVowels;
        
    }
};