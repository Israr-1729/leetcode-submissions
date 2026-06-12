class Solution {
public:
    string sortVowels(string s) {
        int size = s.size();

        int numVowel = 0;
        for(char c : s)
        {
            if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            numVowel++;
        }

        vector<char> vowelOnly(numVowel);
        int idx = 0;
        for(int i = 0; i<size; i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            vowelOnly[idx++] = s[i];
        }

        sort(vowelOnly.begin(), vowelOnly.end());
        idx = 0;

        for(int i = 0; i<size; i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            s[i] = vowelOnly[idx++];
        }
        return s;
    }
};