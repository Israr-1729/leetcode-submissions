class Solution {
public:


    int thisStrength(char c)
    {
        if(c>='a' && c<='z')
        return 1;

        if(c>='A' && c<='Z')
        return 2;

        if(c>='0' && c<='9')
        return 3;

        else
        return 5;
    }
    int passwordStrength(string password) {
        int strength = 0;
        int size = password.size();
        unordered_map<char, bool> appeared;

        for(int i = 0; i<size; i++)
        {
            char ch = password[i];
            if(!appeared[ch])
            {
                strength += thisStrength(ch);
                appeared[ch] = true;
            }
        }
        return strength;
    }
};