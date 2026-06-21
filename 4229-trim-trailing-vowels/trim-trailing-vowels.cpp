class Solution {
public:
    string trimTrailingVowels(string s) {
        while(true)
        {
            if(s.size() != 0 && (s[s.size()-1]=='a' || s[s.size()-1]=='e' || s[s.size()-1]=='i' || s[s.size()-1]=='o' || s[s.size()-1]=='u'))
            s.pop_back();

            else
            break;
        }
        return s;
    }
};