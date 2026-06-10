class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq (26);
        for(char c : text)
        {
            freq[c-'a']++;
        }

        int counter = 0;

        while(true)
        {
                freq['b'-'a']--;
                freq['a'-'a']--;
                freq['l'-'a']--;
                freq['l'-'a']--;
                freq['o'-'a']--;
                freq['o'-'a']--;
                freq['n'-'a']--;
            if(freq['b'-'a']>=0 &&freq['a'-'a']>=0 &&freq['l'-'a']>=0 &&freq['o'-'a']>=0 &&freq['n'-'a']>=0)
            {
                counter++;
            }
            else
            break;
        }
        return counter;
    }
};