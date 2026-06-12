class Solution {
public:
    string sortVowels(string s) {
        int size = s.size();
        vector<char> vowelOnly;
        for(int i = 0; i<size; i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            vowelOnly.push_back(s[i]);
        }

        sort(vowelOnly.begin(), vowelOnly.end());
        int idx = 0;

        for(int i = 0; i<size; i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            s[i] = vowelOnly[idx++];
        }
        return s;
    }
};